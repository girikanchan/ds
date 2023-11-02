#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i =2;i>=0;--i){
        cout<<arr[i];
    }
    return 0;
}