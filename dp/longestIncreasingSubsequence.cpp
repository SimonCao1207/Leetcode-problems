#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    https://leetcode.com/problems/longest-increasing-subsequence/
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int k=0; k<n; k++){
            for (int i=0; i<k; i++){
                if (nums[i] < nums[k])
                    dp[k] = max(dp[k], dp[i] + 1);
            }
        }
        int ans = -1;
        for (auto v: dp){
            ans = max(v, ans);
        }
        return ans;

    }
};

int main(){
    // vector<int> nums{10,9,2,5,3,7,101,18};
    // vector<int> nums{7,7,7,7,7,7,7};
    // vector<int> nums{0,1,0,3,2,3};
    // vector<int> nums{4,10,4,3,8,9};
    vector<int> nums{1,3,6,7,9,4,10,5,6};

    Solution s = Solution();
    int ans = s.lengthOfLIS(nums);
    cout << ans << "\n";
}