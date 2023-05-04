struct Edge {
    int x;
    int y;
    int len;
    Edge(int x, int y, int len):x(x), y(y), len(len) {}
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        for(int i=0; i<n; ++i) {
            parent.emplace_back(i);
            rank.emplace_back(1);
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
            if (rank[parent_x] == parent_y) {
                ++rank[parent_x];
            }
        }
    }

    bool isconnected(int x, int y) {
        return find(x) == find(y);
    } 
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        auto distance = [&](int i, int j) -> int {return abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);};

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                edges.emplace_back(i, j, distance(i, j));
            }
        }

        sort(edges.begin(), edges.end(), [](Edge a, Edge b)->bool {return a.len < b.len;});

        UnionFind uf(n);
        int ans = 0;
        for (auto &edge: edges) {
            int x = edge.x;
            int y = edge.y;
            int len = edge.len;
            if (!uf.isconnected(x, y)) {
                uf.unite(x, y);
                ans += len;
            }
        }
        return ans;
    }
};