#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> p;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=-1, fresh=0;
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
        queue<p> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                p qFront = q.front();
                q.pop();
                int x = qFront.first, y = qFront.second;
                for (int i=0; i<4; i++){
                    int newX = dir[i][0] + x,  newY = dir[i][1] + y;
                    if (newX >= 0 && newY >=0 && newX < grid.size() && newY < grid[0].size())
                    if (grid[newX][newY] == 1) {
                        q.push({newX, newY});
                        grid[newX][newY] = 2;
                        fresh--;
                    }
                }
            }
            ans ++;
        }
        if (fresh > 0) return -1;
        if (ans == -1) return 0;        
        return ans;
    }
};