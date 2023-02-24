
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int res;
        vector<int> v;
        for (int i=0; i<n; i++){
            v.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            int m = abs(v[i])-1;
            if (v[m] > 0) v[m] = -v[m];
            else res = m+1;
        }
        return res;
    }
};