#include "figure.h"
#include <cmath>

const int XPLUS = 30;
const int YPLUS = 30;

void Point::Z_Rotate(int degree){
    double rad = (double)degree * M_PI / 180;
    double matrix[3][3] = {
        {cos(rad), -sin(rad), 0},
        {sin(rad), cos(rad), 0},
        {0, 0, 1},
    };
    double P[4] = {this->x, this->y, this->z, 1.0f};
    Point tmp;
    for (int i = 0; i < 3; ++i) tmp.x += (matrix[0][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.y += (matrix[1][i] * P[i]);
    for (int i = 0; i < 3; ++i) tmp.z += (matrix[2][i] * P[i]);
    *this = tmp;
    std::cout << (int)this->x << ' ' << (int)this->y << ' ' << (int)this->z << '\n';
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
    std::cout << (int)this->x << ' ' << (int)this->y << ' ' << (int)this->z << '\n';
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
    tx = ty = 0;
    double P1[4] = {this->x, this->y, this->z, 1.f};
    for (int i = 0; i < 4; ++i) tx += (matrix[0][i] * P1[i]);
    for (int i = 0; i < 4; ++i) ty += (matrix[1][i] * P1[i]);
    *this = {tx, ty, 0};
    }

void Line::Draw(std::vector<std::vector<char>> &m){
    this->p1.Projection();
    this->p2.Projection();
    Point f1,f2;
    f1 = this->p1;
    f2 = this->p2;
    // std::cout << (int)f1.x << ' ' << (int)f1.y << '\n';
    // std::cout << (int)f2.x << ' ' << (int)f2.y << '\n';
    int x_increase = (f2.x - f1.x);
    int y_increase = (f2.y - f1.y);
    if(x_increase == 0){
        for (int i = f1.y;i<=f2.y;++i) m[f1.x + XPLUS][i + YPLUS] = '*';
        return;
    }
    else if(y_increase == 0){
        for (int i = f1.x; i <= f2.x; ++i) m[i + XPLUS][f1.y + YPLUS] = '*';
        return;
    }
    double gradient = (double)(x_increase /y_increase);
    double remain = double(f1.y - (gradient * f1.x));
    for (int i = f1.x; i <= f2.x; ++i){
        int y = ceil((gradient*i) + remain);
        std::cout << i << ' ' << y << '\n';
        m[i + XPLUS][y + YPLUS] = '*';
    }
}