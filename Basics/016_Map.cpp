#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string, int> M1;
    
    M1["TV"] = 100;
    M1["Camera"] = 150;
    M1["Laptop"] = 200;

    for(auto val : M1) {
        cout << val.first << "\t" << val.second << endl;
    }

    return 0;
}
