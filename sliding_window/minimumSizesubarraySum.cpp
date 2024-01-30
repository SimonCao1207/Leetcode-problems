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
        int ans=0, _size=1;
        int start=0, end=0, _sum=0;
        while (_sum < target && end < nums.size()){
            _sum += nums[end];
            end++;
        }
        end--;
        if (_sum < target) return 0;
        _size = end-start+1;
        ans = _size;

        while (end < nums.size()){
            if (_sum >= target){
                ans = min(_size, ans);
                _sum -= nums[start];
                start++;
                _size --;
            }
            else {
                end ++;
                if (end < nums.size()){
                    _sum += nums[end];
                    _size++;
                }
            }

        }
        return ans;
    }
};

int main(){
    // vector<int> nums{2,3,1,2,4,3}; 
    // int target = 7;
    vector<int> nums{2,16,14,15};
    int target = 20;
    Solution s = Solution();
    double ans = s.minSubArrayLen(target, nums);
    cout << ans << "\n";
}