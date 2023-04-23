class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<bool> > visited(m, vector<bool>(n, false));

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j]==1 && !visited[i][j]) {
                    ans = max(ans, dfs(grid, visited, i, j, m, n));
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool> >& visited, int i, int j, int m, int n) {
        int ans =1;
        visited[i][j] = true;
        if (i-1 >= 0 && grid[i-1][j] && !visited[i-1][j]) ans += dfs(grid, visited, i-1, j, m, n);
        if (i+1 < m && grid[i+1][j] && !visited[i+1][j]) ans += dfs(grid, visited, i+1, j, m, n);
        if (j-1 >= 0 && grid[i][j-1] && !visited[i][j-1]) ans += dfs(grid, visited, i, j-1, m, n);
        if (j+1 < n && grid[i][j+1] && !visited[i][j+1]) ans += dfs(grid, visited, i, j+1, m, n);
        return ans;
    }
};