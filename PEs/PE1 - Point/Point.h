#ifndef POINT_H
#define POINT_H


class Point 
{ 
    private:
    int x_coord_;
    int y_coord_;
    
    public:
     Point(); // Default constructor
     Point(int, int); // Parameterized constructor
     int get_x();
     int get_y();
     bool set_x(int);
     bool set_y(int);
     double Distance(Point);
     bool Translate(int);
}; 

#endif 