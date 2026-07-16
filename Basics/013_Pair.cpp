#include<iostream>
#include<vector>
using namespace std;

int main() {
    pair<string, int> P1 = {"Mayank", 20}; //input can be different datatype. And no need to include any module.
    
    cout << P1.first << endl; //Accessing first data.
    cout << P1.second << endl; //Accessing second data.
    
    cout << "\nAnother Example : " << endl;
    pair<int, pair<string, float>> P2 = {100, {"Mohit", 6.9}}; //even pair consider as datatype.
    
    cout << P2.first << endl;
    cout << P2.second.first << endl;
    cout << P2.second.second << endl;
    
    //Pair in Vector
    
    cout << "\nPair in Vector :\n"; 
    vector<pair<int, int>> V1 = {{1, 2}, {10, 20}, {100, 200}};
    
    V1.push_back({1000, 2000}); //push_back() need pair.
    V1.emplace_back(999, 1999); //emplace_back() creates pair, we just need to pass the value. It is faster than push_back().
    
    for(pair<int, int> val : V1) { //we can replace "pair<int, int>" with "auto".
        cout << val.first << "\t" << val.second << endl;
    }
    
    return 0;
}
