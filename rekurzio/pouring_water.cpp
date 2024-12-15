#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <climits>
/*
POUR1 - Pouring water
recursion
*/

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int find_steps(int a, int b, int c, int current_a, int current_b, map<pair<int, int>, int>& memo) {
    if (current_a == c || current_b == c) 
        return 0;
    
    if (memo.find(make_pair(current_a, current_b)) != memo.end()) 
        return memo[make_pair(current_a, current_b)];

    memo[make_pair(current_a, current_b)] = -1;

    int min_steps = INT_MAX;

    if (current_a < a) {
        int steps = find_steps(a, b, c, a, current_b, memo);
        if (steps != -1) min_steps = min(min_steps, steps + 1);
    }

    if (current_b < b) {
        int steps = find_steps(a, b, c, current_a, b, memo);
        if (steps != -1) min_steps = min(min_steps, steps + 1);
    }

    if (current_a > 0) {
        int steps = find_steps(a, b, c, 0, current_b, memo);
        if (steps != -1) min_steps = min(min_steps, steps + 1);
    }

    if (current_b > 0) {
        int steps = find_steps(a, b, c, current_a, 0, memo);
        if (steps != -1) min_steps = min(min_steps, steps + 1);
    }

    int pour_to_b = min(current_a, b - current_b);
    if (pour_to_b > 0) {
        int steps = find_steps(a, b, c, current_a - pour_to_b, current_b + pour_to_b, memo);
        if (steps != -1) min_steps = min(min_steps, steps + 1);
    }

    int pour_to_a = min(current_b, a - current_a);
    if (pour_to_a > 0) {
        int steps = find_steps(a, b, c, current_a + pour_to_a, current_b - pour_to_a, memo);
        if (steps != -1) min_steps = min(min_steps, steps + 1);
    }

    memo[make_pair(current_a, current_b)] = (min_steps == INT_MAX) ? -1 : min_steps;

    return memo[make_pair(current_a, current_b)];
}

int solve(int a, int b, int c) {
    if (c > max(a, b) || c % gcd(a, b) != 0) 
        return -1;

    map<pair<int, int>, int> memo;
    return find_steps(a, b, c, 0, 0, memo);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }

    return 0;
}
