#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to add an edge to the adjacency list
void addEdge(vector<vector<pair<int, int>>>& adjList, int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight); // For undirected graphs
}

// Dijkstra's algorithm
vector<int> dijkstra(vector<vector<pair<int, int>>>& adjList, int startVertex) {
    int numVertices = adjList.size();
    vector<int> distance(numVertices, INF);
    vector<bool> visited(numVertices, false);

    // Priority queue to keep track of the vertices with their current distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        pq.pop();

        if (visited[currentVertex]) {
            continue;
        }

        visited[currentVertex] = true;

        for (const auto& neighbor : adjList[currentVertex]) {
            int neighborVertex = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[neighborVertex] && distance[currentVertex] + edgeWeight < distance[neighborVertex]) {
                distance[neighborVertex] = distance[currentVertex] + edgeWeight;
                pq.push(make_pair(distance[neighborVertex], neighborVertex));
            }
        }
    }

    return distance;
}

int main() {
    int numVertices = 6; // Adjust this according to your graph's size
    vector<vector<pair<int, int>>> adjList(numVertices);

    // Add edges to the graph along with their weights
    addEdge(adjList, 0, 1, 4);
    addEdge(adjList, 0, 2, 2);
    addEdge(adjList, 1, 3, 5);
    addEdge(adjList, 1, 4, 1);
    addEdge(adjList, 2, 4, 3);
    addEdge(adjList, 3, 4, 2);
    addEdge(adjList, 3, 5, 6);
    addEdge(adjList, 4, 5, 3);

    int startVertex = 0; // Choose the starting vertex for Dijkstra's algorithm

    vector<int> shortestDistances = dijkstra(adjList, startVertex);

    cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (shortestDistances[i] == INF) {
            cout << "Not reachable" << endl;
        } else {
            cout << shortestDistances[i] << endl;
        }
    }

    return 0;
}
