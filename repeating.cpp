#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n]; // Declare the array after inputting 'n'

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    const int N=1e6+2;
    int idx[N];

    for(int i = 0; i < N; i++) {
        idx[i] = -1;
    }
    int min_idx = INT_MAX; // Change INT_MIN to INT_MAX
    for (int i = 0; i < n; i++)
    {
        if(idx[arr[i]] != -1){ // Change a[i] to arr[i]
            min_idx = min(min_idx, idx[arr[i]]);
        }
        else{
            idx[arr[i]] = i;
        }
    }
    if (min_idx == INT_MAX)
    {
        cout << -1 << endl;
    } else {
        cout << min_idx + 1 << endl;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
