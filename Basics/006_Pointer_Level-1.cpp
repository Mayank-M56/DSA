#include<iostream>
using namespace std;

void passBy(int* b); //we created a pointer, during call, an address will assign to it. consider as pass by address.

int main() {
    int arr[] = {10, 20, 30, 40, 50}; //an array is an pointer that have an address of "arr[0]" always. no need extra pointer.
    int a = 100;
    
    passBy(&a); //address of "a" is passed to function and then funtion directly performs its tasks to this address by dereferencing.
    
    int* ptr = NULL; // we shouldn't initialize empty pointer, to avoid random value address.
    ptr = &a; //declared a pointer with address of "a", means "ptr" has address of "a".
    int** PTR = &ptr; //we can't store the address of pointer variable in normal variable, it requires pointer variable.
    
    cout<< "1. address stored in pointer is " << ptr << endl;
    cout<< "2. value at address which is stored in pointer = " << *ptr << endl; // *ptr = *(&a) = a, means if we add * in "ptr" then we can get the value at address that is 100.
    cout<< "3. another pointer which is storing the address (as value) of our previous pointer, which is " << PTR << endl;
    cout<< "4. (value at address of )x2 which is stores ** pointer = " << **PTR << endl; 
    cout<< "5. value at first index of array is " << *arr << endl;
    
    return 0;
}

void passBy(int* b) {
    *b = 200; // now we are accessing the value of "a" throung *(dereferencing address that is assigned during call).
}
