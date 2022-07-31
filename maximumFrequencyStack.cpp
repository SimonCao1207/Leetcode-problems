#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class FreqStack {
public:
    unordered_map<int, int> counts;
    unordered_map<int, vector<int>> levels;
    int highest;
    FreqStack() {
        highest = 0;
    }
    
    void push(int val) {
        if (!counts.count(val)) counts[val] = 1;
        else counts[val]++;
        int l = counts[val];
        highest = max(highest, l);
        if (!levels.count(l)) levels[l] = {};
        levels[l].push_back(val);
    }
    
    int pop() {
        int popElem = levels[highest].back();
        levels[highest].pop_back();
        if (levels[highest].empty()) highest--;
        counts[popElem]--;
        return popElem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */