class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > f(m, vector<int>(n, 0));

        int ans = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==0) {
                    continue;
                }
                if (i==0 || j==0) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]) + 1;
                }
                ans += f[i][j];
            }
        }

        return ans;
    }
};