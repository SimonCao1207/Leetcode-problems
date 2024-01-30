#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int appear=0, i=0, ans=-1;
        int prev;
        for (auto x: nums){
            if (i==0) prev = x; 
            if (prev == x) appear++;
            else appear = 0; 
            prev = x; 
            i++;
            if (appear >= nums.size()/2)
                ans = x; 
        }
        return ans;     
    }
    
};

int main(){
    // vector<int> nums{3,2,3};
    vector<int> nums{2,2,1,1,1,2,2};
    Solution s = Solution();
    int ans = s.majorityElement(nums);
    cout << "Ans : " << ans << "\n";
}
