/**
Jaryd Meek
PE 1
This program makes creates a class for 2d points and allows users to manipulate them.
*/


#include "Point.h"
#include <iostream>

using namespace std;

int main() {
    //Create 3 Points
    Point pt1;
    Point pt2(2,5);
    Point pt3(-2, 1);

    //Print Points and Distances:
    cout << "Point 1 Coordinates: (" << pt1.get_x() << "),(" << pt1.get_y() << ")" << endl;
    cout << "Point 2 Coordinates: (" << pt2.get_x() << "),(" << pt2.get_y() << ")" << endl;
    cout << "Point 3 Coordinates: (" << pt3.get_x() << "),(" << pt3.get_y() << ")" << endl << endl;
    
    cout << "Distance Between Point 1 and 2: " << pt1.Distance(pt2) << endl;
    cout << "Distance Between Point 1 and 3: " << pt1.Distance(pt3) << endl;
    cout << "Distance Between Point 2 and 3: " << pt2.Distance(pt3) << endl << endl;

    //Translate one of the points

    pt1.Translate(2);
    cout << "Translated Point 1 by 2" << endl;

    //print out new info
    cout << "New Point 1 Coordinates: (" << pt1.get_x() << "),(" << pt1.get_y() << ")" << endl;
    cout << "Distance Between Point 1 and 2: " << pt1.Distance(pt2) << endl;
    cout << "Distance Between Point 1 and 3: " << pt1.Distance(pt3) << endl << endl;

    pt1.Translate(-10);
    cout << "Translated Point 1 by -10" << endl;

    //print out new info
    cout << "New Point 1 Coordinates: (" << pt1.get_x() << "),(" << pt1.get_y() << ")" << endl;
    cout << "Distance Between Point 1 and 2: " << pt1.Distance(pt2) << endl;
    cout << "Distance Between Point 1 and 3: " << pt1.Distance(pt3) << endl;
}