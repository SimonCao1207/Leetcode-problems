#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;


int partition(vector<int>& nums, int start, int end){
    int pivot = nums[end];
    int i = start-1;
    for (int j=start; j<end; j++){
        if (nums[j] < pivot){
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[end]);
    return i+1; 
}

void quickSort(vector<int>& nums, int start, int end){
    if (start < end) {
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot-1);        
        quickSort(nums, pivot+1, end);        
    }
}

int main(){
    vector<int> a{1,4,10,3,2,5,7,11,0};
    // vector<int> a{2,0,1};
    // vector<int> a{2,0,2,1,1,0};
    quickSort(a, 0, a.size()-1);
    for (auto &e: a)
        cout << e << " ";
    cout << "\n";
    return 0;
}