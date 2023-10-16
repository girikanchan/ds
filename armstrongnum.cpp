#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    int org =0;
    org = n;
    int sum = 0;
    cin>>n;
    while(n>0){
        int last = n%10;
        sum += pow(last,3);
        n = n/10;

    }
    cout<<sum;
    if (sum == org){
        cout<<"Am";
    }
    else{
        cout<<"nan";
    }
    
    return 0;
}
