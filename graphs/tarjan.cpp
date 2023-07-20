#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TarjanAlgorithm {
    int numVertices;
    vector<vector<int>> adjList;
    vector<int> lowLinkValue;
    vector<int> discoveryTime;
    vector<bool> inStack;
    stack<int> s;
    int time;

public:
    TarjanAlgorithm(int n) : numVertices(n), adjList(n), lowLinkValue(n, -1), discoveryTime(n, -1), inStack(n, false), time(0) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void tarjanSCC() {
        vector<vector<int>> SCCs;

        for (int i = 0; i < numVertices; ++i) {
            if (discoveryTime[i] == -1) {
                dfs(i, SCCs);
            }
        }

        // Print the strongly connected components
        cout << "Strongly Connected Components (SCCs):" << endl;
        for (const auto& SCC : SCCs) {
            cout << "SCC: ";
            for (int vertex : SCC) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

private:
    void dfs(int u, vector<vector<int>>& SCCs) {
        discoveryTime[u] = lowLinkValue[u] = time++;
        s.push(u);
        inStack[u] = true;

        for (int v : adjList[u]) {
            if (discoveryTime[v] == -1) {
                dfs(v, SCCs);
                lowLinkValue[u] = min(lowLinkValue[u], lowLinkValue[v]);
            } else if (inStack[v]) {
                lowLinkValue[u] = min(lowLinkValue[u], discoveryTime[v]);
            }
        }

        if (lowLinkValue[u] == discoveryTime[u]) {
            vector<int> SCC;
            int v;
            do {
                v = s.top();
                s.pop();
                inStack[v] = false;
                SCC.push_back(v);
            } while (u != v);
            SCCs.push_back(SCC);
        }
    }
};

int main() {
    int numVertices = 8; // Adjust this according to your graph's size
    TarjanAlgorithm tarjan(numVertices);

    // Add edges to the graph
    tarjan.addEdge(0, 1);
    tarjan.addEdge(1, 2);
    tarjan.addEdge(1, 3);
    tarjan.addEdge(2, 0);
    tarjan.addEdge(3, 4);
    tarjan.addEdge(4, 5);
    tarjan.addEdge(5, 3);
    tarjan.addEdge(5, 6);
    tarjan.addEdge(6, 7);
    tarjan.addEdge(7, 5);

    tarjan.tarjanSCC();

    return 0;
}
