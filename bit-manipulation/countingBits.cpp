#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i=0; i<=n; i++){
            int cnt = 0;
            for(int j=0; j<sizeof(int)*8; j++){
                if (i & (1<<j)) cnt ++;
            }        
            ans.push_back(cnt);
        }
        return ans;
    }
};