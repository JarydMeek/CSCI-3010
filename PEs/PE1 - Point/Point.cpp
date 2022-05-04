#include "Point.h"
#include <cmath> //math library for absolute value and sqrt

using namespace std;

//default constructor
Point::Point() {
    x_coord_ = 0;
    y_coord_ = 0;
}
//parameterized constructor (2 parameters)
Point::Point(int newx_coord_, int newy_coord_) {
    x_coord_ = newx_coord_;
    y_coord_ = newy_coord_;
}
//getter for x_coord_
int Point::get_x() {
    return x_coord_;
}
//getter for y_coord_
int Point::get_y() {
    return y_coord_;
}

//setter for x_coord_
bool Point::set_x(int new_x_coord_) {
    x_coord_ = new_x_coord_;
    return true;
}
//setter for y_coord_
bool Point::set_y(int new_y_coord_) {
    y_coord_ = new_y_coord_;
    return true;
}

/* ACTUAL FUNCTIONS */

/*
  Function: Calculates Euclidian Distance
  Input: Point to calculate distance from
  Returns: Euclidian Distance Between Two Points
*/
double Point::Distance(Point otherPoint) {
    //Sqrt((x2-x1)^2 + (y2-y1)^2)
    return sqrt(pow(abs(otherPoint.get_x() - x_coord_),2) + pow(abs(otherPoint.get_y() - y_coord_),2));
}
/*
  Function: Adds an offset to both the X and Y coordinates
  Input: Value to offset coordinates by
  Returns: True on successful change of coords
*/
bool Point::Translate(int offset) {
    x_coord_ += offset;
    y_coord_ += offset;
    return true;
}