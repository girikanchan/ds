#include<iostream>
using namespace std;

int main(){
    int n,i;
    

    cin>>n;
    int start,end;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int count = 0;
    for(int i = 0;i<n;i++){
        start = arr[i];
        end = arr[i+1];
        while (start + 1 < end) {
            count++;
            start++;
            }
        
    }
    cout<<count;
    return 0;
}