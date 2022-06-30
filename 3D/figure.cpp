#include "figure.h"
#include <cmath>
void Line::Draw(std::vector<std::vector<char> >& m){
    int x_increase = (p2.x - p1.x);
    int y_increase = (p2.y - p1.y);
    if(x_increase == 0){
        for (int i = p1.y;i<=p2.y;++i){
            m[p1.x][i] = '*';
        }
        return;
    }
    else if(y_increase == 0){
        std::cout << p1.y<<' '<<p1.x<<' '<<p2.x;
        for (int i = p1.x; i <= p2.x; ++i)
        {
            m[i][p1.y] = '*';
        }
        return;
    }
    float gradient = (float)x_increase / (float)y_increase;
    int remain = round(p1.y - gradient * p1.x);
    for (int i = p1.x; i <= p2.x; ++i){
        int y = round((float)(gradient*i)) + remain;
        std::cout << i << ' ' << y << '\n';
        m[i][y] = '*';
    }
}