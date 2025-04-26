#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, induk;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        induk.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            induk[i] = i;
        }
    }

    int findIndukUtama(int simpul) {
        if (simpul == induk[simpul])
            return simpul;
        return induk[simpul] = findIndukUtama(induk[simpul]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findIndukUtama(u);
        int ulp_v = findIndukUtama(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            induk[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            induk[ulp_v] = ulp_u;
        } else {
            induk[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findIndukUtama(3) == ds.findIndukUtama(7)) {
        cout << "Sama\n";
    } else {
        cout << "Tidak sama\n";
    }

    ds.unionByRank(3, 7);

    if (ds.findIndukUtama(3) == ds.findIndukUtama(7)) {
        cout << "Sama\n";
    } else {
        cout << "Tidak sama\n";
    }

    return 0;
}
