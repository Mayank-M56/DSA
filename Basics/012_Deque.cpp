#include<iostream>
#include<deque> 
using namespace std;

// Same as Doubly Linked list but we can access element through index that is impossible with list.

int main() {
    deque<int> D1;
    int size, value;
    
    cout << "Enter the size of Deque : ";
    cin >> size;
    
    cout << "Enter the element : ";
    for(int i = 0; i < size; i++) {
        cin >> value;
        D1.push_back(value);
    }
    
    cout << "\nHere's the output : ";
    for(int val : D1) {
        cout << val << "\t";
    }
    
    D1.pop_back();
    D1.pop_front();
    D1.push_front(999);
    D1.push_back(999);
    
    cout << "\nHers's the updated output : ";
    for(int val : D1) {
        cout << val << "\t";
    }
    
    cout << "\nValue at 3rd Index : " << D1[3]; //We can access and perform operation direct through index.
    
    return 0;
}
