// Time complexity : O[n]
/* Kadane's Algorithm says : Whenever sum of contiguous subarray element become negative,
                             then exclude that part,
                             but always track MaxSum so whenever result become 0 due to encountered higher negative vlaue,
                             result never lost. */

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int most = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++) { //Moving one by one elements.
        sum += arr[i]; //Adds them normally.
        most = max(sum, most); //Tracks MaxSum always.

        if (sum < 0) sum = 0; // Better to make it 0, if Summation become Negative.
    }

    cout << "Maximum sum of subarray is " << most;

    return 0;
}
