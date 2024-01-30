
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        q.push({0, 0});
        
        vector<vector<int>> ans;
        while(k-- && q.size()){
            pair<int, int> p = q.top(); q.pop();
            int idx1 = p.first, idx2 = p.second;
            vector<int> a{nums1[idx1], nums2[idx2]};
            ans.push_back(a);

            if (idx1+1 < nums1.size())
                q.push({idx1+1, idx2});
            if (idx1==0 && idx2+1 < nums2.size())
                q.push({idx1, idx2+1});
        }
        return ans;
    }
};

int main(){
    vector<int> nums1{-10,-4,0,0,6}; 
    vector<int> nums2{3,5,6,7,8,100}; 
    int k = 10;
    Solution s = Solution();
    vector<vector<int>> ans = s.kSmallestPairs(nums1, nums2, k);
    for(auto v: ans){
        for (auto x: v)
            cout << x << " ";
        cout << "\n";
    }
}