#include <iostream>
#include <string>
#include <vector>

/*
ACODE - Alphacode
dynamic-programming
*/

using namespace std;

long long count_decodings(const string& s) {
    int n = s.length();
    if (n == 0 || s[0] == '0') return 0;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        int two_digit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (two_digit >= 10 && two_digit <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    string input;
    while (true) {
        cin >> input;
        if (input == "0") break; 
        cout << count_decodings(input) << endl;
    }
    return 0;
}
