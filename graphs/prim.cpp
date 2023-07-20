#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int dest, weight;
};

class CompareEdges {
public:
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

void addEdge(vector<vector<Edge>>& adjList, int src, int dest, int weight) {
    adjList[src].push_back({dest, weight});
    adjList[dest].push_back({src, weight}); // For undirected graphs
}

void prim(vector<vector<Edge>>& adjList, int numVertices) {
    priority_queue<Edge, vector<Edge>, CompareEdges> pq;
    vector<bool> inMST(numVertices, false);
    vector<int> key(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);

    int startVertex = 0; // Start from vertex 0

    key[startVertex] = 0;
    pq.push({startVertex, 0});

    while (!pq.empty()) {
        int u = pq.top().dest;
        pq.pop();

        inMST[u] = true;

        for (const auto& edge : adjList[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({v, key[v]});
            }
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " -- " << i << " : " << key[i] << endl;
    }
}

int main() {
    int numVertices = 6; // Adjust this according to your graph's size
    vector<vector<Edge>> adjList(numVertices);

    // Add edges to the graph along with their weights
    addEdge(adjList, 0, 1, 4);
    addEdge(adjList, 0, 2, 2);
    addEdge(adjList, 1, 2, 5);
    addEdge(adjList, 1, 3, 10);
    addEdge(adjList, 2, 3, 7);
    addEdge(adjList, 2, 4, 3);
    addEdge(adjList, 3, 4, 8);
    addEdge(adjList, 3, 5, 6);
    addEdge(adjList, 4, 5, 1);

    prim(adjList, numVertices);

    return 0;
}
