#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int weight;
    int from;
    int to;

    Edge(int w, int f, int t) : weight(w), from(f), to(t) {}
};

bool compareEdge(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
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

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false; 

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Graph {
private:
    int nodes;
    vector<Edge> edges;

public:
    Graph(int n) : nodes(n) {}

    void addEdge(int from, int to, int weight) {
        edges.emplace_back(weight, from, to);
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(), compareEdge);

        UnionFind uf(nodes);

        int mstWeight = 0;
        vector<Edge> mstEdges;

        for (const auto& edge : edges) {
            if (uf.unionSets(edge.from, edge.to)) {
                mstWeight += edge.weight;
                mstEdges.push_back(edge);
            }
        }

        // Output the MST
        cout << "Minimum Spanning Tree Edges:" << endl;
        for (const auto& edge : mstEdges) {
            cout << edge.from << " - " << edge.to << " (weight: " << edge.weight << ")" << endl;
        }
        cout << "Total Weight of MST: " << mstWeight << endl;
    }
};

int main() {
    int numNodes = 6;
    Graph graph(numNodes);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(3, 4, 6);
    graph.addEdge(4, 5, 9);
    graph.addEdge(2, 5, 10);

    graph.kruskalMST();

    return 0;
}
