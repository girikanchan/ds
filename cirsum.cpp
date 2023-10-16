#include<iostream>
using namespace std;

int kadane(int arr[],int n){
    int maxsum = 0;
    int currsum;
    for(int i = 0;i<n;i++){
        currsum +=arr[i];
        if(currsum<0){
            currsum = 0;
        }
        maxsum = max(maxsum,currsum);

    }
    return maxsum;
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int wrapsum;
    int nonwrap;

    nonwrap = kadane(arr,n);

    int total = 0;

    for(int i=0;i<n;i++){
        total += arr[i];
        arr[i] =-arr[i];
    }
    wrapsum = total + kadane(arr,n);
    cout<<max(wrapsum,nonwrap)<<endl;
    return 0;
}