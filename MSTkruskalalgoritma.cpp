#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    vector<int> induk, rank;

    DisjointSet(int n) {
        induk.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            induk[i] = i;
        }
    }

    int find(int u) {
        if (u != induk[u]) {
            induk[u] = find(induk[u]); 
        }
        return induk[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                induk[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                induk[rootV] = rootU;
            } else {
                induk[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

struct Edge {
    int u, v, bobot;
};

bool compareEdges(Edge a, Edge b) {
    return a.bobot < b.bobot;
}

int kruskal(int n, vector<Edge>& edges) {
    DisjointSet ds(n);
    sort(edges.begin(), edges.end(), compareEdges);
    int totalBobotMST = 0;

    for (Edge edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unionSets(edge.u, edge.v);
            totalBobotMST += edge.bobot;
        }
    }
    return totalBobotMST;
}

int main() {
    int n = 6; 
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 4},
        {1, 4, 5},
        {3, 4, 2},
        {4, 5, 6}
    };

    int totalBobot = kruskal(n, edges);
    cout << "Total Bobot Minimun Spanning Tree adalah: " << totalBobot << endl;

    return 0;
}






