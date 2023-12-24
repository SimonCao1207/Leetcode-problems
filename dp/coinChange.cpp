#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/*
    https://leetcode.com/problems/coin-change/submissions/
*/
// Classic DP problem

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for (int i=1; i<=amount; i++){
            dp[i] = INT_MAX-1;
            for (auto c: coins){
                if (i >= c)
                    dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
        return (dp[amount] == INT_MAX-1) ? -1 : dp[amount];
    }
};


int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    Solution s = Solution();
    int ans = s.coinChange(coins, amount);
    cout << ans << "\n";
}