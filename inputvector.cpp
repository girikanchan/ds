#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> v;
char c;
for(int i=0;;i++){
    cin>>c;
    if(c=='\n'){
        break;
    }
    int x = c - '0';// typecasting char into integer.
    v.push_back(x);
}
cout<<v.size()<<endl;// just to check if it is done taking input and what is the size of vector now.
}