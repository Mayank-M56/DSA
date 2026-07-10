#include<iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int a = 5;
    int* ptr = &a;
    
    cout<< "address = " << ptr << "\naddress + 1 int = " << ptr+1 << endl; 
    cout<< ((ptr+1) == (++ptr)); // post/pre increment(or decrement) really change even in just checking condition while "ptr+1" don't affect the real variable if used in condition checking.

    --ptr;
    int* ptr1 = ptr+1;
    cout<< "\n\nvalue of ptr = " << ptr << "\nvalue of ptr1 = " << ptr1 << "\ndifference between two pointer = " << ptr1-ptr << endl; // difference between two consecutive int* pointers is 1 element, which equals sizeof(int) bytes (usually 4). 
    
    cout<< "address of array = " << arr << ", 2nd index = " << arr+1 << " and further index = " << arr+2; // array is pointer, no need "&" to get its address.
    
    return 0;
}   
