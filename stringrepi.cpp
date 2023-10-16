#include<iostream>
#include<string.h>
using namespace std;

void replacestr(string s){
    if(s.length() ==0){
        return;
    }
    if(s[0]=='p'&&s[1]=='i'){
        cout<<"3.14";
        replacestr(s.substr(2));
    }
    else{
        cout<<s[0];
        replacestr(s.substr(1));
    }
}
int main(){
    string s ="piisvcbhfjpi";
    replacestr(s);
}