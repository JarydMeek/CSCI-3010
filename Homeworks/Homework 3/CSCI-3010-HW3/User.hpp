#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <vector>

using namespace std;

struct Message;
class Product;
class Buyer;

class User {
public:
  User(string username, long phone_no, string address);
  void UpdateUser(string username, long phone_no, string address);

  double get_account_balance() { return balance_; };
  void SetAccountBalance(double balance) { balance_ = balance; };

  int get_num_ratings() { return num_ratings_; };
  int get_rating() { return rating_; };
  void SetRating(int rating) { num_ratings_++; rating_ = (rating_+rating)/num_ratings_; };

  string get_username() { return username_; };
  void SetUsername(string username) { username_ = username; };

  string get_address() { return address_; };
  void SetAddress(string address) { address_ = address; }

  long get_phone_number() { return phone_no_; };
  void SetPhoneNo(long phone_no) { phone_no_ = phone_no; };

  static vector<Message*> get_messages() { return messages_; };
  static vector<Message*> get_new_messages() { return new_messages_; };
  void clear_messages() {new_messages_.clear();};
  static void PrintMesssages(User *user1, User *user2);
  void SendMessage(User *recipient, string message);
  vector <User*> get_can_message() {return can_message_;};
  void add_can_message(User* to_add) { can_message_.push_back(to_add); };

  void RateUser(User &user_to_rate, int rating);

  virtual string get_type() {return "user";};

private:
  double balance_;
  int rating_;
  int num_ratings_;
  string username_;
  long phone_no_;
  string address_;

  static vector<Message*> messages_;
  static vector<Message*> new_messages_;
  vector<User*> can_message_;
};


class Seller : public User {
public:
  Seller(string username, long phone_no, string address, bool delivery):
  User(username, phone_no, address)
  {
    ship = delivery;
  }

  vector<Product*> get_seller_products() { return seller_products_; };

  void SellProduct(Product *p);
  void OpenBid(Product *p);
  void ShowProducts(bool showNumber, bool showSold, int &counter);
  bool get_ship() {return ship;};

  string get_type() {return "seller";};

private:
  vector<Product *> seller_products_;
  bool ship;
};

class Buyer : public User {
public:
  Buyer(string username, long phone_no, string address):
  User(username, phone_no, address)
  {}

  vector<Product *> get_bids() { return bids_; };
  vector<double> get_bid_amounts() { return bids_amount_; };
  vector<Product *> get_purchase_history(){ return purchase_history_; };

  vector<Product *> get_products_for_sale();
  void PlaceBid(Product *p, double bid_price);

  void add_to_history(Product * item) { purchase_history_.push_back(item);};

   string get_type() {return "buyer";};

private:
  vector<Product *> bids_;
  vector<double> bids_amount_;
  vector<Product *> purchase_history_;
};

#endif
