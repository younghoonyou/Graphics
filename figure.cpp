#include "figure.h"
#include <cmath>
#define MIN(a,b) ((a<b)?a:b)

int XPLUS = 45;//To locate square to center
int YPLUS = 25;//To locate square to center

void Point::Z_Rotate(int degree){
    double rad = ((double)degree * M_PI)/180;
    double matrix[3][3] = {//Z rotation matrix
            {cos(rad), -sin(rad), 0},
            {sin(rad), cos(rad), 0},
            {0, 0, 1},
        };
    if(degree == 90){
        matrix[0][0] = matrix[1][1] = 0;
    }
    double P[4] = {this->x, this->y, this->z, 1.0f};
    Point tmp;
    for (int i = 0; i < 3; ++i) tmp.x += (matrix[0][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.y += (matrix[1][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.z += (matrix[2][i] * P[i]);
    *this = tmp;
}

void Point::Y_Rotate(int degree){
    double rad = (M_PI * degree) / 180;
    double matrix[4][4] = {//Y rotation matrix
        {1,0,0,0},
        {0,cos(rad),-sin(rad),0},
        {0,sin(rad),cos(rad),0},
        {0, 0, 0, 1},
    };
    if (degree == 90){
        matrix[1][1] = matrix[2][2] = 0;
    }
    double P[4] = {this->x, this->y, this->z, 1.0f};
    Point tmp;
    for (int i = 0; i < 3; ++i) tmp.x += (matrix[0][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.y += (matrix[1][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.z += (matrix[2][i] * P[i]);
    *this = tmp;
}

void Point::X_Rotate(int degree){
    double rad = (M_PI * degree) / 180;
    double matrix[4][4] = {//X rotation matrix
        {cos(rad), 0, sin(rad), 0},
        {0, 1, 0, 0},
        {-sin(rad), 0, cos(rad), 0},
        {0, 0, 0, 1},
    };
    if (degree == 90){
        matrix[0][0] = matrix[2][2] = 0;
    }
    double P[4] = {this->x, this->y, this->z, 1.0f};
    Point tmp;
    for (int i = 0; i < 3; ++i) tmp.x += (matrix[0][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.y += (matrix[1][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.z += (matrix[2][i] * P[i]);
    *this = tmp; 
}

    Point Point::Projection(){//Orthogonal projection
        double matrix[4][4] = {
            {1, 0, 0, 0},  // w
            {0, 1, 0, 0},  // h
            {0, 0, 1, 1},  // a
            {0, 0, -1, 0}, // b
        };
        Point ret;
        double P1[4] = {this->x, this->y, this->z, 1.f};
        for (int i = 0; i < 4; ++i) ret.x += (matrix[0][i] * P1[i]);
        for (int i = 0; i < 4; ++i) ret.y += (matrix[1][i] * P1[i]);
        return ret;
    }

void Line::Draw(std::vector<std::vector<char>> &m){
    Point f1 = this->p1.Projection();
    Point f2 = this->p2.Projection();

    double x_increase = (f2.x - f1.x);
    double y_increase = (f2.y - f1.y);
    if(x_increase == 0){//If y is same
        if(f1.y < f2.y){
            for (int i = (int)(f1.y); i <= (int)(f2.y); ++i) m[(int)(f1.x) + XPLUS][i + YPLUS] = '*';
        }
        else{
            for (int i = (int)(f2.y); i <= (int)(f1.y); ++i) m[(int)(f1.x) + XPLUS][i + YPLUS] = '*';
        }
        return;
    }
    else if(y_increase == 0){//if x is same
        if (f1.x < f2.x){
            for (int i = (int)(f1.x); i <= (int)(f2.x); ++i)
                m[i + XPLUS][(int)(f1.y) + YPLUS] = '*';
        }
        else{
            for (int i = (int)(f2.x); i <= (int)(f1.x); ++i) m[i + XPLUS][(int)(f1.y) + YPLUS] = '*';
        }
        return;
    }
    double gradient = (double)(y_increase /x_increase);
    double remain = double(f1.y - (gradient * f1.x));
    // we can know the y = ax + b and just put data on equation
    if(abs(gradient) < 1){ // if gradient is bigger than 1 we should focus on y data. If we focus on x data the gab between next y is would be more bigger
        if (f1.x < f2.x){//start with small one
            for (int i = (int)(f1.x); i <= (int)(f2.x); ++i){
                int y = (int)((gradient * i) + remain);
                m[i + XPLUS][y + YPLUS] = '*';
            }
        }
        else{
            for (int i = (int)(f2.x); i <= (int)(f1.x); ++i){
                int y = (int)((gradient * i) + remain);
                m[i + XPLUS][y + YPLUS] = '*';
            }
        }
    }
    else{
        if(f1.y < f2.y){
            for (int i = (int)(f1.y); i <= (int)(f2.y); ++i){
                int x = (int)(((double)i - remain) / gradient);
                m[x + XPLUS][i + YPLUS] = '*';
            }
        }
        else{
            for (int i = (int)(f2.y); i <= (int)(f1.y); ++i){
                int x = (int)(((double)i - remain) / gradient);
                m[x + XPLUS][i + YPLUS] = '*';
            }
        }
    }
}