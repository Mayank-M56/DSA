// Time complexity : O[n²]
//Maximum sun of sub array means continious array elements, not random, and maximum resultant of certain subarray will be the winner.
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int yolo[7] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(yolo)/sizeof(yolo[0]); //if 1000kg weight of human floating in vaccum and each of them weight is 100kg then : 1000kg/100kg = 10 Human.
    
    int maximum = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += yolo[j];
            maximum = max(sum, maximum); //"max()" gives larger value among in it.
        }
    }
    
    cout<< "Maximum sum of subarray can be " << maximum;
    
    return 0;
}
