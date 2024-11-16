#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> units = {1, 2, 5, 10, 20, 50};
    int max_value = 99;
    vector<int> dp(max_value + 1, max_value + 1); 
    dp[0] = 0; 
    for (int coin : units) {
        for (int value = coin; value <= max_value; value++) {
            dp[value] = min(dp[value], dp[value - coin] + 1);
        }}
    int total = 0;
    for (int value = 1; value <= max_value; value++) {
        total += dp[value];
    }
    double avg = total / static_cast<double>(max_value);
    cout << "average of unit: " << avg << endl;
    return 0;
}