#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TopologicalSort {
    int numVertices;
    vector<vector<int>> adjList;
    vector<bool> visited;
    stack<int> result;

public:
    TopologicalSort(int n) : numVertices(n), adjList(n), visited(n, false) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    vector<int> getTopologicalSort() {
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        vector<int> topologicalOrder;
        while (!result.empty()) {
            topologicalOrder.push_back(result.top());
            result.pop();
        }

        return topologicalOrder;
    }

private:
    void dfs(int u) {
        visited[u] = true;

        for (int v : adjList[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }

        result.push(u);
    }
};

int main() {
    int numVertices = 7; // Adjust this according to your graph's size
    TopologicalSort ts(numVertices);

    // Add edges to the graph
    ts.addEdge(0, 1);
    ts.addEdge(0, 2);
    ts.addEdge(1, 3);
    ts.addEdge(2, 3);
    ts.addEdge(3, 4);
    ts.addEdge(4, 5);
    ts.addEdge(4, 6);

    vector<int> topologicalOrder = ts.getTopologicalSort();

    cout << "Topological Sort: ";
    for (int vertex : topologicalOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
