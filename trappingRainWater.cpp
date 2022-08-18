#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        int mLeft=height[0];
        vector<int> maxRight(n, 0);
        vector<int> waterTrap;
        int mRight=height[n-1];
        int sum_of_elems;
        
        for (int i=0; i<n; i++){
            maxLeft[i] = mLeft;
            mLeft = max(mLeft, height[i]);
        }
        for (int i=n-1; i>=0; i--){
            maxRight[i] = mRight;
            mRight = max(mRight, height[i]);
        }
        for (int i=1; i<n-1; i++){
            int block = max(0, min(maxLeft[i], maxRight[i])-height[i]);
            waterTrap.push_back(block);
        }
        
        sum_of_elems = accumulate(waterTrap.begin(), waterTrap.end(), 0);
        
        return sum_of_elems;
    }
};