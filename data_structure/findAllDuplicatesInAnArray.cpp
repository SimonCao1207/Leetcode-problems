#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
 
/*
    https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i=0; i < n; i++) {
            while (nums[nums[i]-1] != nums[i]){
               int tmp = nums[i];
               nums[i] = nums[tmp-1]; 
               nums[tmp-1] = tmp; 
            }
        }
        for (int i=0; i<n; i++){
            if (nums[i] != i+1){
                ans.push_back(nums[i]);
            }
        }
        return ans; 
    }
};


int main(){
    vector<int> nums {4,3,2,7,8,2,3,1};
    Solution s = Solution();
    vector<int> ans = s.findDuplicates(nums);
    for (auto v: ans){
        cout << v << " ";
    }
    cout << "\n";
}