/*
Time Complexity : O(n)
Space Complexity : O(n)

Product of Array Except Self : Optimal Approach (Prefix & Suffix Product)
    Conditions :
        -Division is not allowed.
        -For every index, product should exclude its own element.

    Observation :
        -Required answer can be obtained by multiplying :
            1. Product of all elements on left side (Prefix).
            2. Product of all elements on right side (Suffix).

    Approach :
        -Store prefix product directly into result vector.
        -Then traverse from right side while maintaining suffix product.
        -Multiply current suffix with already stored prefix.
        -Eventually every index gets product of all elements except itself.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> product(vector<int>& x);

int main() {

    vector<int> series = {1, 2, 3, 4};

    vector<int> ans = product(series);

    cout << "Here's the product of given number with conditions : " << endl;

    for(int val : ans) {
        cout << val << "\t";
    }

    return 0;
}

vector<int> product(vector<int>& x) {
    vector<int> result(x.size(), 1); //Initially every index contains multiplicative identity (1).

    for(int i = 1; i < x.size(); i++) { //Stores product of every left side element (Prefix Product).
        result[i] = result[i-1] * x[i-1]; //"result[i-1]" already stores product of all previous elements.
                                          //Thus only previous element of "x" is missing to complete current prefix.
                                          //Ex- "result[7] = result[0*1*2*3*4*5] * x[6];" : now result[7]=result[0*1*2*3*4*5*6].
    }

    int suffix = 1; //Initially no element exists on right side.

    for(int i = x.size()-2; i >= 0; i--) { //Traverse from right to left, "x.size()-2" : begins from sencond from last, not last.
        suffix *= x[i+1]; //Initally had 1, then multiplied by "x[second from last]", then "x[thrird from last]"....so on.
        result[i] *= suffix; //Since we already had prifix in "result[]", need to add suffix. 
                             //Ex- "result[4] *= suffix(5*6*7*...);" where result[4] have (0*1*2*3 : prifix), means result[4] would be (0*1*2*3) * (5*6*7*...)
    }

    return result;
}
