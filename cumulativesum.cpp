#include<iostream>
#include<climits>
using namespace std;

int main(){
    int i,n,arr[n];
    int cumSum[0];
    int cumsum[n+1];

    cin>>n;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 1;i<=n;i++){
        cumSum[i] += cumSum[i-1]+arr[i-1];
    }
    int maxsum = INT_MIN;
    for(int i = 1;i<=n;i++){
        int sum =0;
        for(int j=0;j<i;j++){
            sum = cumsum[i] - cumsum[j];
            maxsum = max(sum,maxsum);
        }
    }
    cout<<maxsum;

    return 0;
}