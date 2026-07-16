#include<iostream>
#include<stack>
using namespace std;

// Stack : Based on LIFO structure.

int main() {
    stack<int> S1 ;
    
    S1.push(10); //placed at bottom.
    S1.emplace(20); //placed at middle.
    S1.push(30); //placed at top.
    
    cout << "Before delete : " << S1.size() << endl;
    
    while(!S1.empty()) { //.empty() tells stack size is 0 or not.
        cout << S1.top() << "\t"; //.top() uses to know element at top right now.
        S1.pop(); //.pop() uses to delete top most element.
    }
    
    cout << "\nAfter delete : " << S1.size() << endl;
    
    S1.push(10); //placed at bottom.
    S1.push(20); //placed at middle.
    S1.push(30); //placed at top.
    
    stack<int> S2;
    
    S2.swap(S1); //Shift all element of "S1" to "S2".
    
    cout << "Second Stack size : " << S2.size() << endl;
    while(!S2.empty()) {
        cout << S2.top() << "\t";
        S2.pop();
    }
    
    return 0;
}
