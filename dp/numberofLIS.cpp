
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ln[n];  
        int cnt[n];
        for (int i=0; i<n; i++){
            ln[i] = cnt[i] = 1;
            for (int j=0; j<i ; j++){
                if (nums[i] > nums[j]){
                    if (ln[i] == ln[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                    else if (ln[i] < ln[j] + 1){
                        cnt[i] = cnt[j];
                        ln[i] = ln[j]+1;
                    }
                }
            }
        }
        int _max = 0, _maxPos = 0;
        while (_maxPos < n){
            if (ln[_maxPos] > _max) _max = ln[_maxPos];
            _maxPos ++;
        }
        int res = 0; 
        for (int i=0; i<n; i++){
            if (ln[i] == _max)
                res += cnt[i];
        }
        return res;   
    }
};


int main(){
    vector<int> nums {1,2,4,3,5,4,7,2};
    Solution s = Solution();
    int ans = s.findNumberOfLIS(nums);
    cout << ans << "\n";
}