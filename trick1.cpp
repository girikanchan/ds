#include<iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 2;

    int c = a >> b;// a/b^b
    int d = a << b;//a*b^b
    
    cout << "Right Shift (a >> b): " << c << endl;
    cout << "Left Shift (a << b): " << d << endl;

    return 0;
}
