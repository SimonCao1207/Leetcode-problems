#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), dp[nums.size()];
        if (n==1) return nums[n-1];
        if (n==2) return max(nums[n-1], nums[n-2]);
        for(int i=0; i<nums.size(); i++){
            if (i==0 || i==1){
                dp[i] = nums[i];
            }
            else {
                int cnt = i-2; 
                dp[i] = dp[i-1];
                while (cnt >= 0){
                    dp[i] = max(dp[i], dp[cnt] + nums[i]);
                    cnt--;
                }
            }
        }
        return max(dp[n-2], dp[n-1]);
    }
};