#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        pair<int,int> cur(sr,sc);
        stack<pair<int, int>> s;
        s.push(cur);
        int oldColor = image[sr][sc], nRow = image.size(), nCol = image[0].size();
        while (!s.empty()){
            pair<int, int> sTop = s.top();
            s.pop();
            int x = sTop.first, y = sTop.second;
            image[x][y] = color;
            if ((x-1 >= 0) && (image[x-1][y] == oldColor)) s.push(make_pair(x-1, y));
            if ((y-1 >= 0) && (image[x][y-1] == oldColor)) s.push(make_pair(x, y-1));
            if ((x+1 < nRow) && (image[x+1][y] == oldColor)) s.push(make_pair(x+1, y));
            if ((y+1 < nCol) && (image[x][y+1] == oldColor)) s.push(make_pair(x, y+1));
        }
        return image;
    }
};