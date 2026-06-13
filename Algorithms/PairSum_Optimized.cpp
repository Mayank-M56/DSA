// Time complexity : O[n]
// Check pair of shorted array's elements in such that their sum is equal to the given target. 
#include<iostream>
using namespace std;

void pairSum(int arr[], int x);

int main() {
    int arr[8] = {2, 3, 5, 7, 9, 11, 16, 18};
    int target = 12;
    
    pairSum(arr, target);
    
    return 0;
}

void pairSum(int arr[], int x) {
    int i = 0, j = 7; 
    while(i < j) { // "i <= j" -> NO, becuase we need pair, if i&j same means they are pointing at one element.
        if(arr[i]+arr[j] < x) { //if sum is less than target then need to choose higher value, as we know array is sorted.
            i++;
        } else if(arr[i]+arr[j] > x) { //if sum is more than target then need to choose lesser value.
            j--;
        }
        else { //if sum = target, then we won't stop, we may get more pair sum later.
            cout<< "There is [" << i <<", " << j << "]" << endl;
            j--;
            i++;
        }
    }
}
