
#include <iostream>

using namespace std;

int max(int x1, int x2, int x3)
{
    if(x1 > x2) {
    if(x1 > x3) return x1;
    else return x3;
    }
    else if(x2 > x3) return x2;
    else return x3;
}

int main()
{
    cout << endl << "!!!!!!!!!!!!!!!!!!" << endl;
    cout << "Hello ";

    return 0;
}
