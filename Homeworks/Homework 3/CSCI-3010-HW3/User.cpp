#include "Store.hpp"
#include "User.hpp"
#include "Product.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Message*> User::messages_;
vector<Message*> User::new_messages_;

/**
  User construct, not used directly anywhere.
  Sellers and Buyers are created by referrring to this parent constructor.

  @param username The user's username
  @param phone_no The user's phone number
  @param address The user's address
*/
User::User(string username, long phone_no, string address) {
  username_ = username;
  phone_no_ = phone_no;
  address_ = address;
  balance_ = 2000;
  num_ratings_ = 0;
}

/**
  Rewrites the user's information with the given parameters.

  @param username The user's  new username
  @param phone_no The user's new phone number
  @param address The user's new address
*/
void User::UpdateUser(string username, long phone_no, string address) {
  username_ = username;
  phone_no_ = phone_no;
  address_ = address;
}

/**
  Send a message between this objects user and another user

  @param recipient Recipient of the message
  @param text The string that is the basis of the message
*/
void User::SendMessage(User *recipient, string text) {
  Message* m = new Message;
  m->text = text;
  m->recipient = recipient;
  m->sender = this;

  messages_.push_back(m);
  new_messages_.push_back(m);
}

/**
  Let's this object's user rate another user

  @param user_to_rate The user you are trying to rate
  @param rating The rating you are giving this user
*/
void User::RateUser(User &user_to_rate, int rating) {
  user_to_rate.SetRating(rating);
}

/**
  Prints the messages between two users (not implemented)

  @param user1 A user
  @param user2 Another user
*/
void User::PrintMesssages(User *user1, User *user2) {
  cout << "---------------------------" << endl;
  cout << "Messages between: " << user1->get_username() << " and " << user2->get_username() << endl;
  for (Message *m : messages_) {
    if ((m->recipient->get_username() == user1->get_username()) 
    || (m->recipient->get_username() == user2->get_username())) {
      cout << m->text << endl;
    }
  }
  cout << "---------------------------" << endl;
}

/**
  Adds a product to the seller's selling list.
  Pushes the new product into the seller's product vector.

  @param p The product to add
*/
void Seller::SellProduct(Product *p) {
  seller_products_.push_back(p);
}

/**
  Opens a bid for a product.

  @param p The product to open the bid for
*/
void Seller::OpenBid(Product *p) {
  for (Product *item: seller_products_) {
    if (item->get_id() == p->get_id()) {
      p->SetIsBidded(true);
    }
  }
}

/**
  Prints out the products the seller has for sale.

  @param showNumber Boolean to determine if the product number will be shown in the print output
  @param showSold Boolean to determine if sold products will show in the print output
  @param counter Counter for the product numbers in the print output
*/
void Seller::ShowProducts(bool showNumber, bool showSold, int &counter) {
  for (Product *p: seller_products_) {
    if (showSold) {
      if (showNumber) {
        cout << "Product " << counter+1 << endl;
      }
      cout << "---------------------------" << endl <<
      p->get_name() << endl <<
      "Quality: " << p->get_quality() << endl <<
      "Base Price: " << p->get_base_price() << endl <<
      "Highest Bid: " << p->get_highest_bid() << endl <<
      "Sold: " << ((p->get_is_sold()) ? "Yes" : "Not yet") << endl <<
      "Bid open: " << ((p->get_is_bidded()) ? "Yes" : "Not yet") << endl <<
      "---------------------------" << endl;
      counter++;
    } else if (p->get_is_sold() == false && showSold == false) {
      if (showNumber) {
        cout << "Product " << counter+1 << endl;
      }
      cout << "---------------------------" << endl <<
      p->get_name() << endl <<
      "Quality: " << p->get_quality() << endl <<
      "Base Price: " << p->get_base_price() << endl <<
      "Highest Bid: " << p->get_highest_bid() << endl <<
      "Sold: " << ((p->get_is_sold()) ? "Yes" : "Not yet") << endl <<
      "Bid open: " << ((p->get_is_bidded()) ? "Yes" : "Not yet") << endl <<
      "---------------------------" << endl;
      counter++;
    }
  }
}

/**
  As a buyer, place a bid on a product.

  @param p The product to set a bid on
  @param bid_price The price to set the bid for
*/
void Buyer::PlaceBid(Product *p, double bid_price) {
    p->SetBid(bid_price, this);
    bids_.push_back(p);
    bids_amount_.push_back(bid_price);
}

