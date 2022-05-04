#include "Store.hpp"
#include "Product.hpp"
#include "User.hpp"

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

/**
  Store constructor (never used outside of singleton)
*/
Store::Store() {
    users_size_ = 0;
    listings_size_ = 0;
}

/**
  Loads two csv files, users.csv and products.csv.
  Inputs the data from these files into the store history.

  @param file_users Users csv file name
  @param file_inventory Products csv file name
*/
void Store::LoadFromFile(string file_users, string file_inventory) {
    //BEGIN USERS
    ifstream users_in;
    users_in.open(file_users);
    vector<string> storage;
    string currentLine;

    while (getline(users_in, currentLine)) {
        string curr;
        istringstream split(currentLine);
        while (getline(split,curr, ',')) {
            storage.push_back(curr);
        }
        if (storage[3][0] == 'b') {
            Buyer *tempBuyer = new Buyer(storage[0], stol(storage[1]), storage[2]);
            AddUser(tempBuyer);
        }else if (storage[3][0] == 's') {
            Seller *tempSeller = new Seller(storage[0], stol(storage[1]), storage[2], storage[4] == "ship");
            AddUser(tempSeller);
        }
        storage.clear();
    }

    //BEGIN INVENTORY
    ifstream products_in;
    products_in.open(file_inventory);

    while (getline(products_in, currentLine)) {
        string curr;
        istringstream split(currentLine);
        while (getline(split,curr, ',')) {
            storage.push_back(curr);
        }

        User *to_add;

        for (User *search : users_) {
            if (search -> get_username() == storage[3]) {
                to_add = search;
                break;
            }
        }

        //Handle all the case options
        if (storage[4].find("Paperback") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetBookPaperback(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Hardcover") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetBookHardcover(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Digital") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetBookDigital(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Vinyl") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetMusicVinyl(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("CD") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetMusicCD(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("MP3") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetMusicMP3(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("TV") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetElectronicTV(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Computer") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetElectronicComputer(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Phone") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetElectronicPhone(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Painting") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetArtPainting(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Photo") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetArtPhoto(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Sculpture") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetArtSculpture(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Shirt") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetClothingShirt(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Pants") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetClothingPants(storage[0], storage[1], stod(storage[2])));
        } else if (storage[4].find("Shoes") != string::npos) {
            ((Seller*)to_add) -> SellProduct(ProductFactory::GetClothingShoes(storage[0], storage[1], stod(storage[2])));
        }
        storage.clear();
    }
}

/**
  Handles the entire menu screen for the program
*/
void Store::PrintMenu() {
    int main_menu_selection;
    while (true) {
        cout << "Please Make A Selection:" << endl;
        cout << "1: Register or Login as Seller" << endl;
        cout << "2: Register or Login as Buyer" << endl;
        cout << "0: Exit" << endl;
        cin >> main_menu_selection;
        cout << "\n" << endl;
        int sub_menu_selection;
        bool exit;
        string user_entry_username;
        long user_entry_phonenumber;
        string user_entry_address;
        int user_entry_delivery;
        switch (main_menu_selection) {
            //if SELLER
            case 1: {
                cout << "Please Enter Your Username:" << endl;
                cin >> user_entry_username;

                
                Seller * new_seller;
                bool found = false;
                for (User *curr : users_) {
                    if (curr->get_username() == user_entry_username) {
                        found = true;
                        new_seller = (Seller *) curr;
                    }
                }
                if (!found) {
                    cout << "Please Enter Your Phone Number:" << endl;
                    cin >> user_entry_phonenumber;

                    cout << "Please Enter Your Address:" << endl;
                    cin.ignore();
                    getline(cin, user_entry_address);
                    

                    cout << "Please enter 1 if you would like to ship your product (flat $5 fee for buyer),\nor enter 2 if you would like your buyer to pick it up:" << endl;
                    cin >> user_entry_delivery;



                    new_seller = new Seller(user_entry_username, user_entry_phonenumber, user_entry_address, user_entry_delivery == 1);
                    users_.push_back(new_seller);
                }
                exit = false;
                while (!exit) {
                    cout << "Please Make A Selection:" << endl;
                    cout << "1: Post New Product For Sale" << endl;
                    cout << "2: View or Send Messages" << endl;
                    cout << "3: View User Information, Balance, and Rating" << endl;
                    cout << "4: Rate Buyer" << endl;
                    cout << "5: Update User Information" << endl;
                    cout << "6: View Product Status" << endl;
                    cout << "7: Open/Close Bidding" << endl;
                    cout << "0: Log Out" << endl;
                    cin >> sub_menu_selection;
                    cout << "\n" << endl;
                    switch (sub_menu_selection) {
                        //POST NEW PRODUCT FOR SALE
                        case 1: {
                            int sub_sub_menu_selection;
                            cout << "What kind of Product Would You Like To Sell?" << endl;
                            cout << "1: Paperback Book\n2: Hardcover Book\n3: Digital Book" << endl;
                            cout << "4: Vinyl\n5: CD\n6: MP3" << endl;
                            cout << "7: TV\n8: Computer\n9: Phone" << endl;
                            cout << "10: Painting\n11: Photo\n12: Sculpture" << endl;
                            cout << "13: Shirt\n14: Pants\n15: Shoes" << endl;
                            cin >> sub_sub_menu_selection;
                            string new_name, new_condition;
                            double new_price;
                            cout << "Please Enter A Name For The Item:" << endl;
                            cin.ignore();
                            getline(cin, new_name);
                            if (sub_sub_menu_selection != 11 && sub_sub_menu_selection != 6 && sub_sub_menu_selection != 3) {
                                cout << "Please Enter A Condition For The Item:" << endl;
                                cin >> new_condition;
                            }
                            cout << "Please Enter A Price For The Item:" << endl;
                            cin >> new_price;
                            switch (sub_sub_menu_selection) {
                                case 1:
                                    new_seller -> SellProduct(ProductFactory::GetBookPaperback(new_name, new_condition, new_price));
                                    break;
                                case 2:
                                    new_seller -> SellProduct(ProductFactory::GetBookHardcover(new_name, new_condition, new_price));
                                    break;
                                case 3:
                                    new_seller -> SellProduct(ProductFactory::GetBookDigital(new_name, "digital", new_price));
                                    break;
                                case 4:
                                    new_seller -> SellProduct(ProductFactory::GetMusicVinyl(new_name, new_condition, new_price));
                                    break;
                                case 5:
                                    new_seller -> SellProduct(ProductFactory::GetMusicCD(new_name, new_condition, new_price));
                                    break;
                                case 6:
                                    new_seller -> SellProduct(ProductFactory::GetMusicMP3(new_name, "digital", new_price));
                                    break;
                                case 7:
                                    new_seller -> SellProduct(ProductFactory::GetElectronicTV(new_name, new_condition, new_price));
                                    break;
                                case 8:
                                    new_seller -> SellProduct(ProductFactory::GetElectronicComputer(new_name, new_condition, new_price));
                                    break;
                                case 9:
                                    new_seller -> SellProduct(ProductFactory::GetElectronicPhone(new_name, new_condition, new_price));
                                    break;
                                case 10:
                                    new_seller -> SellProduct(ProductFactory::GetArtPainting(new_name, new_condition, new_price));
                                    break;
                                case 11:
                                    new_seller -> SellProduct(ProductFactory::GetArtPhoto(new_name, "digital", new_price));
                                    break;
                                case 12:
                                    new_seller -> SellProduct(ProductFactory::GetArtSculpture(new_name, new_condition, new_price));
                                    break;
                                case 13:
                                    new_seller -> SellProduct(ProductFactory::GetClothingShirt(new_name, new_condition, new_price));
                                    break;
                                case 14:
                                    new_seller -> SellProduct(ProductFactory::GetClothingPants(new_name, new_condition, new_price));
                                    break;
                                case 15:
                                    new_seller -> SellProduct(ProductFactory::GetClothingShoes(new_name, new_condition, new_price));
                                    break;
                            }
                            break;
                        }
                        //SEND MESSAGES BETWEEN USERS
                        case 2: {
                            bool exit_submenu = false;
                            while (!exit_submenu) {
                                int sub_sub_menu_selection;
                                cout << "What would you like to do?" << endl;
                                cout << "1: View New Messages" << endl;
                                cout << "2: View All (historical) Messages" << endl;
                                cout << "3: Send New Message" << endl;
                                cout << "0: Return To Main Menu" << endl;
                                cin >> sub_sub_menu_selection;

                                switch (sub_sub_menu_selection) {
                                    case 1: 
                                        for (int x = 0; x < new_seller->get_new_messages().size(); x++) {
                                            cout << "Message " << x+1 << ": " << new_seller->get_new_messages().at(x)->sender->get_username() << ": " << new_seller->get_new_messages().at(x)->text << "\n" << endl;
                                        }
                                        if (new_seller->get_new_messages().size() == 0) {
                                            cout << "No New Messages\n" << endl;
                                        }
                                        new_seller->clear_messages();
                                        break;
                                    case 2: {
                                        for (int x = 0; x < new_seller->get_messages().size(); x++) {
                                            cout << "Message " << x+1 << ": " << new_seller->get_messages().at(x)->sender->get_username() << ": " << new_seller->get_messages().at(x)->text << "\n" << endl;
                                        }
                                        if (new_seller->get_messages().size() == 0) {
                                            cout << "No Messages\n" << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        string recipient;
                                        cout << "Enter Recipient's Username" << endl;
                                        cin.ignore();
                                        bool found = false;
                                        getline(cin, recipient);
                                        for (User *current : new_seller->get_can_message()) {
                                            if (current->get_username() == recipient) {
                                                found = true;
                                                cout << "Enter Message To Send" << endl;
                                                string message;
                                                getline(cin, message);
                                                new_seller->SendMessage(current, message);
                                                cout << "Message Sent!" << endl;
                                                break;
                                            }
                                        }
                                        if (!found){
                                            cout << "Recipient Not Found, Or You Cannot Message This User"<< endl;
                                        }
                                        break;
                                    }
                                    case 0:
                                        exit_submenu = true;
                                        break;
                                }
                            }
                            break;
                        }
                        //View User Information, Balance, and Rating
                        case 3:
                            cout << "---------------------------" << endl;
                            cout << "User Information (" << new_seller->get_username() << ")" << endl;
                            cout << "Phone Number: " << new_seller->get_phone_number() << endl;
                            cout << "Address: " << new_seller->get_address() << endl;
                            cout << "Balance: " << new_seller->get_account_balance() << endl;
                            cout << "Rating: " << (new_seller->get_num_ratings() == 0 ? "Not yet rated" : to_string(new_seller->get_rating())) << endl;
                            cout << "---------------------------" << endl;
                            break;
                        //RATE BUYER
                        case 4: {
                            string recipient;
                            cout << "Enter Buyer's Username" << endl;
                            cin.ignore();
                            bool found = false;
                            getline(cin, recipient);
                            for (User *current : new_seller->get_can_message()) {
                                if (current->get_username() == recipient) {
                                    found = true;
                                    cout << "Enter Rating (1-10)" << endl;
                                    int rating;
                                    cin >> rating;
                                    new_seller->RateUser(*current, rating);
                                    cout << "Rating Added!" << endl;
                                    break;
                                }
                            }
                            if (!found){
                                cout << "Buyer Not Found, Or You Cannot Rate This User"<< endl;
                            }
                            break;
                        }
                        //Update User's Information
                        case 5: {
                            string user_update_username;
                            long user_update_phonenumber;
                            string user_update_address;
                            cout << "Please Enter A New Username:" << endl;
                            cin >> user_update_username;
                            
                            cout << "Please Enter A New Phone Number:" << endl;
                            cin >> user_update_phonenumber;

                            cout << "Please Enter A New Address:" << endl;
                            cin.ignore();
                            getline(cin, user_update_address);
                                
                            new_seller->UpdateUser(user_update_username, user_update_phonenumber, user_update_address);
                            break;
                        }
                        //View Product Status  
                        case 6: {
                            int counter = 0;
                            new_seller->ShowProducts(true, true, counter);
                            break;
                        }
                        //Open/Close Bidding, and handle product being sold.
                        case 7: {
                            int counter = 0;
                            new_seller->ShowProducts(true, true, counter);
                            cout << "Which product would you like to modify? (enter number)" << endl;
                            int selection;
                            cin >> selection;
                            Product* to_modify = new_seller->get_seller_products()[selection-1];
                                if (to_modify->get_is_sold()) {
                                    cout << "There is nothing that can be modified on this product." << endl;
                                } else if (to_modify->get_is_bidded()) {
                                    cout << "Modifying this item will end it's bidding.\nIf there are bids, the item will be sold to the highest bidder. Otherwise bids will be closed.\nIf you would like to continue, type 'Y' otherwise type 'N'" << endl;
                                    char cont;
                                    cin >> cont;
                                    if (cont == 'Y' || cont == 'y') {
                                        //End product
                                        vector<User*> bidding_users = to_modify->get_bidding_users();
                                        vector<double> bidding_amount = to_modify->get_bidding_amount();
                                        int shipping_cost;
                                        if (new_seller->get_ship()) {
                                            shipping_cost = 5;
                                        } else {
                                            shipping_cost = 0;
                                        }
                                        string winner = "No One";
                                        for (int x = bidding_users.size()-1; x >= 0; x--) {
                                            Buyer* current_user = (Buyer *) bidding_users.at(x);
                                            if (current_user->get_account_balance() >= (bidding_amount.at(x) + shipping_cost)) {
                                                //winner
                                                winner = current_user->get_username();
                                                cout << winner << " won " << to_modify->get_name() << " for $" <<  bidding_amount.at(x) << endl;
                                                current_user->SetAccountBalance(current_user->get_account_balance() - (bidding_amount.at(x) + shipping_cost));
                                                new_seller->SetAccountBalance(new_seller->get_account_balance() + (bidding_amount.at(x) + shipping_cost));
                                                current_user->add_can_message(new_seller);
                                                new_seller->add_can_message(current_user);
                                                current_user->add_to_history(to_modify);
                                                to_modify->SetIsSold(true);
                                                current_user->SendMessage(new_seller, "You have won the bid on " + to_modify->get_name() + "!!");
                                                if (!new_seller ->get_ship()) {
                                                    to_modify->SetPickup(new_seller->get_address());
                                                } else {
                                                    cout << "Please send product to: " << endl;
                                                    cout << current_user->get_username()<< " at " << current_user->get_address() << endl;
                                                }
                                                break;
                                            }
                                        }
                                        if (winner == "No One") {
                                            cout << "No one won the auction." << endl;
                                            to_modify->SetIsBidded(false);
                                        }
                                    }
                                } else {
                                    cout << "Your " << to_modify->get_name() << " has been opened for bids." << endl;
                                    to_modify->SetIsBidded(true);
                                }
                            break;
                        }
                            
                        case 0:
                            exit = true;
                            break;
                    };
                }
                break;
            }
            //if BUYER
            case 2: {
                cout << "Please Enter Your Username:" << endl;
                cin >> user_entry_username;
                
                Buyer * new_buyer;
                bool found = false;
                for (User *curr : users_) {
                    if (curr->get_username() == user_entry_username) {
                        found = true;
                        new_buyer = (Buyer *) curr;
                    }
                }
                if (!found) {
                    cout << "Please Enter Your Phone Number:" << endl;
                    cin >> user_entry_phonenumber;

                    cout << "Please Enter Your Address:" << endl;
                    cin.ignore();
                    getline(cin, user_entry_address);
                    new_buyer = new Buyer(user_entry_username, user_entry_phonenumber, user_entry_address);
                    users_.push_back(new_buyer);
                }

                



                exit = false;
                while (!exit) {
                    cout << "Please Make A Selection:" << endl;
                    cout << "1: View Products For Sale" << endl;
                    cout << "2: Place Bid On Product" << endl;
                    cout << "3: View or Send Messages" << endl;
                    cout << "4: View User Information, Balance, and Rating" << endl;
                    cout << "5: Rate Seller" << endl;
                    cout << "6: Update User Information" << endl;
                    cout << "7: View Placed Bids" << endl;
                    cout << "8: View Order History" << endl;
                    cout << "0: Log Out" << endl;
                    cin >> sub_menu_selection;
                    cout << "\n" << endl;
                    switch (sub_menu_selection) {
                        //View Products for sale
                        case 1: {
                            cout << "Products For Sale:\n---------------------------" << endl;
                            int counter = 0;
                            for (User* curr : get_users()) {
                                if (curr->get_type() == "seller") {
                                    Seller* temp = (Seller*) curr;
                                    temp->ShowProducts(true, false, counter);
                                }
                            }
                            break;
                        }
                        //Place Bid on Product
                        case 2: {
                            cout << "Products For Sale:\n---------------------------" << endl;
                            int counter = 0;
                            for (User* curr : get_users()) {
                                if (curr->get_type() == "seller") {
                                    Seller* temp = (Seller*) curr;
                                    temp->ShowProducts(true, false, counter);
                                }
                            }
                            cout << "\n\nWhich product would you like to bid on? (enter product number)" << endl;
                            int product_num;
                            cin >> product_num;
                            Product * found_product = NULL;
                            //Seller* found_product_seller;
                            counter = 0;
                            for (User* curr : get_users()) {
                                if (curr->get_type() == "seller") {
                                    Seller* current_seller = (Seller*) curr;
                                    for (Product * current_product : current_seller->get_seller_products()) {
                                        if (current_product->get_is_sold() == false) {
                                            if (product_num-1 == counter) {
                                                found_product = current_product;
                                                //found_product_seller = current_seller;
                                                break;
                                            }
                                            counter++;
                                        }
                                    }
                                }
                            }
                            //We now have the item and the seller, place a bid.
                            if (found_product != NULL && found_product->get_is_bidded()) {
                                cout << "Placing Bid on: "<< found_product->get_name() << endl;
                                double curr_high_bid = found_product->get_highest_bid();
                                cout << "The current high bid is: $" << curr_high_bid << "\n" << endl; 
                                double new_bid;
                                bool valid_entry = false;
                                while (!valid_entry) {
                                    cout << "How much would you like to bid?" << endl;
                                    cin >> new_bid;
                                    if (new_bid <= curr_high_bid) {
                                        cout << "Bid Not High Enough." << endl;
                                    } else {
                                        cout << "Bid Placed!" << endl;
                                        new_buyer->PlaceBid(found_product, new_bid);
                                        valid_entry = true;
                                    }
                                }
                            } else if (found_product != NULL && !found_product->get_is_bidded()) {
                                cout << found_product->get_name() << endl;
                                cout << "Item found, bidding is not currently open" << endl;
                            } else {
                                cout << "Item Not Found" << endl;
                            }
                            
                            break;
                        }
                        //View or Send Messages
                        case 3: {
                            bool exit_submenu = false;
                            while (!exit_submenu) {
                                int sub_sub_menu_selection;
                                cout << "What would you like to do?" << endl;
                                cout << "1: View New Messages" << endl;
                                cout << "2: View All (historical) Messages" << endl;
                                cout << "3: Send New Message" << endl;
                                cout << "0: Return To Main Menu" << endl;
                                cin >> sub_sub_menu_selection;

                                switch (sub_sub_menu_selection) {
                                    case 1: 
                                        for (int x = 0; x < new_buyer->get_new_messages().size(); x++) {
                                            cout << "Message " << x+1 << ": " << new_buyer->get_new_messages().at(x)->sender->get_username() << ": " << new_buyer->get_new_messages().at(x)->text << "\n" << endl;
                                        }
                                        if (new_buyer->get_new_messages().size() == 0) {
                                            cout << "No New Messages\n" << endl;
                                        }
                                        new_buyer->clear_messages();
                                        break;
                                    case 2: {
                                        for (int x = 0; x < new_buyer->get_messages().size(); x++) {
                                            cout << "Message " << x+1 << ": " << new_buyer->get_messages().at(x)->sender->get_username() << ": " << new_buyer->get_messages().at(x)->text << "\n" << endl;
                                        }
                                        if (new_buyer->get_messages().size() == 0) {
                                            cout << "No Messages\n" << endl;
                                        }
                                        break;
                                    }
                                    case 3: {
                                        string recipient;
                                        cout << "Enter Recipient's Username" << endl;
                                        cin.ignore();
                                        bool found = false;
                                        getline(cin, recipient);
                                        for (User *current : new_buyer->get_can_message()) {
                                            if (current->get_username() == recipient) {
                                                found = true;
                                                cout << "Enter Message To Send" << endl;
                                                string message;
                                                getline(cin, message);
                                                new_buyer->SendMessage(current, message);
                                                cout << "Message Sent!" << endl;
                                                break;
                                            }
                                        }
                                        if (!found){
                                            cout << "Recipient Not Found, Or You Cannot Message This User"<< endl;
                                        }
                                        break;
                                    }
                                    case 0:
                                        exit_submenu = true;
                                        break;
                                }
                            }
                            break;
                        }
                        //View user info, balance, and rating
                        case 4:
                            cout << "---------------------------" << endl;
                            cout << "User Information (" << new_buyer->get_username() << ")" << endl;
                            cout << "Phone Number: " << new_buyer->get_phone_number() << endl;
                            cout << "Address: " << new_buyer->get_address() << endl;
                            cout << "Balance: " << new_buyer->get_account_balance() << endl;
                            cout << "Rating: " << (new_buyer->get_num_ratings() == 0 ? "Not yet rated" : to_string(new_buyer->get_rating())) << endl;
                            cout << "---------------------------" << endl;
                            break;
                        //Rate Seller
                        case 5: {
                            string recipient;
                            cout << "Enter Seller's Username" << endl;
                            cin.ignore();
                            bool found = false;
                            getline(cin, recipient);
                            for (User *current : new_buyer->get_can_message()) {
                                if (current->get_username() == recipient) {
                                    found = true;
                                    cout << "Enter Rating (1-10)" << endl;
                                    int rating;
                                    cin >> rating;
                                    new_buyer->RateUser(*current, rating);
                                    cout << "Rating Added!" << endl;
                                    break;
                                }
                            }
                            if (!found){
                                cout << "Seller Not Found, Or You Cannot Rate This User"<< endl;
                            }
                            break;
                        }
                        //Update User Info
                        case 6: {
                            string user_update_username;
                            long user_update_phonenumber;
                            string user_update_address;
                            cout << "Please Enter A New Username:" << endl;
                            cin >> user_update_username;
                            
                            cout << "Please Enter A New Phone Number:" << endl;
                            cin >> user_update_phonenumber;

                            cout << "Please Enter A New Address:" << endl;
                            cin.ignore();
                            getline(cin, user_update_address);
                                
                            new_buyer->UpdateUser(user_update_username, user_update_phonenumber, user_update_address);
                            break;
                        }
                        //View Placed Bids
                        case 7:
                            for (int x = 0; x < new_buyer->get_bids().size(); x++) {
                                cout << "You bid $" << new_buyer->get_bid_amounts().at(x) << " for " << new_buyer->get_bids().at(x)->get_name() << endl;
                            }
                            break;
                        //View Order History
                        case 8:
                            for (Product * curr : new_buyer->get_purchase_history()) {
                                cout << "You bought " << curr->get_name() << " for $" << curr->get_highest_bid();
                                if (curr->get_pickup()) {
                                    cout << " and need to go to '" << curr->get_pickup_address() << "' to pick it up from the seller";
                                }
                                cout << endl;
                            }
                            break;
                        case 0:
                            exit = true;
                            break;
                    };
                }
                break;
            }
            //EXIT
            case 0:
                return;
        };
    }
}

/**
  Adds a user to the store's user vector

  @param user User to add to the user vector
*/
void Store::AddUser(User *user) {
    users_.push_back(user);
    users_size_++;
}
