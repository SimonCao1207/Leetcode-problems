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
    int lengthOfLongestSubstring(string s) {
        int ans = 0, cnt = 0, start = 0, end = 0;
        unordered_map<char, int> m;
        m.reserve(128);
        m.max_load_factor(0.25);
        while (end <= s.length()){
            ans = max(ans, cnt);
            if (end == s.length()) {ans = max(ans, cnt);break;};
            if (m.find(s[end]) == m.end()){
                // Not found
                m[s[end]] = end;
                cnt ++ ;
                end ++;
                continue;
            }
            else {
                // Found
                cnt = 0;
                start = m[s[end]] + 1;
                end = start;
                m.clear();
            }
        }
        return ans;
        
    }
};