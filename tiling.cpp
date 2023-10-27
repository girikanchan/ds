#include<iostream>
using namespace std;
int trailing(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return trailing(n-1)+trailing(n-2);
}
int main(){
    cout<<trailing(4);

    return 0;
}