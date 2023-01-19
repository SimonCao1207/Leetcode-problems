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
    int deleteAndEarn(vector<int>& nums) {
        int bucketSize = 1e5+1;
        vector<int> buckets(bucketSize, 0);
        for(int i=0; i<nums.size(); i++)
            buckets[nums[i]] += nums[i];
        
        /*
        take[i] : optimal value of first 0th->ith buckets while taking the ith bucket
        skip[i] : optimal value of first 0th->ith buckets while skipping the ith bucket
        */
        
        int take[bucketSize], skip[bucketSize];
        for (int i=0; i < bucketSize; i++){
            take[i] = i>0 ? skip[i-1] + buckets[i] : 0;
            skip[i] = i>0 ? max(take[i-1], skip[i-1]) : 0;
        }
        
        return max(take[bucketSize-1], skip[bucketSize-1]);
    }
};