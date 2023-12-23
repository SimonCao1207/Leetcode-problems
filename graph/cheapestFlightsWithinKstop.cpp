#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
unsigned long long veryLargeNumber = 18446744073709551615ULL;


/*
    https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/?envType=list&envId=53js48ke  
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        double dist[n];
        vector<pair<int, int>> adj[n];
        for (int i=0; i<n; i++){
            dist[i] = veryLargeNumber;
        }      
        dist[src] = 0;
        for (auto &f: flights){
            int from = f[0];
            int to = f[1];
            int w = f[2]; 
            adj[from].push_back({to, w});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({-1, {src, 0}}); 
        while (!q.empty()){
            auto front = q.front();
            int a = front.second.first; 
            int cost_so_far = front.second.second;
            int stop = front.first;
            q.pop();
            if (stop >= k) continue;
            for (auto u : adj[a]){
                int targ = u.first; 
                int w = u.second;
                if (cost_so_far + w < dist[targ] && stop + 1 <= k){
                    dist[targ] = cost_so_far + w;
                    q.push({stop+1, {targ, dist[targ]}});
                } 
            }
        }
        return (dist[dst] == veryLargeNumber) ? -1 : dist[dst];
    }
};

int main(){
    Solution s = Solution();
    // int n = 4;
    // vector<vector<int>> flights{{0,1,100},{1,2,100},{2,0,100},{1,3,600}, {2,3,200}};
    // int src = 0, dst = 3, k = 1;

    int n = 4;
    vector<vector<int>> flights{{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    int src = 0, dst = 3, k = 1;

    int ans = s.findCheapestPrice(n, flights, src, dst, k);
    cout << ans << "\n";
}