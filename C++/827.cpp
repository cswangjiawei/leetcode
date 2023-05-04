class Solution {
private:
    vector<vector<int> > direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_map<int, int> area;

public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > tag(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (!tag[i][j] && grid[i][j]) {
                    int t = i*n + j + 1;
                    area[t] = dfs(grid, tag, t, i, j);
                    ans = max(ans, area[t]);
                } 
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 0) {
                    int z = 1;
                    unordered_set<int> connected;
                    for (auto& direct: direction) {
                        int next_i = i + direct[0];
                        int next_j = j + direct[1];
                        if (next_i<0 || next_i>=m || next_j<0 || next_j>=n || !tag[next_i][next_j] || connected.count(tag[next_i][next_j])) {
                            continue;
                        }
                        z += area[tag[next_i][next_j]];
                        connected.insert(tag[next_i][next_j]);
                    }
                    ans = max(ans, z);
                }
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<int> >& tag, int t, int i, int j) {
        tag[i][j] = t;
        int res = 1;
        for (auto& direct: direction) {
            int next_i = i + direct[0];
            int next_j = j + direct[1];
            if (next_i<0 || next_i>=grid.size() || next_j<0 || next_j>=grid[0].size() || tag[next_i][next_j] || !grid[next_i][next_j]) {
                continue;
            }
            res += dfs(grid, tag, t, next_i, next_j);
        }
        return res;
        
    }
};