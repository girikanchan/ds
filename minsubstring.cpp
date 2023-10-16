#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n = str.size();
    cout<<str;
    cout<<n;
    cout<<endl;

    for(int i = 0; i<n;i++){
        for(int j = 0; j<=i;j++){
            cout<<str[j];
            
        }
        cout<<endl;
    }
    return 0;
}