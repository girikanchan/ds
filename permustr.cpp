#include<iostream>
using namespace std;

void perstr(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i = 0; i<s.length();i++){
        char ch = s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        
        perstr(ros,ans+ch);
    }
}
int main(){

    perstr("abc","");
    return 0;
}