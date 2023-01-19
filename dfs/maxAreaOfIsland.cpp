#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int isValid(vector<vector<int>>&grid, pair<int, int> p, set<pair<int,int>> visited){
        return (visited.find(p) == visited.end() && grid[p.first][p.second]);
    }
    
    int dfs(vector<vector<int>>& grid, pair<int, int> cur, set<pair<int, int>> visited){
        if (!isValid(grid, cur, visited)) return 0;
        stack<pair<int,int>> s;
        int ans=0, m = grid.size(), n = grid[0].size();
        s.push(cur);
        visited.insert(cur);
        while(!s.empty()){
            pair<int, int> sTop = s.top();
            int x = sTop.first, y = sTop.second;
            s.pop();
            ans += 1;
            pair<int, int> nextPoint;
            if ((x-1 >=0)){
                nextPoint = make_pair(x-1, y);
                if (isValid(grid, nextPoint, visited)) {s.push(nextPoint); visited.insert(nextPoint);}
            }
            if ((y-1 >=0)){
                nextPoint = make_pair(x, y-1);
                if (isValid(grid,  nextPoint, visited)) {s.push(nextPoint); visited.insert(nextPoint);}

            }
            if ((x+1 < m)){
                nextPoint = make_pair(x+1, y);
                if (isValid(grid, nextPoint, visited)) {s.push(nextPoint); visited.insert(nextPoint);}
            }
            if ((y+1 < n)){
                nextPoint = make_pair(x, y+1);
                if (isValid(grid, nextPoint, visited)) {s.push(nextPoint); visited.insert(nextPoint);}
            }
        }
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;
        int m = grid.size(), n = grid[0].size(), ans=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                pair<int, int> cur(i,j);
                int areaOfLand = dfs(grid, cur, visited);
                ans = max(ans, areaOfLand);
            }
        }
        return ans;
    }
};