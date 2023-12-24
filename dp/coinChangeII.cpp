#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    https://leetcode.com/problems/coin-change-ii/
*/
// Classic DP problem

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (auto c: coins){
            for (int i=1; i<=amount; i++){
                if (i-c>=0)
                    dp[i] += dp[i-c];
            }
        }
        return dp[amount];
    }
};

int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;
    Solution s = Solution();
    int ans = s.change(amount, coins);
    cout << ans << "\n";
}