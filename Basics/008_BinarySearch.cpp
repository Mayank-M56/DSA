// Time Complexity : O[logn]
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end);

int main() {
    vector<int> arr;
    int n, target, x;
    
    cout<< "Enter the integer series = ";
    for(int i = 1; i <= 8; i++) {
        cin>> n;
        arr.push_back(n);
    }
    
    cout<< "what's the value want to search = ";
    cin>> target;
    
    int start = 0, end = arr.size()-1;
    x = binarySearch(arr, target, start, end);
    
    if(x == (-1)) {
        cout<< "Value not found.";
    } else {
        cout<< "value available at " << x <<endl;
    }

    system("pause");
    
    return 0;
}

int binarySearch(vector<int>& arr, int target, int start, int end) {
    
    int mid = start+(end-start)/2; // we can also write "mid = (start+end)/2", but it's not optimized for large value because when start and end tends to INT_MAX then adding both can lead to memory leakage.
    while(start <= end) {
        if(target < arr[mid]) { //Element available before mid, so Go Lower.
            return binarySearch(arr, target, start, mid-1);
        } else if(target > arr[mid]) { //Element available after mid, so Go Higher.
            return binarySearch(arr, target, mid+1, end);
        } else {
            return mid; //Found
        }
    }
    
    return -1; //Not Found
}
