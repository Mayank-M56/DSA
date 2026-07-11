// Time Complexity : O[n²]
#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>& arr, int size);

int main() {
    vector<int> arr;
    int size, elements;
    
    cout << "Enter the size : ";
    cin >> size;
    
    cout << "Enter the elements : ";
    for(int i = 0; i < size; i++) {
        cin >> elements;
        arr.push_back(elements);
    }
    
    selection_sort(arr, size);
    
    cout << "Here's the sorted array : ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    
    return 0;
}

void selection_sort(vector<int>& arr, int size) {
    int smallest_Index;// stores smallest index of array that have smallest integer.
    
    for(int i = 0; i < size-1; i++) {
        smallest_Index = i; //let assume "i" index contain smaller integer.
        
        for(int j = i+1; j < size; j++) {
            if(arr[smallest_Index] > arr[j]) smallest_Index = j; //comparing with after "i"th index integer, if smaller integer detected then consider it as "smallest_Index";
        }
        
        swap(arr[i], arr[smallest_Index]); //now swap
    }
}
