#include "figure.h"
#include <cmath>
#define MIN(a,b) ((a<b)?a:b)
// const double PI = 3.141592;
int XPLUS = 20;
int YPLUS = 10;

void Point::Z_Rotate(int degree){
    double rad = ((double)degree * M_PI)/180;
    double matrix[3][3] = {
            {cos(rad), -sin(rad), 0},
            {sin(rad), cos(rad), 0},
            {0, 0, 1},
        };
    if(degree == 90){
        matrix[0][0] = matrix[1][1] = 0;
    }
    // std::cout << "Degree : " << cos(rad) << ' ' << sin(rad) << '\n';
    double P[4] = {this->x, this->y, this->z, 1.0f};
    Point tmp;
    for (int i = 0; i < 3; ++i) tmp.x += (matrix[0][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.y += (matrix[1][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.z += (matrix[2][i] * P[i]);
    *this = tmp;
    // std::cout << (int)this->x << ' ' << (int)this->y << ' ' << (int)this->z << '\n';
    // std::cout << ceil(this->x) << ' ' << ceil(this->y) << ' ' << round(this->z) << '\n';
}

void Point::Y_Rotate(int degree){
    double rad = (M_PI * degree) / 180;
    double matrix[4][4] = {
        {1,0,0,0},
        {0,cos(rad),-sin(rad),0},
        {0,sin(rad),cos(rad),0},
        {0, 0, 0, 1},
    };
    double P[4] = {this->x, this->y, this->z, 1.0f};
    Point tmp;
    for (int i = 0; i < 4; ++i) tmp.x += matrix[0][i] * P[i];
    for (int i = 0; i < 4; ++i) tmp.y += matrix[1][i] * P[i];
    for (int i = 0; i < 4; ++i) tmp.z += matrix[2][i] * P[i];
    *this = tmp;
    // std::cout << this->x << ' ' << this->y << ' ' << this->z << '\n';
}

void Point::X_Rotate(int degree){
    double rad = (M_PI * degree) / 180;
    double matrix[4][4] = {
        {cos(rad), 0, sin(rad), 0},
        {0, 1, 0, 0},
        {-sin(rad), 0, cos(rad), 0},
        {0, 0, 0, 1},
    };
    double P[4] = {this->x, this->y, this->z, 1.0f};
    Point tmp;
    for (int i = 0; i < 4; ++i) tmp.x += matrix[0][i] * P[i];
    for (int i = 0; i < 4; ++i) tmp.y += matrix[1][i] * P[i];
    for (int i = 0; i < 4; ++i) tmp.z += matrix[2][i] * P[i];
    *this = tmp;
    // std::cout << (int)this->x << ' ' << (int)this->y << ' ' << (int)this->z << '\n';
}

    void Point::Projection(){
    // double Aspect = (double)(204/46);
    // float h = 1 / tanf(1/1.f);
    // float w = h / Aspect;
    // float a = 1000.f / (1000.f - 1.f);
    // float b = -1.f * a;
    double matrix[4][4] = {
        {1, 0, 1, 0},//w
        {0, 1, 1, 0},//h
        {0, 0, 1, 1},//a
        {0, 0, -1, 0},//b
        };
    double tx,ty;
    tx = ty = 0.f;
    double P1[4] = {this->x, this->y, this->z, 1.f};
    for (int i = 0; i < 4; ++i) tx += (matrix[0][i] * P1[i]);
    for (int i = 0; i < 4; ++i) ty += (matrix[1][i] * P1[i]);
    // std::cout << tx << ' ' << ty << '\n';
    *this = {tx, ty, 0};
    }

void Line::Draw(std::vector<std::vector<char>> &m){
    int X_change = INT32_MAX;
    int Y_change = INT32_MAX;
    this->p1.Projection();
    this->p2.Projection();
    Point f1,f2;
    f1 = this->p1;
    f2 = this->p2;

    // std::cout << '\n';
    // std::cout << f1.x << ' ' << f1.y << ' ' << f1.z << '\n';

    for (int i = 59; i >= 0; --i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if(m[j][i] == '*'){
                X_change = MIN(X_change, i);
                Y_change = MIN(Y_change, j);
            }
        }
    }
    // XPLUS = 10 - X_change;
    // YPLUS = 10 - Y_change;
    // std::cout << XPLUS << ' ' << YPLUS; // std::cout << f2.x << ' ' << f2.y << ' ' << f2.z << '\n';
    double x_increase = (f2.x - f1.x);
    double y_increase = (f2.y - f1.y);
    if(x_increase == 0){
        if(f1.y < f2.y){
            for (int i = (int)(f1.y); i <= (int)(f2.y); ++i) m[(int)(f1.x) + XPLUS][i + YPLUS] = '*';
        }
        else{
            for (int i = (int)(f2.y); i <= (int)(f1.y); ++i) m[(int)(f1.x) + XPLUS][i + YPLUS] = '*';
        }
        // std::cout << (int)(f1.x) << ' ' << (int)(f1.y) << '\n';
        return;
    }
    else if(y_increase == 0){
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
    if(f1.x < f2.x){
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