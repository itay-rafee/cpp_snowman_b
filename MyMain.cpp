#include <iostream>
#include <stdexcept>
#include <math.h>
#include "snowman.hpp"

using namespace std;
// using namespace ariel;

int build_snowman(int num, int tav)
{
    int ans = 0;
    int len = 8;
    for (size_t i = 0; i < len; i++)
    {
        if (i + 1 != tav)
        {
            ans = ans + pow(10, i) * (rand() % 4 + 1);
        }
        else
        {
            ans = ans + pow(10, tav-1) * num;
        }
    }
    return ans;
}

int main()
{
    int n = 11111111;
    string s = ariel::snowman(n);
    cout << "n = " + to_string(n) + ":" << endl;
    cout << s << endl;

    n = 22222222;
    s = ariel::snowman(n);
    cout << "\nn = " + to_string(n) + ":" << endl;
    cout << s << endl;

    n = 33333333;
    s = ariel::snowman(n);
    cout << "\nn = " + to_string(n) + ":" << endl;
    cout << s << endl;

    n = 44444444;
    s = ariel::snowman(n);
    cout << "\nn = " + to_string(n) + ":" << endl;
    cout << s << endl;
    int j = 5;
    for (size_t i = 1; i < j; i++)
    {
        n = build_snowman(i,i);
        s = ariel::snowman(n);
        cout << "\nn = " + to_string(n) + ":" << endl;
        cout << s << endl;
    }

    return 0;
}
// g++ -o m snowman.cpp MyMain.cpp