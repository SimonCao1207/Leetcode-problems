#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void print_vec(vector<int>& nums){
        for(auto &v: nums){
            cout << v << " ";
        }
    }
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        int ans=1, end=1, window_size=1;
        sort(nums.begin(), nums.end());
        print_vec(nums);
        while(end < nums.size()){
            if (nums[end] == nums[end-1]+1) {window_size++; end++; ans = max(window_size, ans);}
            else if (nums[end] == nums[end-1]) end++;
            else{
                window_size=1;
                end++;
            }
        }
        return ans;
    }
};