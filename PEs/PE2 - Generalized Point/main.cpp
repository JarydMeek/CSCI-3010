/**
Jaryd Meek
PE 2
This program makes creates a class for multi-dimentional points and allows users to manipulate them.
*/


#include "Point.h"
#include <iostream>

using namespace std;

int main() {
    //Create 3 Points
    Point pt1(2);
    Point pt2(vector<int> {2,5});
    Point pt3(vector<int> {-2,1});

    //Print Points and Distances:
    cout << "Point 1 Coordinates: (" << pt1.get_specific_coord(0) << "),(" << pt1.get_specific_coord(1) << ")" << endl;
    cout << "Point 2 Coordinates: (" << pt2.get_specific_coord(0) << "),(" << pt2.get_specific_coord(1) << ")" << endl;
    cout << "Point 3 Coordinates: (" << pt3.get_specific_coord(0) << "),(" << pt3.get_specific_coord(1) << ")" << endl << endl;
    
    cout << "Distance Between Point 1 and 2: " << pt1.Distance(pt2) << endl;
    cout << "Distance Between Point 1 and 3: " << pt1.Distance(pt3) << endl;
    cout << "Distance Between Point 2 and 3: " << pt2.Distance(pt3) << endl << endl;

    //Translate one of the points

    pt1.Translate(2);
    cout << "Translated Point 1 by 2" << endl;

    //print out new info
    cout << "New Point 1 Coordinates: (" << pt1.get_specific_coord(0) << "),(" << pt1.get_specific_coord(1) << ")" << endl;
    cout << "Distance Between Point 1 and 2: " << pt1.Distance(pt2) << endl;
    cout << "Distance Between Point 1 and 3: " << pt1.Distance(pt3) << endl << endl;

    pt1.Translate(-10);
    cout << "Translated Point 1 by -10" << endl;

    //print out new info
    cout << "New Point 1 Coordinates: (" << pt1.get_specific_coord(0) << "),(" << pt1.get_specific_coord(1) << ")" << endl;
    cout << "Distance Between Point 1 and 2: " << pt1.Distance(pt2) << endl;
    cout << "Distance Between Point 1 and 3: " << pt1.Distance(pt3) << endl;
}