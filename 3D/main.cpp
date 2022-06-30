#include <iostream>
#include <cctype>
#include "figure.h"
#include <vector>
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
    // for (;;)
    // {
    //     c = _getch();                //입력값 input
    //     printf("입력 값 : %c\n", c); //입력값 출력
    // }

    std::vector<std::vector<char> > m(100, std::vector<char>(60, ' '));
    Point x1(0, 0),x2(20,0),x3(0,15),x4(20,15),x5(7,22),x6(27,22),x7(7,7),x8(27,7);
    Line l1(x1,x2),l2(x1,x3),l3(x2,x4),l4(x3,x4),l5(x3,x5),l6(x4,x6),l7(x5,x6),l8(x7,x5),l9(x8,x6),l10(x1,x7),l11(x2,x8),l12(x7,x8);
    l1.Draw(m);
    l2.Draw(m);
    l3.Draw(m);
    l4.Draw(m);
    l5.Draw(m);
    l6.Draw(m);
    l7.Draw(m);
    l8.Draw(m);
    l9.Draw(m);
    l10.Draw(m);
    l11.Draw(m);
    l12.Draw(m);
    show(m);
    return 0;
}