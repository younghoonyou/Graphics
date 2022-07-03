#include <iostream>
#include <cctype>
#include "figure.h"
#include <vector>
#include <string.h>
#include <ncurses.h>
void clear_arr(std::vector<std::vector<char>> &m){
    for (int i = 59; i >= 0; --i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (j == 0 || j == 99 || i == 0 || i == 59) m[j][i] = '.';
            else m[j][i] = ' ';
        }
    }
} 
void show(std::vector<std::vector<char>> &m){
        for (int i = 59; i >= 0; --i){
            for (int j = 0; j < 100; ++j){
                std::cout << m[j][i] << ' ';
            }
            std::cout << '\n';
        }
}

int main(){
    std::cout.tie(0), std::ios_base::sync_with_stdio(false);
    std::vector<std::vector<char>> m(100, std::vector<char>(60,' '));
    Point x[8] = {
        {-10, -8, -5},
        {10, -8, -5},
        {-10, 8, -5},
        {10, 8, -5},
        {-10, 8, 5},
        {10, 8, 5},
        {-10, -8, 5},
        {10, -8, 5},
    };
    while(1){
        for (Point &P : x){
            P.X_Rotate(10);
            P.Y_Rotate(10);
            P.Z_Rotate(10);
        }
        Line l[12] = {
            {x[0], x[1]},
            {x[0], x[2]},
            {x[1], x[3]},
            {x[2], x[3]},
            {x[2], x[4]},
            {x[3], x[5]},
            {x[4], x[5]},
            {x[6], x[4]},
            {x[7], x[5]},
            {x[0], x[6]},
            {x[1], x[7]},
            {x[6], x[7]},
        };
        for(Line &L:l){
            L.Draw(m);
        }
        show(m);
        clear_arr(m);
        napms(90);
    }
}