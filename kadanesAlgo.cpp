#include<iostream>
using namespace std;

int main(){
    int n,i;
    int arr[n];

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxsum = 0;
    int currsum;
    for(int i = 0;i<n;i++){
        currsum +=arr[i];
        if(currsum<0){
            currsum = 0;
        }
        maxsum = max(maxsum,currsum);

    }
    cout<<maxsum;
    return 0;
}