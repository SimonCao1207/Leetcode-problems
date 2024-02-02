#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/task-scheduler/description/
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter[26] = {0};
        int _max = 0, maxCount = 0; 
        for (auto task: tasks){
            counter[task - 'A'] ++;
            if (_max == counter[task - 'A']){
                maxCount ++;
            }
            else if (_max < counter[task - 'A']){
                maxCount = 1;
                _max = counter[task - 'A']; 
            }
        }  
        int partCount = _max - 1;
        int N = tasks.size();
        int emptySlot = (n-maxCount+1)*partCount;
        int availableSlot = N - _max*maxCount;
        int idles = std::max(0, emptySlot - availableSlot);
        return N + idles;
    }
};

int main(){
    // vector<char> tasks{'A','A','A','B','B','B'}; 
    // int n = 2;
    vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'}; 
    int n = 2;
    Solution s = Solution();
    int ans = s.leastInterval(tasks, n);
    cout << ans << "\n";
}