#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int max_so_far = 0;
        for (int i=0; i<prices.size(); i++){
            if (prices[i] < min_so_far) min_so_far = prices[i];
            else max_so_far = max(max_so_far, prices[i] - min_so_far);
        }
        return max_so_far;
    }
};