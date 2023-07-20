#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

//DSU stands for Disjoint Set Union. DSU is a data structure that is used to efficiently manage 
//sets of elements that are partitioned into disjoint subsets. 
//It is a key component in Kruskal's algorithm to detect cycles during the process of building 
//the Minimum Spanning Tree (MST).
class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

void kruskal(vector<Edge>& edges, int numVertices) {
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(numVertices);
    vector<Edge> mst;
    int mstWeight = 0;

    for (const auto& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;

        if (dsu.find(src) != dsu.find(dest)) {
            mst.push_back(edge);
            mstWeight += weight;
            dsu.unite(src, dest);
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    cout << "Total MST Weight: " << mstWeight << endl;
}

int main() {
    int numVertices = 6; // Adjust this according to your graph's size
    vector<Edge> edges;

    // Add edges to the graph along with their weights
    edges.push_back({0, 1, 4});
    edges.push_back({0, 2, 2});
    edges.push_back({1, 2, 5});
    edges.push_back({1, 3, 10});
    edges.push_back({2, 3, 7});
    edges.push_back({2, 4, 3});
    edges.push_back({3, 4, 8});
    edges.push_back({3, 5, 6});
    edges.push_back({4, 5, 1});

    kruskal(edges, numVertices);

    return 0;
}
