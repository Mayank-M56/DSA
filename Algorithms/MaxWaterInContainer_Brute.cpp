/*
Brute Force
Time Complexity : O(n²)
Space Complexity : O(1) excluding "track", otherwise O(2) ≈ O(1)

Container With Most Water :
    Approach :
        -Consider every possible pair of lines.
        -Area depends on :
            1. Smaller height among both lines.
            2. Distance(width) between them.
        -Calculate area of every pair.
        -Whenever greater area found, update result and remember that pair.
*/
#include<iostream>
#include<vector>
using namespace std;

int maxSize(vector<int>& heights, vector<int>& track);

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> track; //Stores heights of line pair giving maximum area.

    int result = maxSize(heights, track);

    cout << "Max water in container can be possible if pair is ("
         << track[0] << ", " << track[1]
         << "), and Area would be : " << result;

    return 0;
}

int maxSize(vector<int>& heights, vector<int>& track) {
    int size = heights.size(); //Size of vector.
    int result = 0; //Stores maximum area found till now.
    int temp; //Stores current pair's area.

    for(int i = 0; i < size; i++) { //Begins with left most indice.
        for(int j = i+1; j < size; j++) { //Compare current line with every line after it. No need to compare previous indices because those pairs are already checked.
            temp = min(heights[i], heights[j]) * (j-i); //Container height depends on shorter line. Width is simply difference between both indices "(j-i)".

            if(result < temp) { //If current pair gives larger area then update answer.
                result = temp;
                track.clear(); //Remove previous best pair.
                track.push_back(heights[i]); //Remember current pair's heights.
                track.push_back(heights[j]);
            }
        }
    }

    return result;
}
