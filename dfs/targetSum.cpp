#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
using namespace std;

/*
    https://leetcode.com/problems/target-sum/description/
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int dp[n][2*total+1];
        memset(dp, 0, sizeof(dp));
        dp[0][nums[0]+total] = 1;
        dp[0][-nums[0]+total] += 1;
        for(int i=1; i<n; i++){
            for (int s=-total; s<=total; s++){
                if (s+nums[i] <= total)
                    dp[i][s+nums[i]+total] += dp[i-1][s+total];
                if (s-nums[i] >= -total)
                    dp[i][s-nums[i]+total] += dp[i-1][s+total];
            }
        }
        return (abs(target) <= total) ? dp[n-1][target+total] : 0;
    }
};