#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;


/*
    https://leetcode.com/problems/3sum/submissions/
*/

class Solution {
public:
    struct PairHash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_map<pair<int, int>, int, PairHash> umap;
    
        for (int i=0; i<n-2; i++){
            int l=i+1, r=n-1;
            while (l < r){
                int s = nums[l] + nums[r];
                pair<int, int> p(nums[i], nums[l]);
                if (s + nums[i] == 0 && umap[p] != 1){
                    umap[p] = 1; 
                    vector<int> v{nums[i], nums[l], nums[r]};
                    ans.push_back(v);
                    l++;
                }
                else if (s + nums[i] > 0) r--;
                else l++;
            }
            
        }
        return ans;
    }
};