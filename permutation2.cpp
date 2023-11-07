#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    vector<vector<int>> ans; // Create a vector to store permutations

    do {
        ans.push_back(a); // Store the current permutation in 'ans'
    } while(next_permutation(a.begin(), a.end()));

    for(auto v : ans){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
