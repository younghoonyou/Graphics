#include <iostream>
#include <cctype>
#include "figure.h"
#include <vector>
void show(std::vector<std::vector<char> > &m)
{
    for (int i = 59;i>=0;--i){
        for (int j = 0;j<120;++j){
            std::cout << m[i][j];
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

    std::vector<std::vector<char> > m(60, std::vector<char>(120, ' '));
    Point x1(0, 0),x2(0,40),x3(20,0),x4(20,40);
    Line l1(x1,x2),l2(x1,x3),l3(x2,x4),l4(x3,x4);
    l1.Draw(m);
    l2.Draw(m);
    l3.Draw(m);
    l4.Draw(m);
    show(m);
    return 0;
}