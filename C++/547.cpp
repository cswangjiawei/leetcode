class UnionFind {
private:
    int count;
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n): count(0) {
        for (int i=0; i<n; ++i) {
            parent.emplace_back(i);
            rank.emplace_back(0);
            ++count;
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
            if (rank[parent_x] == rank[parent_y]) rank[parent_x] += 1;
            --count;
        }

    }

    int get_count() const {
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (isConnected[i][j]) {
                    uf.unite(i, j);
                }
            }
        }

        return uf.get_count();
    }
};