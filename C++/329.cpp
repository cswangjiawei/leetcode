class Solution {
private:
    int m;
    int n;
    vector<vector<int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans = max(ans, dfs(matrix, dp, i, j) );
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int> >& dp, int i, int j) {
        if (dp[i][j]) {
            return dp[i][j];
        }
        int ans = 1;
        for (auto& direction: directions) {
            int next_i = i + direction[0];
            int next_j = j + direction[1];
            if (next_i<0 || next_i>=m || next_j<0 || next_j>=n || matrix[next_i][next_j] <= matrix[i][j]) {
                continue;
            }
            int tmp = 1;
            if (dp[next_i][next_j]) {
                tmp += dp[next_i][next_j];
            } else {
                tmp += dfs(matrix, dp, next_i, next_j);
            }
            ans = max(ans, tmp);
        }
        dp[i][j] = ans;

        return ans;
    }
};