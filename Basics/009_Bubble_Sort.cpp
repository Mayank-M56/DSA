// Time Complexity : O[n²]
#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int>& arr, int size);

int main() {
    vector<int> arr;
    int size, store;
    
    cout << "Enter the size of array : ";
    cin >> size;
    
    cout << "Enter element one by one : ";
    for(int i = 0; i < size; i++) {
        cin >> store;
        arr.push_back(store);
    }
    
    bubble_sort(arr, size);
    
    cout << "Sorted array : ";
    
    for(int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    
    return 0;
}

void bubble_sort(vector<int>& arr, int size) {
    int check = false; //for optimization, if we recieve already a sorted array then we should not perform remaining task.
    
    for(int i = 0; i < size-1; i++) { //outer loop to reallocate our first integer to its right location.
        for(int j = 0; j < size-i-1; j++) { // iterrates all index
            if(arr[j] > arr[j+1]) { // compare two consecutive index to check left one is greater or not.
                check = true; //if we found suspect then recieved array isn't sorted.
                swap(arr[j], arr[j+1]); //swap higher integer to right using inbuild swap function.
            }
        }
        if(!check) { //if we got sorted array then "check" won't true, so "!check" means false.
            cout << "Already Sorted." << endl;
            return;
        }
    }
}
