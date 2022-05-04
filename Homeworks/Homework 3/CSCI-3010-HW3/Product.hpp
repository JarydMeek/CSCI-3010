#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class User;

using namespace std;

struct Message;

class Product {
public:
  Product(string name, string quality, double base_price) {
    name_ = name;
    quality_ = quality;
    base_price_ = base_price;
    highest_bid_ = base_price;
    is_sold_ = false;
    is_bidded_ = false;
    counter_++;
    id_ = counter_;
  }

  string get_name() { return name_; };
  string get_quality() { return quality_; };
  double get_base_price() { return base_price_; };
  double get_highest_bid() { return highest_bid_; };
  bool get_is_sold() { return is_sold_; };
  bool get_is_bidded() { return is_bidded_; };
  int get_id() { return id_; };

  vector<User*> get_bidding_users() {return bidding_users_;};
  vector<double> get_bidding_amount() {return bidding_amount_;};

  void SetIsSold(bool sold) { is_sold_ = sold; is_bidded_ = false; };
  void SetIsBidded(bool bided) { is_bidded_ = bided; is_sold_ = false; };
  void SetBid(double bid_amount, User *bidder);

  void SetPickup(string add) {pickup_ = true; pickup_address_ = add;}
  bool get_pickup() {return pickup_;}
  string get_pickup_address() {return pickup_address_;}
private:
  string quality_;
  double base_price_;
  double highest_bid_;
  bool is_sold_;
  bool is_bidded_;
  string name_;
  int id_;
  bool pickup_;
  string pickup_address_;
  vector<User*> bidding_users_;
  vector<double> bidding_amount_;

  static int counter_;
};

class Book : public Product {
public:
  Book(string name, string quality, double base_price):
  Product(name, quality, base_price)
  {}
};

class Paperback : public Book { 
public:
  Paperback(string name, string quality, double base_price):
  Book(name, quality, base_price)
  {}
};
class Hardcover : public Book { 
public:
  Hardcover(string name, string quality, double base_price):
  Book(name, quality, base_price)
  {}
};
class Digital : public Book { 
public:
  Digital(string name, string quality, double base_price):
  Book(name, quality, base_price)
  {}
};


class Music : public Product {
public:
  Music(string name, string quality, double base_price):
  Product(name, quality, base_price)
  {}
};

class Vinyl : public Music { 
public:
  Vinyl(string name, string quality, double base_price):
  Music(name, quality, base_price)
  {}
};
class CD : public Music { 
public:
  CD(string name, string quality, double base_price):
  Music(name, quality, base_price)
  {}
};
class MP3 : public Music { 
public:
  MP3(string name, string quality, double base_price):
  Music(name, quality, base_price)
  {}
};

class Electronic : public Product {
public:
  Electronic(string name, string quality, double base_price):
  Product(name, quality, base_price)
  {}
};

class TV : public Electronic { 
public:
  TV(string name, string quality, double base_price):
  Electronic(name, quality, base_price)
  {}
};
class Computer : public Electronic { 
public:
  Computer(string name, string quality, double base_price):
  Electronic(name, quality, base_price)
  {}
};
class Phone : public Electronic { 
public:
  Phone(string name, string quality, double base_price):
  Electronic(name, quality, base_price)
  {}
};

class Art : public Product {
public:
  Art(string name, string quality, double base_price):
  Product(name, quality, base_price)
  {}
};

class Painting : public Art { 
public:
  Painting(string name, string quality, double base_price):
  Art(name, quality, base_price)
  {}
};
class Photo : public Art { 
public:
  Photo(string name, string quality, double base_price):
  Art(name, quality, base_price)
  {}
};
class Sculpture : public Art { 
public:
  Sculpture(string name, string quality, double base_price):
  Art(name, quality, base_price)
  {}
};


class Clothing : public Product {
public:
  Clothing(string name, string quality, double base_price):
  Product(name, quality, base_price)
  {}
};

class Shirt : public Clothing { 
public:
  Shirt(string name, string quality, double base_price):
  Clothing(name, quality, base_price)
  {}
};
class Pants : public Clothing { 
public:
  Pants(string name, string quality, double base_price):
  Clothing(name, quality, base_price)
  {}
};
class Shoes : public Clothing { 
public:
  Shoes(string name, string quality, double base_price):
  Clothing(name, quality, base_price)
  {}
};

class ProductFactory {
public:
  static Paperback* GetBookPaperback(string name, string condition = "new", double price = 15.00);
  static Hardcover* GetBookHardcover(string name, string condition = "used", double price = 5.00);
  static Digital* GetBookDigital(string name, string condition = "digital", double price = 7.00);
  static Vinyl* GetMusicVinyl(string name, string condition = "used", double price = 40.00);
  static CD* GetMusicCD(string name, string condition = "used", double price = 15.00);
  static MP3* GetMusicMP3(string name, string condition = "digital", double price = 3.00);
  static TV* GetElectronicTV(string name, string condition = "used", double price = 150.00);
  static Computer* GetElectronicComputer(string name, string condition = "used", double price = 400.00);
  static Phone* GetElectronicPhone(string name, string condition = "new", double price = 700.00);
  static Painting* GetArtPainting(string name, string condition = "used", double price = 100.00);
  static Photo* GetArtPhoto(string name, string condition = "digital", double price = 20.00);
  static Sculpture* GetArtSculpture(string name, string condition = "used", double price = 500.00);
  static Shirt* GetClothingShirt(string name, string condition = "used", double price = 15.00);
  static Pants* GetClothingPants(string name, string condition = "used", double price = 30.00);
  static Shoes* GetClothingShoes(string name, string condition = "new", double price = 60.00);
};

#endif