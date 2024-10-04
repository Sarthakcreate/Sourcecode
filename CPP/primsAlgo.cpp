#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Defining a structure to represent a graph's edge
typedef pair<int, int> pii; // (weight, node)

// Function to run Prim's algorithm
void primMST(int V, vector<vector<pii>>& adj) {
    // Priority queue to pick the minimum weight edge (min heap)
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // To store the minimum spanning tree (MST) result
    vector<int> parent(V, -1);

    // To keep track of the minimum edge weight to reach a node
    vector<int> key(V, INT_MAX);

    // To check whether a node is already included in the MST
    vector<bool> inMST(V, false);

    // Start from the 0th vertex
    key[0] = 0;
    pq.push({0, 0}); // (weight, node)

    while (!pq.empty()) {
        int u = pq.top().second; // Extract the minimum node from the queue
        pq.pop();

        // Include the extracted vertex in the MST
        inMST[u] = true;

        // Explore all adjacent vertices of the extracted node
        for (auto& [weight, v] : adj[u]) {
            // If v is not yet in the MST and the weight of (u, v) is smaller than the current key[v]
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Output the edges of the MST
    cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " \tWeight: " << key[i] << "\n";
    }
}

// Driver function
int main() {
    int V = 5; // Number of vertices in the graph
    vector<vector<pii>> adj(V);

    // Adding edges: (node1, node2, weight)
    adj[0].push_back({2, 1}); adj[1].push_back({2, 0}); // Edge 0-1 (weight 2)
    adj[0].push_back({3, 3}); adj[3].push_back({3, 0}); // Edge 0-3 (weight 3)
    adj[1].push_back({3, 2}); adj[2].push_back({3, 1}); // Edge 1-2 (weight 3)
    adj[1].push_back({1, 3}); adj[3].push_back({1, 1}); // Edge 1-3 (weight 1)
    adj[2].push_back({5, 4}); adj[4].push_back({5, 2}); // Edge 2-4 (weight 5)
    adj[3].push_back({2, 4}); adj[4].push_back({2, 3}); // Edge 3-4 (weight 2)

    // Running Prim's algorithm
    primMST(V, adj);

    return 0;
}
