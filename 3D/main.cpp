#include <iostream>
#include <cctype>
#include "figure.h"
#include <vector>
#include <thread>
#include <string.h>
#include <unistd.h>
void show(std::vector<std::vector<char> > &m)
{
    for (int i = 59;i>=0;--i){
        for (int j = 0;j<100;++j){
            std::cout << m[j][i]<<' ';
        }
        std::cout << '\n';
    }
}
int main(int argc, char **argv){
    // if (argc != 2 || !isdigit(*argv[argc - 1]) || (*argv[argc - 1] - '0') <= 2 || (*argv[argc - 1] - '0') > 6)
    // {
    //     std::cout << "Just Input 3 ~ 6 Number";
    //     return 0;
    // }
    std::cout.tie(0), std::ios_base::sync_with_stdio(false);
    // int num = *argv[argc - 1] - '0';
    std::vector<std::vector<char> > m(100, std::vector<char>(60, ' '));
    Point x1(0, 0, 0), x2(20, 0, 0), x3(0, 15, 0), x4(20, 15, 0), x5(0, 15, 10), x6(20, 15, 10), x7(0, 0, 10), x8(20, 0, 10);
    // std::cout << x6.x << ' ' << x6.y << ' ' << x6.z << '\n';
    // x6.Y_Rotate(10);
    // std::cout << x6.x << ' ' << x6.y << ' '   << x6.z << '\n';
    // x3.X_Rotate(180);
    // x4.X_Rotate(180);
    // x5.X_Rotate(180);
    // x6.X_Rotate(180);
    // x7.X_Rotate(180);
    // x8.X_Rotate(180);
    // Line l1(x1, x2);


    std::cout << x1.x << ' ' << x1.y << ' ' << x1.z << '\n';
    std::cout << x2.x << ' ' << x2.y << ' ' << x2.z << '\n';
    std::cout << x3.x << ' ' << x3.y << ' ' << x3.z << '\n';
    std::cout << x4.x << ' ' << x4.y << ' ' << x4.z << '\n';
    std::cout << '\n'
              << '\n';
    x1.Z_Rotate(90);
    x2.Z_Rotate(90);
    x3.Z_Rotate(90);
    x4.Z_Rotate(90);
    Line l1(x1, x2), l2(x1, x3), l3(x2, x4), l4(x3, x4), l5(x3, x5), l6(x4, x6), l7(x5, x6), l8(x7, x5), l9(x8, x6), l10(x1, x7), l11(x2, x8), l12(x7, x8);
    // l1.Draw(m);

    // l1.Draw(m);
    // l2.Draw(m);
    // l3.Draw(m);
    // l4.Draw(m);

    // x1.Z_Rotate(90);
    // x2.Z_Rotate(90);
    // x3.Z_Rotate(90);
    // x4.Z_Rotate(90);
    // l1 = {x1, x2};
    // l2 = {x1, x3};
    // l3 = {x2, x4};
    // l4 = {x3, x4};


    l1.Draw(m);
    l2.Draw(m);
    l3.Draw(m);
    l4.Draw(m);
    // l5.Draw(m);
    // l6.Draw(m);
    // l7.Draw(m);
    // l8.Draw(m);
    // l9.Draw(m);
    // l10.Draw(m);
    // l11.Draw(m);
    // l12.Draw(m);
    // thread t1();
    // thread t2();
    // t1.join();
    // t2.join();
    show(m);
    return 0;
}