#include <iostream>
#include <vector>
using namespace std;

// Directions for grid navigation: right and down (to simulate a spanning tree structure)
const int dx[] = { 1, 0 };
const int dy[] = { 0, 1 };

// Function to find the root of a node in the union-find data structure
int find(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = find(parent[node], parent);  // Path compression
    }
    return parent[node];
}

// Function to union two nodes in the union-find data structure
void unionSets(int node1, int node2, vector<int>& parent, vector<int>& rank) {
    int root1 = find(node1, parent);
    int root2 = find(node2, parent);

    if (root1 != root2) {
        // Union by rank to keep the tree flat
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        }
        else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        }
        else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

int main() {
    
    int rows = 50;
    int cols = 600;

    
    int totalNodes = rows * cols;

   
    int totalEdges = (rows * (cols - 1)) + (cols * (rows - 1));

    vector<int> parent(totalNodes);
    vector<int> rank(totalNodes, 0);

    
    for (int i = 0; i < totalNodes; ++i) {
        parent[i] = i;
    }


    int edgesInSpanningTree = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {

            int currentNode = r * cols + c;

            // Try to connect to the right node (if within bounds)
            if (c + 1 < cols) {
                int rightNode = r * cols + (c + 1);
                if (find(currentNode, parent) != find(rightNode, parent)) {
                    unionSets(currentNode, rightNode, parent, rank);
                    edgesInSpanningTree++;
                }
            }

            // Try to connect to the bottom node (if within bounds)
            if (r + 1 < rows) {
                int bottomNode = (r + 1) * cols + c;
                if (find(currentNode, parent) != find(bottomNode, parent)) {
                    unionSets(currentNode, bottomNode, parent, rank);
                    edgesInSpanningTree++;
                }
            }
        }
    }

    // Maximum number of edges that can be removed
    int removableEdges = totalEdges - edgesInSpanningTree;

    // Output the result
    cout << "Total number of edges: " << totalEdges << endl;
    cout << "Edges in the spanning tree: " << edgesInSpanningTree << endl;
    cout << "Maximum number of edges that can be removed: " << removableEdges << endl;

    return 0;
}
