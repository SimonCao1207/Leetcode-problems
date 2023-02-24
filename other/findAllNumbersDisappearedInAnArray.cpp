#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


/*
O(1) extra space and in O(n) runtime.
May assume the returned list does not count as extra space.
*/ 

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> res;
        for (int i=0; i<n; i++){
            int m = abs(nums[i])-1;
            if (nums[m] > 0) nums[m] = -nums[m];
        }
        for (int i=0; i<n; i++){
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};