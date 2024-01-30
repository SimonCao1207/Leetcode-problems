#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/minimum-size-subarray-sum/description/
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int _size=INT32_MAX;
        int start=0, end=0, _sum=nums[end];
        while (end < nums.size()){
            if (_sum >= target){
                _size = min(end-start+1, _size);
                _sum -= nums[start++];
            }
            else {
                end ++;
                if (end < nums.size()){
                    _sum += nums[end];
                }
            }
        }
        return _size == INT32_MAX ? 0 : _size;
    }
};

int main(){
    vector<int> nums{2,3,1,2,4,3}; 
    int target = 7;
    // vector<int> nums{2,16,14,15};
    // int target = 20;
    Solution s = Solution();
    double ans = s.minSubArrayLen(target, nums);
    cout << ans << "\n";
}