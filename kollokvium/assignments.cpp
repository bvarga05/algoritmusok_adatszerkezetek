#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long dp[21][1 << 20]; 

long long count_assignments(int student, int n, int mask, const vector<vector<int> >& preferences) {
    if (student == n) return 1;

    if (dp[student][mask] != -1) return dp[student][mask];

    long long ways = 0;

    for (int topic = 0; topic < n; ++topic) {
        if (preferences[student][topic] == 1 && !(mask & (1 << topic))) {
            ways += count_assignments(student + 1, n, mask | (1 << topic), preferences);
        }
    }

    return dp[student][mask] = ways;
}

int main() {
    int c;
    cin >> c;
    int n;

    while (c--) {
        cin >> n;

        vector<vector<int> > preferences(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> preferences[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << count_assignments(0, n, 0, preferences) << endl;
    }

    return 0;
}
