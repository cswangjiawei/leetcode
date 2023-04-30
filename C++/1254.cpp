class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool> > visited(m, vector<bool>(n, false));

        int ans = 0;
        for (int i=1; i<m-1; ++i) {
            for (int j=1; j<n-1; ++j) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    ans += dfs(grid, visited, i, j, m, n);
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool> >& visited, int i, int j, int m, int n) {
        if (visited[i][j]) return true;
        visited[i][j] = true;
        if ((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==0)  return 0;
        if (grid[i][j]==1) return 1;
        int a = dfs(grid, visited, i-1, j, m, n);
        int b = dfs(grid, visited, i+1, j, m, n);
        int c = dfs(grid, visited, i, j-1, m, n);
        int d = dfs(grid, visited, i, j+1, m, n);

        return a && b && c && d;
    }
};