#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/insert-interval/description/
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto pos = lower_bound(intervals.begin(), intervals.end(), newInterval);
        vector<vector<int>> ans;
        bool flag = false;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        if (pos == intervals.end()){
            for (auto i = intervals.begin(); i < intervals.end(); i++){
                if (i == pos-1){
                    if (isOverlap(intervals[i-intervals.begin()], newInterval))
                        ans.push_back(mergeInterval(intervals[i-intervals.begin()], newInterval));
                    else {
                        ans.push_back(intervals[i-intervals.begin()]);
                        ans.push_back(newInterval);
                    }
                } 
                else ans.push_back(intervals[i-intervals.begin()]);
            }
            return ans;
        }
        for (auto i = intervals.begin(); i < intervals.end(); i++){
            if (i == pos){
                vector<int> tmp = (ans.empty()) ? intervals[i-intervals.begin()] : ans.back();
                if (isOverlap(tmp, newInterval)){
                    if (!ans.empty()) ans.pop_back();
                    ans.push_back(mergeInterval(tmp, newInterval));
                    flag = true;
                } else {
                    ans.push_back(newInterval);
                    if (isOverlap(intervals[i-intervals.begin()], newInterval)){
                        ans.pop_back();
                        ans.push_back(mergeInterval(intervals[i-intervals.begin()], newInterval));
                        flag = true;
                    }
                }
            } 
            
            if (flag) { 
                if (isOverlap(intervals[i-intervals.begin()], ans.back())){
                    vector<int> cur = ans.back();
                    ans.pop_back();
                    ans.push_back(mergeInterval(intervals[i-intervals.begin()], cur));
                }
                else {
                    flag = false;
                    ans.push_back(intervals[i-intervals.begin()]);
                }
            } else ans.push_back(intervals[i-intervals.begin()]);
        }
        return ans;
    }

    vector<int> mergeInterval(vector<int>& a, vector<int>& b){
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
    
    bool isOverlap(vector<int>& a, vector<int> b){
        return (a[0] <= b[0]) ? (b[0] <= a[1]) : (a[0] <= b[1]);
    }
};

int main(){
    vector<vector<int>> intervals {{0,5}, {9,12}};
    vector<int> newInterval {{7,16}};
    Solution s = Solution();
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for (auto v: ans){
        for(auto e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
}