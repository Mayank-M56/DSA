// Time complexity : O[n logn]
// Majority element consider when frequency of an element is more than n/2, where n = size of array/vector.
// Optimize approach : Sort array -> Counting will be easy for each element -> Get the Result when certain element frequency exceeded n/2
#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[7] = {4, 4, 2, 4, 1, 4, 1};
    
    sort(arr, arr+7); //sort() helps to sort array/vector.
    // Array is now sorted {1, 1, 2, 4, 4, 4, 4}
    
    int n = 7/2;
    int freq = 0;
    int ans = arr[0]; // Begins with first target.
    
    for(int i = 0; i < 7; i++) {
        if(ans == arr[i]) {
            freq++; // if iterated element matched to target then upgrade frequency.
        } else { // means new target faces, so iterated element becomes new target and frequency should reset.
            ans = arr[i];
            freq = 1;
        }
        
        if(freq > n) { //Found
            cout<< "Majority element is " << arr[i];
            break;
        }
    }
    
    return 0;
}
