#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// Depth-First Search algorithm
void DFSUtil(vector<vector<int>>& adjList, int currentVertex, vector<bool>& visited) {
    visited[currentVertex] = true;
    cout << currentVertex << " "; // Process the current vertex

    for (int neighbor : adjList[currentVertex]) {
        if (!visited[neighbor]) {
            DFSUtil(adjList, neighbor, visited);
        }
    }
}

void DFS(vector<vector<int>>& adjList, int startVertex) {
    vector<bool> visited(adjList.size(), false); // To track visited vertices
    DFSUtil(adjList, startVertex, visited);
}

// Function to add an edge to the adjacency list
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graphs
}

// Breadth-First Search algorithm
void BFS(vector<vector<int>>& adjList, int startVertex) {
    vector<bool> visited(adjList.size(), false); // To track visited vertices
    queue<int> q;

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " "; // Process the current vertex

        // Enqueue all the unvisited neighbors of the current vertex
        for (int neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numVertices = 6; // Adjust this according to your graph's size
    vector<vector<int>> adjList(numVertices);

    // Add edges to the graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 3, 5);
    addEdge(adjList, 4, 5);

    int startVertex = 0; // Choose the starting vertex for BFS

    cout << "Breadth-First Traversal (starting from vertex " << startVertex << "): ";
    BFS(adjList, startVertex);
    cout << endl;

    return 0;
}
