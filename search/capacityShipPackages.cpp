#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

/*
    https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

// Binary Search

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int mid, left=0, right=0;
        for (auto w: weights){
            left = max(left, w);
            right += w;
        }
        while (left < right){
            mid = (left + right) / 2;
            int sum = 0, num_day = 1, pos = 0;
            while (pos < n){
                sum += weights[pos];
                if (sum > mid) {
                    sum = 0;
                    num_day += 1;
                    continue;
                }
                pos ++;
            }
            if (num_day > days) left = mid+1;
            else right = mid;
        }
        return left;
    }
};

int main(){
    // vector<int> weights {1,2,3,4,5,6,7,8,9,10};
    // int days = 5;

    // vector<int> weights {3,2,2,4,1,4};
    // int days = 3;

    vector<int> weights {10,50,100,100,50,100,100,100};
    int days = 5;

    Solution s = Solution();
    int ans = s.shipWithinDays(weights, days);
    cout << ans << "\n";
}