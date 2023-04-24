class Solution {
private:
    int m;
    int n;
    vector<vector<int> > visited;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visited = vector(m, vector<int>(n, 0));

        for (int i=0; i<m; ++i) {
            dfs(i, 0, grid);
            dfs(i, n-1, grid);
        }

        for (int i=1; i<n-1; ++i) {
            dfs(0, i, grid );
            dfs(m-1, i, grid);
        }

        int ans = 0;
        for (int i=1; i<m-1; ++i) {
            for (int j=1; j<n-1; ++j) {
                if (grid[i][j] && !visited[i][j]) {
                    ++ans;
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i>=m || i<0 || j>=n || j<0 || visited[i][j] || !grid[i][j]) return;
        visited[i][j] = 1;
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);

    }
};