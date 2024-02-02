#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/top-k-frequent-elements/description/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int freq[20000] = {0};
        for (auto num: nums){
            int _num = (num < 0) ? 20000 + num : num;
            freq[_num] ++;
        }
        auto cmp = [&freq](int a, int b){
            int _a = (a < 0) ? 20000 + a : a;
            int _b = (b < 0) ? 20000 + b : b;
            return freq[_a] > freq[_b]; 
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i=0; i<20000; i++){
            if (freq[i] > 0){
                int _i = (i >= 10000-1) ? i-20000 : i;
                q.push(_i);
                if (q.size() > k) q.pop();
            }
        }
        vector<int> ans;
        while (!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};

int main(){
    vector<int> nums {4,1,-1,2,-1,2,3};
    int k=2;
    Solution s = Solution();
    vector<int> ans = s.topKFrequent(nums, k);
    for (auto v: ans){
        cout << v << " ";
    }
    cout << "\n";
}