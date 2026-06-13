// Time complexity : O[n²]
// Check pair of shorted array's elements in such that their sum is equal to the given target. 
#include<iostream>
using namespace std;

int main() {
    int arr[8] = {2, 3, 5, 7, 9, 11, 16, 18};
    int target = 12;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i]+arr[j] == target) {
                cout<< "There is [" << i <<", " << j << "]" << endl;
            }
        }
    }
    
    return 0;
}
