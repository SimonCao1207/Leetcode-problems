#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
unsigned long long veryLargeNumber = 1e4+1;

/*
    https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/?envType=list&envId=53js48ke
*/
// Floyd–Warshall Algorithm

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unsigned long long dist[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = veryLargeNumber;
            }
        }
        for (int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            dist[a][b] = w;
            dist[b][a] = w;
        }
        for (int k=0; k<n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int nums[n];
        int ans=-1;
        unsigned long long m = veryLargeNumber;
        for (int i=0; i<n; i++){
            nums[i] = 0;
            for (int j=0; j<n; j++){
                if (dist[i][j] <= distanceThreshold && i!=j)
                    nums[i]++;
            }
            if (nums[i] < m)
                m = nums[i];
        }
        for (int i=n-1; i>=0; i--){
            if (nums[i] == m) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution s = Solution();
    int n = 5;
    vector<vector<int>> edges{{0,1,2},{0,4,8},{1,2,10000},{1,4,2},{2,3,10000},{3,4,1}}; 
    int distanceThreshold = 10000;

    double ans = s.findTheCity(n, edges, distanceThreshold);
    cout << ans << "\n";
}