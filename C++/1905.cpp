class Solution {
private:
    int m;
    int n;
    vector<vector<int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        m = grid1.size();
        n = grid1[0].size();

        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid2[i][j] && !visited[i][j]) {
                    ans += bfs(grid1, grid2, visited, i, j);
                }
            }
        }
        return ans;
    }

    int bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        bool check = grid1[i][j];
        while (!q.empty()) {
            auto e = q.front();
            q.pop();
            int row = e.first;
            int col = e.second;
            if (grid1[row][col] == 0) {
                check = false;
            }

            for (auto& direction: directions) {
            int next_row = row + direction[0];
            int next_col = col + direction[1];
            if (next_row<0 || next_row>=m || next_col<0 || next_col>=n || visited[next_row][next_col] || !grid2[next_row][next_col]) {
                continue;
                }
            q.push({next_row, next_col});
            visited[next_row][next_col] = true;
            }

        }
        return check;

    }
};