#include<iostream>
using namespace std;

int fripair(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return fripair(n-1)+ fripair(n-2)*(n-1);
}
int main(){

    cout<<fripair(4);
    return 0;
}