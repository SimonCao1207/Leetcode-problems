#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

unsigned long long veryLargeNumber = 18446744073709551615ULL;

/*
    https://leetcode.com/problems/network-delay-time/submissions/
*/

// Bellman–Ford algorithm O(nm)
class BellmanFord {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
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

// Dijkstra algorithm  O(n+mlog(m))
class Dijkstra {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = -1; 
        double distance[n+1];
        int visited[n+1]; 
        for (int i=1; i<=n; i++){
            visited[i] = -1;
            distance[i] = veryLargeNumber;
        }
        distance[k] = 0;
        priority_queue<pair<int, int>> q;

        vector<pair<int, int>> adj[n+1];
        for (const auto &e: times){
            int src = e[0];
            int targ = e[1];
            int w = e[2];
            adj[src].push_back({w, targ});
        }

        q.push({0, k});
        while (!q.empty()){
            int a = q.top().second; 
            q.pop();
            if (visited[a] == 1) continue;
            visited[a] = 1;
            for(auto u: adj[a]){
                int targ = u.second, w = u.first;
                if ( distance[a] + w < distance[targ]){
                    distance[targ] = distance[a] + w;
                    q.push({-distance[targ], targ});
                }
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

    // BellmanFord s = BellmanFord();
    Dijkstra s = Dijkstra();
    cout << s.networkDelayTime(times, n, k);
}