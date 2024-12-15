#include <iostream>
#include <vector>
#include <algorithm>

/*
ADABRANC - Ada and Branches
tree & sorting
*/

using namespace std;

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
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
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int get_size(int x) {
        return size[find(x)];
    }
};

struct Edge {
    int weight, u, v;

    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

struct Query {
    int weight, node, index;

    bool operator<(const Query& other) const {
        return weight > other.weight;
    }
};

int main() {
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<Edge> edges(M); 
    vector<Query> queries(Q);
    vector<int> result(Q);

    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    for (int i = 0; i < Q; i++) {
        cin >> queries[i].node >> queries[i].weight;
        queries[i].index = i;
    }

    sort(edges.begin(), edges.end());
    sort(queries.begin(), queries.end());

    DSU dsu(N);
    int edgeIndex = 0;

    for (const Query& query : queries) {
        while (edgeIndex < M && edges[edgeIndex].weight >= query.weight) {
            dsu.unite(edges[edgeIndex].u, edges[edgeIndex].v);
            edgeIndex++;
        }

        result[query.index] = dsu.get_size(query.node);
    }

    for (int i = 0; i < Q; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
