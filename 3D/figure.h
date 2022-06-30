#ifndef __FIGURE_H_
#define __FIGURE_H_
#include <vector>
#include <iostream>
struct Point{
    float x, y;
    Point(){
        x = 0;
        y = 0;
    }
    Point(float x_,float y_){
        x = x_;
        y = y_;
    }
    Point(const Point& p){
        this->x = p.x;
        this->y = p.y;
    }
    Point& operator=(const Point &p){
        this->x = p.x;
        this->y = p.y;
        return *this;
    }
};
struct Line{
    Point p1, p2;
    Line(Point p1_,Point p2_){
        // if(p1_.x > p2_.x){
        //     p2 = p1_;
        //     p1 = p2_;
        // }
        // else{
            p1 = p1_;
            p2 = p2_;
            // }
    }
    void Draw(std::vector<std::vector<char> >& m);
};
#endif