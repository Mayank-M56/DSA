#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, int size);

int main() {
    int size = 6; //6 vertices.

    vector<vector<int>> adj(size);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    BFS(0, adj, size);

    return 0;
}

void BFS(int start, vector<vector<int>>& adj, int size) {
    vector<bool> visited(size, false); //This creates an array of size "size", initially containing false like this "visited = [false, false, false, false, false, false]"."
    queue<int> q; //This will enqueue newly found vertex and dequeue visited vertex.

    visited[start] = true; //Like this -> visited = [true, false, false, false, false, false]
    q.push(start); //Queue got his first vertex to expand which is 0/A.

    while(!q.empty()) {
        int node = q.front(); //Queue: [0], "q.front()" only accesses the front element.
                              //        ↑
                              //      Front
        q.pop(); //Since we got a front vertex in "node" then it should be dequeue.

        cout << node << "\t"; //Our traversal output is gradually constructed as BFS processes vertices.

        //This loop motive is mark only new found vertex as visited and push that vertex into queue. 
        for(int neighbor : adj[node]) { //A range-based for loop, "adj[node]" is a vertex that has multiple connection with other vertices, i.e. - "A -> [B, C, E, F]", this mean loop end after B, C, E and F encounter.
            if(!visited[neighbor]) { //Only if vertex isn't visited yet.
                visited[neighbor] = true; //New Vertex found and marked visited.
                q.push(neighbor); //Store in queue and will pop() when it about to expand its connection.
            }
        //Because queue keep getting new vertex then they'll expand when front one will "pop()". 
        }
    }
}
