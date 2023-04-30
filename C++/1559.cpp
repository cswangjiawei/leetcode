class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int m, int n) {
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                parent.emplace_back(i*n+j);
                rank.emplace_back(1);
            }
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
        if (parent_x != parent_y) {
            if (rank[parent_x] < rank[parent_y]) {
                swap(parent_x, parent_y);
            }
            parent[parent_y] = parent_x;
            if (rank[parent_x] == rank[parent_y]) {
                rank[parent_x] += 1;
            }
        }
    }

    bool isconnected(int x, int y) {
        return parent[x] == parent[y];
    }

};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m, n);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i>0 && grid[i][j] == grid[i-1][j]) {
                    if (uf.isconnected(i*n+j, (i-1)*n+j)) {
                        return true;
                    } else {
                        uf.unite(i*n+j, (i-1)*n+j);
                    }
                }
                if (j>0 && grid[i][j] == grid[i][j-1]) {
                    if (uf.isconnected(i*n+j, i*n+j-1)) {
                        return true;
                    } else {
                        uf.unite(i*n+j, i*n+j-1);
                    }
                }
            }
        }

        return false;
    }
};