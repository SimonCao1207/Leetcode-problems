#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==1) return 1;
        int cur = nums.size()-2;
        int curGoodPos = nums.size()-1;
        while (cur>=0){
            if (nums[cur] >= curGoodPos - cur)  curGoodPos = cur;
            cur--;
        }
        return curGoodPos == 0;
    }
}; 