#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Spiral order print

    int rs = 0, re = n - 1, cs = 0, ce = m - 1;

    while (rs <= re && cs <= ce) {
        // Print the top row
        for (int col = cs; col <= ce; col++) {
            cout << a[rs][col] << " ";
        }
        rs++;

        // Print the rightmost column
        for (int row = rs; row <= re; row++) {
            cout << a[row][ce] << " ";
        }
        ce--;

        // Print the bottom row (if there are rows left to print)
        if (rs <= re) {
            for (int col = ce; col >= cs; col--) {
                cout << a[re][col] << " ";
            }
            re--;
        }

        // Print the leftmost column (if there are columns left to print)
        if (cs <= ce) {
            for (int row = re; row >= rs; row--) {
                cout << a[row][cs] << " ";
            }
            cs++;
        }
    }

    return 0;
}
