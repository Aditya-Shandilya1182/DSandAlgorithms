#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int src, dest, weight;
};

void addEdge(vector<Edge>& edges, int src, int dest, int weight) {
    edges.push_back({src, dest, weight});
}

void BellmanFord(vector<Edge>& edges, int numVertices, int startVertex) {
    vector<int> distance(numVertices, INF);
    distance[startVertex] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (const auto& edge : edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            if (distance[src] != INF && distance[src] + weight < distance[dest]) {
                distance[dest] = distance[src] + weight;
            }
        }
    }

    for (const auto& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;

        if (distance[src] != INF && distance[src] + weight < distance[dest]) {
            cout << "Negative weight cycle detected! The graph contains negative cycles." << endl;
            return;
        }
    }

    cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INF) {
            cout << "Not reachable" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

int main() {
    int numVertices = 5; // Adjust this according to your graph's size
    vector<Edge> edges;

    // Add edges to the graph along with their weights
    addEdge(edges, 0, 1, 6);
    addEdge(edges, 0, 2, 7);
    addEdge(edges, 1, 2, 8);
    addEdge(edges, 1, 3, 5);
    addEdge(edges, 1, 4, -4);
    addEdge(edges, 2, 3, -3);
    addEdge(edges, 2, 4, 9);
    addEdge(edges, 3, 1, -2);
    addEdge(edges, 4, 3, 7);

    int startVertex = 0; // Choose the starting vertex for Bellman-Ford algorithm

    BellmanFord(edges, numVertices, startVertex);

    return 0;
}
