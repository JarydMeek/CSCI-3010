#ifndef POINT_H
#define POINT_H
#include<vector>

class Point 
{ 
    private:
    std::vector<int> coords_;
    
    public:
     Point(int); // Default constructor
     Point(std::vector<int>); // Parameterized constructor
     std::vector<int> get_coords();
     int get_specific_coord(int);
     int get_dimensions();
     bool set_coord(int, int);
     double Distance(Point);
     bool Translate(int);
}; 

#endif 