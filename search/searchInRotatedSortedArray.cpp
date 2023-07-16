#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
source: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
Other idea : https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/14435/clever-idea-making-it-simple/
If nums[mid] and target are "on the same side" of nums[0], we just take nums[mid]. Otherwise we use -infinity or +infinity as needed.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int _size = nums.size();
        int start=0, end=_size-1;
        while (start < end){
            int mid = (start+end)/2;
            if (nums[mid] > nums[end])
                start = mid+1;
            else 
                end = mid;
        }
        int k = start;
        start = 0, end = _size-1;
        int pos=-1;
        while(start<=end){
            int mid = (start+end)/2;
            int cmp =  (mid+k) < _size ? mid+k : mid+k-_size;
            if (target == nums[cmp]){
                pos = cmp;
                break;
            }
            if (target < nums[cmp])
                end = mid-1;
            else 
                start = mid+1;
        }
        return pos;

    }
};

/*
In :
7
4 5 6 7 0 1 2
0
1
1
0
Out: 
4
-1
*/

int main(){
    Solution s;
    while (1) {
        vector<int> nums;
        int size, target; cin>>size;
        if (size==-1) break;
        while (size--){
            int _n;
            cin >> _n;
            nums.push_back(_n);
        }
        cin >> target;
        int ans = s.search(nums, target);
        cout << ans << "\n";
    }
    
}