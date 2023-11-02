#include<iostream>
using namespace std;
int main(){
    int a = 10>20>5;
    int x = 057;//invalid octal number as adding 0 at the starting of any integer tells compiler that this number is octal number.
    //and octal number ranges from 0 to 7 and in 58 , 8 is not an octal number so gives an error.

    cout<<a<<endl;
    cout<<x;
    return 0;
}