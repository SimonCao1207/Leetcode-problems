#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 1, right = n-2;
        while (left < right) {
            int mid = (left + right) / 2; 
            if (arr[mid] < arr[mid+1] && arr[mid] > arr[mid-1]) left = mid+1;
            else if (arr[mid] > arr[mid+1] && arr[mid] < arr[mid-1]) right = mid-1;
            else return mid;
        }
        return left;
    }
};

int main(){
    vector<int> arr {3,5,3,2,0};

    Solution s = Solution();
    int ans = s.peakIndexInMountainArray(arr);
    cout << ans << "\n";
}