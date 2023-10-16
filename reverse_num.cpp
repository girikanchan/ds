#include<iostream>
using namespace std;
int main(){
    int a = 1234;
    int last;
    int rev= 0;

    while(a>0){
        int last = a%10;
        rev = rev*10+last;
        a = a/10;
    }
    cout<<rev;
    return 0;
}