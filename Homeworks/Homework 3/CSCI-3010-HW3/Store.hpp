#ifndef STORE_HPP
#define STORE_HPP

#include <string>
#include <vector>

using namespace std;

class User;
class Product;

struct Message {
  User *recipient;
  User *sender;
  string text;
};

class Store {
public:
  void LoadFromFile(string file_users, string file_inventory);
  vector<User*> get_users() { return users_; };
  vector<Product*> get_active_listings() { return listings_; };
  vector<Product*> get_completed_listings();
  int get_size_users() { return users_size_; };
  int get_size_listings() { return listings_size_; };

  void PrintMenu();
  void AddUser(User *user);

  static Store& get_instance() {
    static Store instance;
    return instance;
  }

  Store(Store const&) = delete;
  void operator=(Store const&) = delete;

private:
  Store();
  vector<User*> users_;
  vector<Product*> listings_;
  int users_size_;
  int listings_size_;
  
};


#endif
