#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n]; // Declare the array after inputting 'n'
    int diff = 2;
    int curr = 2;
    int ans = 2; // Initialize ans to a suitable initial value

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++) { // Note: Loop until n-1 to avoid accessing arr[i+1] out of bounds
        if (diff == arr[i + 1] - arr[i]) {
            curr++;
        } else {
            diff = arr[i + 1] - arr[i];
            curr = 2;
        }
        ans = max(ans, curr);
    }

    cout << ans;
    return 0;
}
