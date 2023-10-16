#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    int arr[n];
    std::cin>>n;
    int sum;
    int MaxSum = INT_MIN;

    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            for(int k = i;k<=j;k++){
                sum += arr[k];
            }
            MaxSum = max(MaxSum,sum);
        }
    }
    return 0;
}