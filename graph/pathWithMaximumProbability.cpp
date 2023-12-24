#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
unsigned long long veryLargeNumber = 18446744073709551615ULL;

/*
    https://leetcode.com/problems/path-with-maximum-probability/submissions/?envType=list&envId=53js48ke
*/
//Dijkstra algorithm

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double dist[n];
        vector<pair<int,double>> adj[n];
        bool visited[n];
        for (int i=0; i<n; i++){
            dist[i] = -1;
            visited[i] = false;
        }
        dist[start_node] = 1;
        for (int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double w = succProb[i];
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        priority_queue<pair<double,int>> q;
        q.push({1, start_node});
        while (!q.empty()){
            auto front = q.top(); q.pop();
            int a = front.second;
            if (visited[a] == true) continue;
            visited[a] = true;
            for (auto u: adj[a]){
                int targ = u.first;
                double w = u.second;
                if (w*dist[a] > dist[targ]){
                    dist[targ] = w*dist[a];
                    q.push({dist[targ], targ});
                }
            }
        }
        return (dist[end_node] == -1) ? 0 : dist[end_node];
    }
};

int main(){
    Solution s = Solution();
    int n = 3;
    vector<vector<int>> edges{{0,1},{1,2},{0,2}}; 
    vector<double> succProb = {0.5,0.5,0.2};
    int start = 0, end = 2;

    double ans = s.maxProbability(n, edges, succProb, start, end);
    cout << ans << "\n";
}