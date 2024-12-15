#include <iostream>
#include <vector>
#include <algorithm>

/*
SPOJ - RENT - Rent your airplane and make money
sorting, dynamic-programming, binary-search
*/

using namespace std;

struct Order {
    int start, end, price;
};

int find_last_non_conflicting(const vector<Order>& orders, int index) {
    int low = 0, high = index - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (orders[mid].end <= orders[index].start) {
            if (orders[mid + 1].end <= orders[index].start) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int get_max_profit(const vector<Order>& orders, int n) {
    vector<int> dp(n);

    dp[0] = orders[0].price;

    for (int i = 1; i < n; ++i) {
        int include_profit = orders[i].price;
        int last_non_conflicting = find_last_non_conflicting(orders, i);
        if (last_non_conflicting != -1) {
            include_profit += dp[last_non_conflicting];
        }

        int exclude_profit = dp[i - 1];

        dp[i] = max(include_profit, exclude_profit);
    }

    return dp[n - 1];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<Order> orders(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> orders[i].start >> orders[i].end >> orders[i].price;
            orders[i].end = orders[i].start + orders[i].end;
        }

        sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
            return a.end < b.end;
        });

        cout << get_max_profit(orders, n) << endl;
    }

    return 0;
}
