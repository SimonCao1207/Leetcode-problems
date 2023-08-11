#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;


/*
    https://leetcode.com/problems/3sum-closest/description/
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int curMin = 1e5+1, ans; 
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++){
            int l=i+1, r=n-1;
            while (l<r){
                int s = nums[l] + nums[r] + nums[i] - target;
                if (s == 0){
                    ans = target;
                    break;
                }
                else if (abs(s) < curMin){
                    ans = nums[l] + nums[r] + nums[i];
                    curMin = abs(s);
                }
                if (s < 0) l++;
                else if (s > 0) r--; 
            }
        }
        return ans;
    }
};