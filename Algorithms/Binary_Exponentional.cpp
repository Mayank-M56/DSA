/*
Time complexity : O[logn]

Overview :
    -This code efficiently computes x^n using Binary Exponentiation.
    -A regular approach multiplies x by itself n times, resulting in O(n) time complexity.
    -whereas below code time complexity is O(logn).

Binary Exponential :
    -Fact :
        -let 3^7 = 3*3*3*3*3*3*3 = 3* 3^2* 3^4, all are same.
    Approach :
        -We focuse on power, let 3^13, 1101(13).
        -Only the bits that are 1 contribute to the final answer. Bits that are 0 are ignored.
        -So 3^13 = (3 *3^4 *3^8)
            -1--->3^1 needed --> 3^1 = 3
            -2--->3^2 avoid --> (3^1 *3^1) = 9
            -4--->3^4 needed --> (3^2 *3^2) = 81
            -8--->3^8 needed --> (3^4 *3^4) = 6561
            -16-->3^16 avoid --> (3^8 *3^8) = 43,046,721
        -As we can observe that result is multiplication of itself, means we don't need to multiply one by one, just track and square it.
        -Thus, 3^13 is computed in only 4 iterations instead of 13.
*/

#include<iostream>
using namespace std;

long long power(long double x, int n); //"long long" value can be much higher.

int main() {
    int a, b;
    
    cout<< "Here a^b" << endl;
    cout<< "Enter the value as \"a\" = ";
    cin>> a;
    cout<< "Enter the value as \"b\" = ";
    cin>> b;
    
    cout << "Value of " << a << "^" << b << " is " << power(a, b) << endl;
    
    return 0;
}

long long power(long double x, int n) {
    long long result = 1; // "result" can be so long, thus "long long" is used.
    
    if(n < 0) { // If the exponent is negative, compute x^(-n) as (1/x)^n.
        x = 1/x;
        n = -n;
    }
        
    while(n > 0) { // "n" is value after losing right most bit. if integer value become 0, loop ends.
        if(n & 1) { // Allow only 1 by the help of comparing(&) with 1 directly. Let [1101(13) & 0001(1) = 1(true)]
            result *= x; // As we know 1 indicates power that must to be participate in result. but 0 won't.
        }
        x *= x; // We do this always regardless n is 0 or 1, because this will give x^1, then x^2, then x^4, then x^8 and so on. if we skip when n is 0 then we won't get proper x^2 series and we are preparing the next power.
        n >>= 1; // Do right shift, means binary value loses its last 1 bit, and resultant value will assign to n.
    }

    return result;
}
