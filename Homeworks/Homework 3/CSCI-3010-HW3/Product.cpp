#include "Store.hpp"
#include "User.hpp"
#include "Product.hpp"

using namespace std;

int Product::counter_ = 0;

/**
  Set a bid on a product

  @param bid_amount The price of the bid
  @param bidder The buyer who is bidding
*/
void Product::SetBid(double bid_amount, User *bidder) { 
  highest_bid_ = bid_amount; 
  bidding_users_.push_back(bidder);
  bidding_amount_.push_back(bid_amount);
  is_bidded_ = true;
};

/**
  Product factory, returns new child Product objects

  @param name Name for the product
  @param condition The condition of the product
  @param price The base price of the product
*/
Paperback* ProductFactory::GetBookPaperback(string name, string condition, double price) {
  return new Paperback(name, condition, price);
}
Hardcover* ProductFactory::GetBookHardcover(string name, string condition, double price) {
  return new Hardcover(name, condition, price);
}
Digital* ProductFactory::GetBookDigital(string name, string condition, double price) {
  return new Digital(name, condition, price);
}
Vinyl* ProductFactory::GetMusicVinyl(string name, string condition, double price) {
  return new Vinyl(name, condition, price);
}
CD* ProductFactory::GetMusicCD(string name, string condition, double price) {
  return new CD(name, condition, price);
}
MP3* ProductFactory::GetMusicMP3(string name, string condition, double price) {
  return new MP3(name, condition, price);
}
TV* ProductFactory::GetElectronicTV(string name, string condition, double price) {
  return new TV(name, condition, price);
}
Computer* ProductFactory::GetElectronicComputer(string name, string condition, double price) {
  return new Computer(name, condition, price);
}
Phone* ProductFactory::GetElectronicPhone(string name, string condition, double price) {
  return new Phone(name, condition, price);
}
Painting* ProductFactory::GetArtPainting(string name, string condition, double price) {
  return new Painting(name, condition, price);
}
Photo* ProductFactory::GetArtPhoto(string name, string condition, double price) {
  return new Photo(name, condition, price);
}
Sculpture* ProductFactory::GetArtSculpture(string name, string condition, double price) {
  return new Sculpture(name, condition, price);
}
Shirt* ProductFactory::GetClothingShirt(string name, string condition, double price) {
  return new Shirt(name, condition, price);
}
Pants* ProductFactory::GetClothingPants(string name, string condition, double price) {
  return new Pants(name, condition, price);
}
Shoes* ProductFactory::GetClothingShoes(string name, string condition, double price) {
  return new Shoes(name, condition, price);
}