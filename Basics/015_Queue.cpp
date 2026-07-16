#include<iostream>
#include<queue>
using namespace std;

// Queue : Based on FIFO structure. Imagine as Hollow Pipe. Functions are same as Stack.

int main() {
    queue<int> Q1;
    
    Q1.push(11);
    Q1.push(22);
    Q1.push(33);
    
    cout << "First Queue size : " << Q1.size() << endl;
    
    queue<int> Q2;
    
    Q2.swap(Q1);
    
    cout << "First Queue size after swap : " << Q1.size() << endl;
    cout << "\nSecond Queue :\n\tBefore delete : " << Q2.size() << endl << "\t";
    while(!Q2.empty()) {
        cout << Q2.front() << "\t";
        Q2.pop();
    }
    
    cout << "\n\tAfter delete : " << Q2.size();
    
    return 0;
}
