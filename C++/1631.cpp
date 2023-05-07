class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        for (int i=0; i<n; ++i) {
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
            if (rank[parent_x] == rank[parent_y]) {
                ++rank[parent_x];
            }
        }
    }

    bool isconnected(int x, int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int x;
    int y;
    int len;
    Edge(int x, int y, int len): x(x), y(y), len(len) {}

};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<Edge> edges;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (j<n-1) {
                    Edge edge1 = Edge(i*n+j, i*n+j+1, abs(heights[i][j] - heights[i][j+1]));
                    edges.push_back(edge1);
                }
                if (i<m-1) {
                    Edge edge2 = Edge(i*n+j, (i+1)*n+j, abs(heights[i][j] - heights[i+1][j]));
                    edges.push_back(edge2);
                }   
            }
        }

        sort(edges.begin(), edges.end(), [](Edge& edge1, Edge& edge2){return edge1.len<edge2.len;});

        UnionFind uf(m*n);
        for (Edge& edge: edges) {
            int x = edge.x;
            int y = edge.y;
            if (!uf.isconnected(x, y)) {
                uf.unite(x, y);
            }
            if (uf.isconnected(0, m*n-1)) {
                return edge.len;
            }
        }
        return 0;
    }
};