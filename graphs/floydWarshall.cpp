#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void floydWarshall(vector<vector<int>>& graph) {
    int numVertices = graph.size();

    // Initialize the distance matrix with the given graph
    vector<vector<int>> distance(graph);

    // Calculate shortest paths between all pairs of vertices
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between all pairs of vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (distance[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << distance[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int numVertices = 4; // Adjust this according to your graph's size

    // Initialize the graph with the given edge weights
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}
