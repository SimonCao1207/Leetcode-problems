#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/house-robber-ii/
*/

class Solution {
public:
    int rob1(vector<int>& nums) {
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
    
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> nums1;
        vector<int> nums2;
        for(int i=0; i<nums.size();i++){
            if (i==0) nums1.push_back(nums[i]);
            else if (i==nums.size()-1) nums2.push_back(nums[i]);
            else {
                nums1.push_back(nums[i]);
                nums2.push_back(nums[i]);
            }
        }
        return max(rob1(nums1), rob1(nums2));
    }
    
};