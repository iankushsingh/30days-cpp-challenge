#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) or Union-Find structure
class DSU {
    std::vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find the root of a set
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    // Union of two sets
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
};

void kruskalMST(int vertices, std::vector<Edge>& edges) {
    // Sort edges by weight
    std::sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(vertices);
    std::vector<Edge> mst;

    for (const auto& edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            mst.push_back(edge);
            dsu.unite(edge.src, edge.dest);
        }
    }

    // Print the MST
    std::cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : mst) {
        std::cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
    }
}

int main() {
    int vertices, edgesCount;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> edgesCount;

    std::vector<Edge> edges(edgesCount);

    std::cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < edgesCount; ++i) {
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(vertices, edges);

    return 0;
}