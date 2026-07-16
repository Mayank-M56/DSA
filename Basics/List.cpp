#include<iostream>
#include<list> 
using namespace std;

//This is a Doubly Linked List, where we can perform operation on elements from front as well as back. but we can't perform any operation through index. rest operation is same as vector.

int main() {
    list<int> L1;
    int size, value;
    
    cout << "Enter the size of list : ";
    cin >> size;
    
    cout << "Enter the element : ";
    for(int i = 0; i < size; i++) {
        cin >> value;
        L1.push_back(value);
    }
    
    cout << "\nHere's the output : ";
    for(int val : L1) {
        cout << val << "\t";
    }
    
    L1.pop_back();
    L1.pop_front();
    L1.push_front(999);
    L1.push_back(999);
    
    cout << "\nHers's the updated output : ";
    for(int val : L1) {
        cout << val << "\t";
    }
    
    //cout << "\nValue at 3rd Index : " << L1[3]; //Gives Error.
    
    return 0;
}
