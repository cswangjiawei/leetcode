class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        int ans = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char> >& grid, int i, int j, int m, int n) {
        grid[i][j] = '0';
        if (i-1>=0 && grid[i-1][j] == '1') {
            dfs(grid, i-1, j, m, n);
        }
        if (i+1<m && grid[i+1][j] == '1') {
            dfs(grid, i+1, j, m, n);
        }
        if (j-1>=0 && grid[i][j-1] == '1') {
            dfs(grid, i, j-1, m, n);
        }
        if (j+1<n && grid[i][j+1] == '1') {
            dfs(grid, i, j+1, m, n);
        }
    }
};


class UnionFind {
private:
    int count;
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(vector<vector<char>>& grid):count(0) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    parent.emplace_back(i*n + j);
                    ++count;
                } else {
                    parent.emplace_back(-1);
                }
                rank.emplace_back(0);
            }
        }
    }

    int find(int i) {
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x != parent_y) {
            --count;
            if (rank[parent_x] < rank[parent_y]) {
                swap(rank[parent_x], rank[parent_y]);
            }
            parent[parent_y] = parent_x;
            if (rank[parent_x] == rank[parent_y]) {
                rank[parent_x] += 1;
            }
        }
    }

    int get_count() const {
        return count;
    }

};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row==0) return 0;
        int col = grid[0].size();

        UnionFind uf(grid);
        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i-1>=0 && grid[i-1][j]=='1') uf.unite(i*col+j, (i-1)*col+j);
                    if (i+1<row && grid[i+1][j]=='1') uf.unite(i*col+j, (i+1)*col+j);
                    if (j-1>=0 && grid[i][j-1]=='1') uf.unite(i*col+j, i*col+j-1);
                    if (j+1<col && grid[i][j+1]=='1') uf.unite(i*col+j, i*col+j+1);
                }
            }
        }

        return uf.get_count();

    }
};