/*
Time Complexity : O(log n)
Space Complexity : O(log n) //Due to recursive function calls.

Single Element in Sorted Array : Binary Search
    Conditions :
        -Array is sorted.
        -Every element appears exactly twice except one.

    Observation :
        -Twin elements always stay together, thus they always occupy even amount of spaces(2, 4, 6...).
        -Presence of Imposter breaks this pairing and make odd amount of spaces.

    Approach :
        -Find middle element.
        -If middle element doesn't match either neighbour, then it is the Imposter.
        -Otherwise check whether "mid" is even or odd and compare to its left element to pair-up.
        -Check if amount of spaces are in odd or even on left side to identify Imposter presence.
*/
#include<iostream>
#include<vector>
using namespace std;

int singleElement(vector<int>& arr, int start, int end);

int main() {
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 7, 7};
    int x;
    
    int start = 0, end = arr.size()-1;
    x = singleElement(arr, start, end);
    
    if(x == (-1)) cout<< "Invalid series.";
    else cout<< "Single element appeared at " << x;
    
    return 0;
}

int singleElement(vector<int>& arr, int start, int end) {
    int mid = start+(end-start)/2;
    
    if(start == end) return start; //Only one element in array.
    
    if(mid > 0 && mid < arr.size()-1) { 
        if(arr[mid-1] != arr[mid] && arr[mid+1] != arr[mid]) return mid; //mid is the Imposter because it neither matching to left nor to right.
    }
            
    if(mid%2 == 0) { //If mid is even, means even amount of wholeNumber are the left side of mid, Ex- mid=4 : (0, 1, 2, 3)Even.
        if(arr[mid] == arr[mid-1]) { //If mid's twin at left side then remaining wholeNumber on left side become in odd amount and that mean twins can't exist at odd spaces, thus Imposter must at left side.
            return singleElement(arr, start, mid-1); //Imposter among left.
        } else { //If Imoster not among right then must be in right.
            return singleElement(arr, mid+1, end); //Imposter among right.
        }
    } else if(mid%2 == 1) { //If mid is odd, means odd amount of wholeNumber are in the left side of mid, Ex- mid=5 : (0, 1, 2, 3, 4)Odd.
        if(arr[mid] == arr[mid-1]) { //If mid's twin at left side then remaining wholeNumber on left side become in even amount and that mean twins favorable spaces, so Imposter must at right side.
            return singleElement(arr, mid+1, end); //Imposter among right.
        } else { //If Imoster not among right then must be in left.
            return singleElement(arr, start, mid-1); //Imposter among left.
        }
    }
    
    return -1;
}
