/**
Jaryd Meek, Richard Roberson
HW 3
This program simulates an E-bay type store. more instructions are below!
*/

#include "User.hpp"
#include "Store.hpp"
#include "Product.hpp"

#include <iostream>

using namespace std;

int main() {
    //HOW TO:

    //Compile code: 'make run'
    //Run Code: './main'


    //It starts with a menu to register or login as a buyer or seller.
    //If you enter a username not already in the database, it'll create a new user, if you enter an existing username, it'll log you in as that user.

    //Most of the logic happens in the classes, this file just gets the singleton store object, loads the files for initialization, and starts the menu!

    Store &store = Store::get_instance();

    store.LoadFromFile("users.csv", "products.csv");

    store.PrintMenu();


    //The files below are for testing basic functions. they're not needed, but nice to have in case :)

    /*
    Store &store = Store::get_instance();
    
    Buyer buyer("buyer123", 5612673440, "123 Generic Rd., Boulder, CO 80303");
    Seller seller("seller567", 4447889999, "567 Placeholder St., Denver, CO");

    store.AddUser(&buyer);
    store.AddUser(&seller);
    
    Product *p = ProductFactory::GetElectronicPhone("Apple iPhone 13");
    seller.SellProduct(p);
    seller.ShowProducts(); //should show iPhone 13 with bid not open yet

    seller.OpenBid(p);
    seller.ShowProducts(); //should show iPhone 13 with base price of 700.00 with bid open

    buyer.PlaceBid(p, 725.00);
    seller.ShowProducts(); //should show iPhone 13 with highest bid at 725.00

    cout << p->get_id() << endl; // first product added should have id = 1

    Product *p2 = ProductFactory::GetMusicVinyl("Currents by Tame Impala");
    seller.SellProduct(p2);
    seller.OpenBid(p2);
    buyer.PlaceBid(p2, 45.00);

    seller.ShowProducts(); //should show iphone and vinyl

    cout << p2->get_id() << endl; //should have id = 2

    p->SetIsSold(true); //marking iphone as sold should remove it from seller products

    seller.ShowProducts(); //should show only vinyl

    buyer.SendMessage(&seller, "how is the condition on the iphone you are selling?");
    seller.SendMessage(&buyer, "its in great condition!!");
    User::PrintMesssages(&buyer, &seller);

    cout << store.get_size_users() << endl;
    store.LoadFromFile("users.csv", "products.csv");
    cout << store.get_size_users() << endl;

    for (User* curr : store.get_users()) {
        cout << curr->get_username() << endl;
        Seller* temp = (Seller*) curr;
        for (Product * current : temp -> get_seller_products()) {
            cout << current->get_name() << endl;
        }
        cout << endl;
    }*/

}