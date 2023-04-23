class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        for (int i=0; i<n; ++i) {
            parent.emplace_back(i);
            rank.emplace_back(0);
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (rank[parent_x] < rank[parent_y]) {
            swap(parent_x, parent_y);
        }
        parent[parent_y] = parent_x;

        if (rank[parent_y] == rank[parent_x]) {
            rank[parent_x] += 1;
        }

    }

    bool connected(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        return parent_x == parent_y;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n+1);
        for (auto &edge: edges) {
            if (uf.connected(edge[0], edge[1])) {
                return edge;
            } else {
                uf.unite(edge[0], edge[1]);
            }
        }

        return {};
    }
};