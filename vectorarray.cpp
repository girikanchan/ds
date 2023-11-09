#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
//1st method
    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    //2nd method
    vector<int>::iterator it;
    for(it = v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
//3rd method
    for(auto element:v){
        cout<<element<<endl;
    }

    return 0;
}