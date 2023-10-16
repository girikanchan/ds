#include<iostream>
#include<string.h>

std::string movex(std::string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    std::string ans = movex(s.substr(1));
    if(ch == 'x'){
        return (ans+ch);
    }
    return (ch+ans);
}
int main(){
    std::cout<<movex("agxhjhfxxhdhfd");
    return 0;
}