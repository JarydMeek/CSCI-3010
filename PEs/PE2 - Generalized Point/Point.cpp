#include "Point.h"
#include <iostream>
#include <cmath> //math library for absolute value and sqrt

using namespace std;

/* CONSTRUCTORS */

//default constructor
Point::Point(int n) {
    for (int x = 0; x < n; x++) {
        coords_.push_back(0);
    }
}
//parameterized constructor (1 parameter, array or vector)
Point::Point(vector<int> new_coords_) {
    coords_ = vector<int>(new_coords_);
}

/* ACCESSOR FUNCTIONS */

//getter for all coordinates
vector<int> Point::get_coords() {
    return coords_;
}

//getter for coordinate at specific index (verifies that index is valid)
//returns coords if valid index or -1 if invalid index
int Point::get_specific_coord(int index) {
    if (index >= coords_.size() || index < 0) {
        cout << "Invalid Index" << endl;
        return -1;
    }
    return coords_[index];
}

//getter for number of dimensions
int Point::get_dimensions() {
    return coords_.size();
}

//setter for coordinate at specific index (verifies that the index is valid)
//Returns true if was able to set new coords, false if invalid index
bool Point::set_coord(int index, int new_coord) {
    if (index >= coords_.size() || index < 0) {
        cout << "Invalid Index" << endl;
        return false;
    }
    coords_[index] = new_coord;
    return true;
}

/* ACTUAL FUNCTIONS */

/*
  Function: Calculates Euclidian Distance
  Input: Point to calculate distance from
  Returns: Euclidian Distance Between Two Points or -1.0 if points have different number of dimensions
*/
double Point::Distance(Point otherPoint) {
    if (otherPoint.get_dimensions() != coords_.size()) {
        cout << "Points have different number of dimensions, cannot continue" << endl;
        return -1.0;
    }
    //Sqrt((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2....)
    int sum = 0;
    for (int x = 0; x < coords_.size(); x++) {
        sum += pow(abs(otherPoint.get_specific_coord(x) - coords_[x]),2);
    }
    return sqrt(sum);
}
/*
  Function: Adds an offset to all of the coordinates
  Input: Value to offset coordinates by
  Returns: True on successful change of coordinates
*/
bool Point::Translate(int offset) {
    for (int x = 0; x < coords_.size(); x++) {
        coords_[x] += offset;
    } 
    return true;
}