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
    int overLap(vector<int> &a, vector<int> &b){
        return (b[0] < a[1]) ? 1 : 0;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        int ans = 0, i = 1, j = 0;
        vector<vector<int>> tmp {intervals[0]}; 
        while (i < intervals.size()) {
            if (overLap(tmp[j], intervals[i])) { 
                i++; 
                ans ++; 
            }
            else {
                j++; 
                tmp.push_back(intervals[i]);
                i++;
            }
        }
        return ans; 
    }
};

int main() {
    vector<vector<int>> intervals {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    Solution s = Solution();
    int ans = s.eraseOverlapIntervals(intervals);
    cout << ans << "\n";
}