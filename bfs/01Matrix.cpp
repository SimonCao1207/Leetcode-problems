#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> p;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), cnt=0;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<p>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!mat[i][j]) q.push({i, j});
            }   
        }
        while (!q.empty()){
            int l = q.size();
            while (l--){
                p a = q.front();
                q.pop();
                int i = a.first, j = a.second;
                if (ans[i][j] != -1) continue;
                ans[i][j] = cnt;
                if (i>0 && mat[i-1][j] && ans[i-1][j] == -1) q.push({i-1, j});
                if (j>0 && mat[i][j-1] && ans[i][j-1] == -1) q.push({i, j-1});
                if (i+1<m && mat[i+1][j] && ans[i+1][j] == -1) q.push({i+1, j});
                if (j+1<n && mat[i][j+1] && ans[i][j+1] == -1) q.push({i, j+1});
            }
            cnt++;
        }
        return ans;  
    }
};