#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int knapsack(vector<int> weight, vector<int> profit, int W){
    // Return maximum profit
    
    int n = weight.size();
    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
    for (int i=1; i<=n; i++){
        for (int w=0; w<=W; w++){
            if (w < weight[i-1])
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i-1]] + profit[i-1]);
        }
    }

    return dp[n][W];
}

int main(){
    vector<int> profit{55, 10, 47, 5, 4, 50, 8, 61, 85, 87};
    vector<int> weight{95, 4, 60, 32, 23, 72, 80, 62, 65, 46};
    int W = 269;
    int ans = 295; 

    // vector<int> profit{44, 46, 90, 72, 91, 40, 75, 35, 8, 54, 78, 40, 77, 15, 61, 17, 75, 29, 75, 63};
    // vector<int> weight{92, 4, 43, 83, 84, 68, 92, 82, 6, 44, 32, 18, 56, 83, 25, 96, 70, 48, 14, 58};
    // int W = 878;
    // int ans = 1024; 

    cout << knapsack(weight, profit, W) << " == "<< ans << "\n";
}