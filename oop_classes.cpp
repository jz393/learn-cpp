//  Created by Jane Zhang on 1/8/19.
//  Copyright © 2019 Jane Zhang. All rights reserved.
/*  This is an implementation of a simple class structure
in C++. */

#include <iostream>
using namespace std;

//the superclass
class Point {
    //attribute variables
    int x;
    int y;  

    public: //object functions
    Point(int, int); //Constructor 1
    Point(); //Constructor 2
    void set_values(int, int);
    int get_x();
    int get_y();
} point1, point2; //object names

//the subclass
class Point_3D : public Point{
    int z; //x and y inherited
    
    public: //can implement functions within class declaration 
    Point_3D(int x, int y, int z_val) : Point(x, y), z(z_val)  {}; //constructor 1 
    Point_3D(): Point(0, 0), z(0)  {}; //constructor 2
    int get_z() {return z;} //additional method
    //all others inherited
};

//we can also implement functions outside of class declaration
Point::Point(int x, int y) {
    Point::set_values(x, y);
}

Point::Point() {
    Point::set_values(0, 0);
}

void Point::set_values (int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::get_x() {
    return this->x;
}

int Point::get_y() {
    return this->y;
}


//main function 
int main(){
    //superclass
    Point point1 (3, 4);
    Point point2;

    cout << "point1: " << point1.get_x() << ", " << point1.get_y() << endl;
    cout << "point2: " << point2.get_y() << ", " << point2.get_y() << endl;

    //subclass
    Point_3D point3 (3,4,5);
    Point_3D point4;

    cout << "point3: " << point3.get_x() << ", " << point3.get_y() <<  ", " << point3.get_z() << endl;
    cout << "point4: " << point4.get_x() << ", " << point4.get_y() <<  ", " << point4.get_z() <<endl;

    return 0;
}

