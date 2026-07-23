/*
Time Complexity : O(log n)
Space Complexity : O(log n) //Due to recursive function calls.

Peak Element : Via Binary Search
    Observation :
        -Peak element is always greater than both of its neighbouring elements.
        -If current region is in increasing order, peak must exist on right side.
        -If current region is in decreasing order, peak must exist on left side.
        -Thus one half can be discarded in every iteration.
    Approach :
        -Find middle element.
        -If middle element is greater than both neighbours, then it is the peak.
        -Otherwise check whether current region is increasing or decreasing.
        -Continue searching only in the possible half.
        -Repeat until peak element is found.
*/
#include<iostream>
#include<vector>
using namespace std;

int searching(vector<int>& arr, int start, int end);

int main() {
    vector<int> arr = {0, 3, 8, 9, 5, 2};
    int x;
    
    int start = 0, end = arr.size()-1;
    x = searching(arr, start, end);
    
    if(x == (-1)) {
        cout<< "Invalid series.";
    } else {
        cout<< "Peak element at " << x;
    }
    
    return 0;
}

int searching(vector<int>& arr, int start, int end) {
    int mid = start+(end-start)/2;
    
    if(start == mid) return mid; //If there is one element then that element is the peak.
    
    if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) return mid; //If mid is greater than its neighbour element then mid is the answer like (1-9-1).
    else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) return searching(arr, mid+1, end); //Condition required increasing order like (1-5-9) where 5 is mid.
    else if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]) return searching(arr, start,  mid-1); //Condition required decreasins order like (9-5-1) where 5 is mid.
    
    return -1;
}
