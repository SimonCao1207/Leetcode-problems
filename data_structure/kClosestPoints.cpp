#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/k-closest-points-to-origin/description/
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;};
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
        for (auto p: points){
            pair<int, int> x{p[0],p[1]};
            q.push(x);
            if (q.size() > k) q.pop();
        }
        vector<vector<int>> ans; 
        while (!q.empty()){
            pair<int, int> p = q.top(); q.pop();
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> points {{1,3},{-2,2}};
    int k=1;
    Solution s = Solution();
    vector<vector<int>> ans = s.kClosest(points, k);
    for (auto v : ans){
        for (auto e : v){
            cout << e << " ";
        }
        cout << "\n";
    }   
}