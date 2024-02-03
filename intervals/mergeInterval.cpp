#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/merge-intervals/description/
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; 
        sort(intervals.begin(), intervals.end());
        for (auto v: intervals){
            if (ans.empty()) ans.push_back(v);
            else {
                vector<int> _v = ans.back();
                if (v[0] <= _v[1]){
                    ans.pop_back();
                    ans.push_back({_v[0], max(v[1], _v[1])});
                }
                else ans.push_back(v);
            }    
        }
        return ans; 
    }
};

int main(){
    vector<vector<int>> intervals {{1,4},{2,3},{8,10},{15,18}};
    Solution s = Solution();
    vector<vector<int>> ans = s.merge(intervals);
    for (auto v: ans){
        for(auto e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
}