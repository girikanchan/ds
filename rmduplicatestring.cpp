#include<iostream>
#include<string.h>
using namespace std;

string rmdup(string s){
    if(s.length == 0){
        return "";
    }
    char ch = s[0];
    string ans = rmdup(s.substr(1));

    if(ch == ans[0]){
        return ans;
    }
    return (ch+ans);
}
int main(){
    rmdupl();
    return 0;
}