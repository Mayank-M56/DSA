/*
Time Complexity : O(log n)
Space Complexity : O(log n) //Due to recursive function calls.

/*
Search in Rotated Sorted Array :

    Observation :
        -At least one half(left or right) is always sorted.
        -Target can be searched normally(Binary Search) if it lies inside sorted region.
        -Otherwise, target must exist in the other(rotated) region.

    Approach :
        -Find middle element.
        -Check whether left or right half is sorted.
        -If target belongs to sorted half, perform Binary Search there, Easy!
        -Otherwise recursively continue searching in the unsorted(rotated) half.
        -Repeat until target is found or search space becomes empty.
*/

#include<iostream>
#include<vector>
using namespace std;

int target;
int binarySearch(vector<int>& arr, int start, int end);
int LorR(vector<int>& arr, int start, int end);

int main() {
    vector<int> arr = {3, 4, 5, 6, 7, 0, 1, 2};
    int x;
    
    cout<< "what's the value want to search = ";
    cin>> target;
    
    int start = 0, end = arr.size()-1;
    x = LorR(arr, start, end);
    
    if(x == (-1)) {
        cout<< "Value didn't find.";
    } else {
        cout<< "Value available at " << x;
    }
    
    return 0;
}

int LorR(vector<int>& arr, int start, int end) {
    int mid = start+(end-start)/2;
    
    if(start > end) return -1; //element haven't found.
    
    if(arr[mid] == target) return mid; //mid is the target.
    
    if(arr[start] <= arr[mid]) { //left is sorted
        if(arr[start] <= target && target < arr[mid]) //target may exist in left region
            return binarySearch(arr, start, mid-1);
        else return LorR(arr, mid+1, end); //target cannot in left region
    } else { //right is sorted
        if(arr[mid] < target && target <= arr[end]) //target may exist in right region
            return binarySearch(arr, mid+1, end);
        else return LorR(arr, start, mid-1); //target cannot in right region
    }
}

int binarySearch(vector<int>& arr, int start, int end) {
    
    if(start > end) return -1;
    
    int mid = start+(end-start)/2;
    
    if(target < arr[mid]) {
        return binarySearch(arr, start, mid-1);
    } else if(target > arr[mid]) {
        return binarySearch(arr, mid+1, end);
    } else {
        return mid;
    }
}
