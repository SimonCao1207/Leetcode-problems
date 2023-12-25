#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    https://leetcode.com/problems/minimum-path-sum/
*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                dp[i][j] = grid[i][j];
                if (i > 0 && j > 0)
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                else if (i == 0 && j > 0)
                    dp[i][j] += dp[i][j-1];
                else if (j == 0 && i > 0)
                    dp[i][j] += dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    // vector<vector<int>> grid {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> grid {{1,2,3},{4,5,6}};
    Solution s = Solution();
    int ans = s.minPathSum(grid);
    cout << ans << "\n";
}