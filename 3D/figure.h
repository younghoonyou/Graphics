#ifndef __FIGURE_H_
#define __FIGURE_H_
#include <vector>
#include <iostream>

struct Point{
    double x, y,z;
    Point(){
        x = 0;
        y = 0;
        z = 0;
    }
    Point(double x_,double y_,double z_){
        x = x_;
        y = y_;
        z = z_;
    }
    Point(const Point& p){
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
    }
    Point& operator=(const Point &p){
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
        return *this;
    }
    void X_Rotate(int degree);
    void Y_Rotate(int degree);
    void Z_Rotate(int degree);
    Point Projection();
};

struct Line{
    Point p1, p2;
    Line(){
    }
    Line(Point p1_,Point p2_){
            p1 = p1_;
            p2 = p2_;
    }
    void Draw(std::vector<std::vector<char> >& m);
};
#endif