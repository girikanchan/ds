#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int s;
    cin >> s;

    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    while (j < n && sum + arr[j] <= s) {
        sum += arr[j];
        j++;
    }
    if (sum == s) {
        cout << i + 1 << " " << j << endl;
    }
    while (j < n) {
        sum += arr[j];
        while (sum > s) {
            sum -= arr[i];
            i++;
        }
        if (sum == s) {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }
    if (st != -1) {
        cout << st << " " << en << endl;
    }
    else {
        cout << "No subarray found with the given sum." << endl;
    }
    return 0;
}
