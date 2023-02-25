#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findMax(vector<int>& vec){
        int max = 0;
        for (auto num: vec){
            int k = abs(num);
            if (k > max) max = k;
        }
        return max;
    }

    int findNum(vector<int>& vec){
        if (!vec.size()) return -1;
        int m = findMax(vec);
        int a[m+1];
        int res = -1;
        fill_n(a, m+1, -1);
        for (int i=0; i<vec.size(); i++){
            int k = abs(vec[i]);
            a[k] = -a[k];
        }
        for (int i=0; i<m+1; i++){
            if (a[i] == 1) res = i;
        }
        return res;
    }

    int singleNumber(vector<int>& nums) {
        vector<int> pos_nums;
        vector<int> neg_nums;
        for (auto num: nums){
            if (num > 0) pos_nums.push_back(num);
            else neg_nums.push_back(num);
        }
        int pos_res = findNum(pos_nums);
        int neg_res = findNum(neg_nums);
        if (pos_res > 0) return pos_res;
        return -neg_res;
    }
};