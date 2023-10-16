#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int N = 1e6 + 2;
    bool check[N];

    for (int i = 0; i < N; i++) {
        check[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && a[i] < N) { // Make sure a[i] is within bounds.
            check[a[i]] = 1;
        }
    }

    int ans = -1;

    for (int i = 1; i < N; i++) {
        if (check[i] == false) {
            ans = i;
            break;
        }
    }

    if (ans == -1) {
        ans = N; // If all positive integers are present, set ans to N.
    }

    cout << ans;

    return 0;
}
