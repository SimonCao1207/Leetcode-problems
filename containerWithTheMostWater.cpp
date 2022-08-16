#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /* O(n)
            Two pointer algorithm
        */
        
        int m = 0, left = 0, right = height.size()-1;
        while (left<right){
            m = max(m, abs(right-left)*min(height[right], height[left]));
            if (height[right] < height[left]) right --;
            else left++;
        }
        return m;
    }
};