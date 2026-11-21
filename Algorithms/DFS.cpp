#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited);

int main() {
    int size = 6; //6 vertices.

    vector<vector<int>> adj(size); //Creates an adjacency list to store connections of each vertex.

    adj[0] = {1, 2}; //Vertex 0 is connected to vertices 1 and 2.
    adj[1] = {0, 3, 4}; //Vertex 1 is connected to vertices 0, 3 and 4.
    adj[2] = {0, 5}; //Vertex 2 is connected to vertices 0 and 5.
    adj[3] = {1}; //Vertex 3 is connected only to vertex 1.
    adj[4] = {1}; //Vertex 4 is connected only to vertex 1.
    adj[5] = {2}; //Vertex 5 is connected only to vertex 2.

    vector<bool> visited(size, false); //Creates an array of size "size", initially containing false, meaning no vertex has been visited yet.

    DFS(0, adj, visited); //Start DFS from vertex 0/A, and pass the adjacency list and visited array to keep track of already visited vertices.

    return 0;
}

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; //Marks the current vertex as visited so that we don't visit it again.

    cout << node << "\t"; //Prints the current vertex as DFS visits it.

    //This loop checks all the vertices directly connected to the current vertex.
    for(int neighbor : adj[node]) { //For example, if node is 0 then adj[0] = {1, 2}, so neighbor will encounter 1 and then 2.
        if(!visited[neighbor]) { //Only if the neighboring vertex hasn't been visited yet.
            DFS(neighbor, adj, visited); //Instead of storing the new vertex in a queue like BFS, DFS calls itself with the new vertex to explore its connections deeply before coming back.
        }
    }
    //When no unvisited neighbor is left, the current DFS call ends and returns to the previous call, allowing it to explore the remaining neighbors (backtracking).
}
