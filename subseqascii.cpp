#include <iostream>
using namespace std;

void subseq(string s, string ans) {
    // Base case: When the input string becomes empty, print the accumulated answer.
    if (s.length() == 0) {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    // Recursive calls to generate subsequences with and without the current character.
    subseq(ros, ans);       // Subsequence without the current character.
    subseq(ros, ans + ch);  // Subsequence with the current character.
    subseq(ros,ans+to_string(code));
}

int main() {
    subseq("ab", "");
    return 0;
}
