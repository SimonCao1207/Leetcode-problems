#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    https://leetcode.com/problems/interval-list-intersections/description/
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int firstP = 0, secondP = 0; 
        while (firstP < firstList.size() && secondP < secondList.size()){
            vector<int> out = _intersection(firstList[firstP], secondList[secondP]);
            if (out[0] == -1){
                if (firstList[firstP][0]  < secondList[secondP][0]) 
                    firstP ++;
                else secondP ++;
                continue;
            } 
            ans.push_back(out);
            if (out[1] == secondList[secondP][1]) secondP ++;
            else if (out[1] == firstList[firstP][1]) firstP++; 
        } 
        return ans;
    }

    vector<int> _intersection(vector<int> firstIntv, vector<int> secondIntv){
        int a = max(firstIntv[0], secondIntv[0]);
        int b = min(firstIntv[1], secondIntv[1]);
        return (a <= b) ? vector<int> {a,b} : vector<int> {-1}; 
    }
};

int main(){
    vector<vector<int>> firstList {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondList {{1,5},{8,12},{15,24},{25,26}};
    Solution s = Solution();
    vector<vector<int>> ans = s.intervalIntersection(firstList, secondList);
    for (auto v: ans){
        for(auto e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
}