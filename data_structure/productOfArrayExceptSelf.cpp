#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans; 
        int n = nums.size();
        int prefix[n];
        int suffix[n];
        prefix[0] = 1; suffix[n-1] = 1;
        for (int i=1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];

        }
        for (int i=nums.size()-2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        for (int i=0; i<n; i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
    return ans;
    }
};

int main(){
    vector<int> nums {1,2,3,4};
    Solution s = Solution();
    vector<int> ans = s.productExceptSelf(nums);
    for (auto v: ans){
        cout << v << " ";
    }
    cout << "\n";
}