#include<iostream>
using namespace std;

int main(){
    int target;
    cin>> target;
    vector<int> dynamicArray;
    for(int i = 0;i<dynamicArray.size();i++){
        dynamicArray.push_back(i);
    }

    arridx(dynamicArray,target);

    print(dynamicArray);

    return 0;
}