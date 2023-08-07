#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
https://leetcode.com/problems/subarray-product-less-than-k/description/
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0, r=0, prod=1;
        int n = nums.size();
        int ans=0;
        while (l<n){
            prod = (l>0) ? max(1, (int) (prod/nums[l-1])) : 1;
            r = max(l,r);
            while (r<n && prod*nums[r] < k){
                prod *= nums[r];
                r+=1;
            }
            ans += r-l;
            l+=1; 
        }
        return ans;
    }
};

