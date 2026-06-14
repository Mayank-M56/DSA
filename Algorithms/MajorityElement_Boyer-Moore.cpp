/* Time complexity : O[n]

Majority element consider when frequency of an element is more than n/2, where n = size of array/vector.

Boyer-Moore approach : -> Upgrade frequency for same element and degrade for different element,
                       -> if frequency becomes 0 then update target element with current element, 
                       -> Eventually Majority element will give positive frequency.

Analogy : Imagine a room of players of football, cricket and BGMI(in majority),
          Same player type → support each other (freq++),
          Different player type → eliminate one vote (freq--),
          Majority group has more than half the room, so it can never be completely eliminated. */

#include<iostream>
using namespace std;

int main() {
    int arr[7] = {4, 4, 2, 4, 1, 4, 1};
    
    int freq = 0, ans = 0;
    for(int i = 0; i < 7; i++) {
        if(freq == 0) { // if frequency of element is 0 then choose new element as "ans".
            ans = arr[i];
            freq++;
        } else if(ans == arr[i]) { // if current element is same then increase frequency.
            freq++;
        } else { // if further element mismatches then decrease then frequency.
            freq--;
        }
    }
    
    cout<< "Majority element is " << ans;
    
    return 0;
}
