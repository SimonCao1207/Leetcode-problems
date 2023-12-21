#include<iostream>
#include <vector>

using namespace std;

/*
    https://leetcode.com/problems/network-delay-time/submissions/
*/

// Bellman–Ford algorithm  
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unsigned long long veryLargeNumber = 18446744073709551615ULL;
        int ans = -1; 
        double distance[n+1];
        for (int i=1; i<=n; i++){
            if (i!= k)
                distance[i] = veryLargeNumber;
        }
        distance[k] = 0;
        for (int i = 1; i <= n-1; i++){
            for (const auto& e : times){
                int src = e[0];
                int targ = e[1];
                int w = e[2];
                distance[targ] = min(distance[targ], distance[src] + w);
            }
        }
        
        for (const auto &v : distance){
            if (v == veryLargeNumber)
                return -1;
            ans = (v > ans) ? v : ans;
        }
        return ans;
    }
};


int main(){
    // vector<vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    // int n = 4, k = 2;

    // vector<vector<int>> times{{1,2,1}};
    // int n = 2, k = 2;

    // vector<vector<int>> times{{1,2,1}};
    // int n = 2, k = 1;

    vector<vector<int>> times{{1,2,1},{2,3,7},{1,3,4},{2,1,2}};
    int n = 3, k = 2;

    Solution s = Solution();
    cout << s.networkDelayTime(times, n, k);

}