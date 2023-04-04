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