#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited);

int main() {
    int size = 8; //8 vertices.

    vector<vector<int>> adj(size); //Creates an adjacency list to store connections of each vertex.

    adj[0] = {1}; //Vertex 0 is connected to vertex 1.
    adj[1] = {0, 2}; //Vertex 1 is connected to vertices 0 and 2.
    adj[2] = {1}; //Vertex 2 is connected only to vertex 1.

    adj[3] = {4, 5}; //Vertex 3 is connected to vertices 4 and 5.
    adj[4] = {3}; //Vertex 4 is connected only to vertex 3.
    adj[5] = {3}; //Vertex 5 is connected only to vertex 3.

    adj[6] = {7}; //Vertex 6 is connected to vertex 7.
    adj[7] = {6}; //Vertex 7 is connected to vertex 6.

    vector<bool> visited(size, false); //Initially marks all vertices as unvisited.

    int components = 0; //Initially there are no connected components discovered.

    for(int i = 0; i < size; i++) { //Checks every vertex to ensure that no disconnected group is left unexplored.
        if(!visited[i]) { //Only if the current vertex hasn't been visited yet, it means a new component is found.
            components++; //Increments the count because a new connected component has been discovered.
            DFS(i, adj, visited); //Explores every vertex reachable from this vertex, marking the entire component visited.
        }
    }

    cout << "\nTotal Connected Components: " << components;

    return 0;
}

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; //Marks the current vertex as visited so that we don't visit it again.

    cout << node << "\t"; //Prints the current vertex as DFS visits it.

    for(int neighbor : adj[node]) { //Checks all the vertices directly connected to the current vertex.
        if(!visited[neighbor]) { //Only if the neighboring vertex hasn't been visited yet.
            DFS(neighbor, adj, visited); //Calls DFS again to explore the new vertex deeply before returning.
        }
    }
}
