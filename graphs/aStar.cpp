#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

const double INF = numeric_limits<double>::max();

struct Node {
    int vertex;
    double fScore; // f(n) = g(n) + h(n)
};

struct Edge {
    int dest;
    double weight;
};

class AStarAlgorithm {
    int numVertices;
    vector<vector<Edge>> adjList;
    vector<double> gScore;
    vector<double> fScore;
    vector<int> cameFrom;

public:
    AStarAlgorithm(int n) : numVertices(n), adjList(n), gScore(n, INF), fScore(n, INF), cameFrom(n, -1) {}

    void addEdge(int u, int v, double weight) {
        adjList[u].push_back({v, weight});
    }

    vector<int> aStar(int startVertex, int goalVertex) {
        gScore[startVertex] = 0;
        fScore[startVertex] = heuristic(startVertex, goalVertex);

        priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq(
            [](Node a, Node b) { return a.fScore > b.fScore; });

        pq.push({startVertex, fScore[startVertex]});

        while (!pq.empty()) {
            int currentVertex = pq.top().vertex;
            pq.pop();

            if (currentVertex == goalVertex) {
                return reconstructPath(goalVertex);
            }

            for (const auto& edge : adjList[currentVertex]) {
                int neighborVertex = edge.dest;
                double tentativeGScore = gScore[currentVertex] + edge.weight;

                if (tentativeGScore < gScore[neighborVertex]) {
                    cameFrom[neighborVertex] = currentVertex;
                    gScore[neighborVertex] = tentativeGScore;
                    fScore[neighborVertex] = gScore[neighborVertex] + heuristic(neighborVertex, goalVertex);
                    pq.push({neighborVertex, fScore[neighborVertex]});
                }
            }
        }

        return {}; // No path found
    }

private:
    double heuristic(int startVertex, int goalVertex) {
        // Replace this heuristic function with an appropriate heuristic for your problem
        // In this example, we use Euclidean distance as the heuristic
        double dx = abs(startVertex - goalVertex);
        return dx;
    }

    vector<int> reconstructPath(int currentVertex) {
        vector<int> path;
        while (currentVertex != -1) {
            path.push_back(currentVertex);
            currentVertex = cameFrom[currentVertex];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int numVertices = 10; // Adjust this according to your graph's size
    AStarAlgorithm astar(numVertices);

    // Add edges to the graph along with their weights
    astar.addEdge(0, 1, 2);
    astar.addEdge(0, 2, 4);
    astar.addEdge(1, 3, 5);
    astar.addEdge(2, 3, 2);
    astar.addEdge(2, 4, 3);
    astar.addEdge(3, 5, 1);
    astar.addEdge(4, 5, 4);
    astar.addEdge(4, 6, 3);
    astar.addEdge(5, 7, 3);
    astar.addEdge(6, 7, 4);
    astar.addEdge(7, 8, 5);
    astar.addEdge(7, 9, 3);
    astar.addEdge(8, 9, 2);

    int startVertex = 0; // Choose the starting vertex for A* algorithm
    int goalVertex = 9;  // Choose the goal vertex for A* algorithm

    vector<int> path = astar.aStar(startVertex, goalVertex);

    if (!path.empty()) {
        cout << "Shortest path from " << startVertex << " to " << goalVertex << ": ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << startVertex << " to " << goalVertex << endl;
    }

    return 0;
}
