#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/maximum-average-subarray-i/description/
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start = 0, end = k-1, m= INT32_MIN; 
        int _sum = 0;
        for (int i=start; i<=end; i++) _sum+=nums[i];
        while (end < nums.size()){
            if (_sum > m) m = _sum;
            end ++;
            start ++;
            _sum -= nums[start-1];
            if (end < nums.size()) _sum += nums[end];
        }
        double ans = double(m)/double(k);
        return ans; 
    }
};

int main(){
    vector<int> nums{1,12,-5,-6,50,3}; 
    int k = 4;
    Solution s = Solution();
    double ans = s.findMaxAverage(nums, k);
    cout << ans << "\n";

}