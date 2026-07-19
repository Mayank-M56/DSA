/*
Time Complexity : O(n)
Space Complexity : O(1) excluding "track", otherwise O(2) ≈ O(1)

Container With Most Water : Optimal Approach (Two Pointer).
    Observation :
        -Area depends on :
            1. Smaller height among both lines.
            2. Distance(width) between them.
        -Every iteration decreases width.
        -Thus only possibility to get larger area is by finding taller smaller-height line.

    Approach :
        -Take two pointers, one at left most line and other at right most line.
        -Calculate current container area.
        -Whenever greater area found, update result and remember that pair.
        -Move pointer having smaller height because it is limiting the current area.
        -Repeat until both pointers meet.
*/
#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& heights, vector<int>& track);

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> track; //Stores heights of line pair giving maximum area.

    int result = maxArea(heights, track);

    cout << "Max water in container can be possible if heights are ("
         << track[0] << ", " << track[1]
         << "), and Area would be : " << result;

    return 0;
}

int maxArea(vector<int>& heights, vector<int>& track) {
    int size = heights.size(); //Size of vector.
    int area, result = 0; //Stores current area and maximum area found till now.

    int i = 0, j = size-1; //Both pointers begin from extreme ends to get maximum possible width.

    while(i < j) { //Continue until both pointers meet because no valid container remains afterwards.

        area = min(heights[i], heights[j]) * (j-i); //Container height depends on shorter line and width is difference between both indices.

        if(area > result) { //If current container stores more water then update answer.
            result = area;

            track.clear(); //Remove previous best pair.

            track.push_back(heights[i]); //Remember current pair's heights.
            track.push_back(heights[j]);
        }

        (heights[i] < heights[j]) ? (i++) : (j--); //Smaller height is limiting current area. Keeping it while reducing width can never produce better result. Thus move smaller height pointer hoping to find taller line.
    }

    return result;
}
