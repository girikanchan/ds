#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    for(int i =0;i<n;i++){
        count++;
    }
    cout<<count;
    return 0;
}