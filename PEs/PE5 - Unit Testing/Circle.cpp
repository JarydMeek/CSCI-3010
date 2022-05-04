
/**
Jaryd Meek
PE5
This program fixes the bugs found in the Circle.o File
*/



//The bugs found in the Circle.o file

//Overlaps really didn't work at all
//Shrink would allow the radius to become negative.


#include "Circle.h"
#include <math.h>

  Circle::Circle(Point p, int rad) {
      center_ = p;
      radius_ = rad;
  }

 /*
  Function: Determines if two circles touch or overlap
  Input: other circle to compare to
  Returns: True if Circles overlap, and False if they don't
*/
  bool Circle::Overlaps(Circle& other) {
      //Logic from here https://www.geeksforgeeks.org/check-two-given-circles-touch-intersect/
      int distSq = (center_.x - other.get_center().x) * (center_.x - other.get_center().x) +
                   (center_.y - other.get_center().y) * (center_.y - other.get_center().y);
      int radSumSq = (radius_ + other.get_radius()) * (radius_ + other.get_radius());
      if (distSq <= radSumSq)
          return true;
      else 
          return false;
  }

  /*
  Function: Calculates area of circle
  Input: None
  Returns: area (as an int)
*/
  int Circle::CalculateArea() {
      return radius_ * radius_ * M_PI;
  }

 /*
  Function: Increases the radius by 1
  Input: None
  Returns: None
*/
  void Circle::Expand() {
      radius_++;
  }

  /*
  Function: Decreases the radius by 1 (minimum at 0)
  Input: None
  Returns: None
*/
  void Circle::Shrink() {
      if (radius_ > 0)
      {
          radius_--;
      }
  }