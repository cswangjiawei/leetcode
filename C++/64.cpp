class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > dy_vec(m, vector<int>(n));

        for(int i=0; i < m; ++i) {
            for(int j=0; j < n; ++j) {
                if (i==0 && j==0) {
                    dy_vec[i][j] = grid[i][j];
                    continue;
                }
                if(i==0) {
                    dy_vec[i][j] = dy_vec[i][j-1] + grid[i][j];
                    continue;
                }
                if(j==0) {
                    dy_vec[i][j] = dy_vec[i-1][j] + grid[i][j];
                    continue;
                }
                dy_vec[i][j] = min(dy_vec[i-1][j], dy_vec[i][j-1]) + grid[i][j];
            }
        }

        return dy_vec[m-1][n-1];
    }
};