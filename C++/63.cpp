class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = static_cast<int>(obstacleGrid.size());
        int n = static_cast<int>(obstacleGrid[0].size());
        vector<vector<int> > dy_vec(m, vector<int>(n, 0));

        if (obstacleGrid[0][0]==1) {
            return 0;
        }
        dy_vec[0][0] = 1;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0) {
                    continue;
                }
                if (i==0 || j==0) {
                    if (obstacleGrid[i][j] != 1) {
                        if (i==0) {
                            dy_vec[i][j] = dy_vec[i][j-1];
                        } else {
                            dy_vec[i][j] = dy_vec[i-1][j];
                        }
                    }
                } else {
                    if (obstacleGrid[i][j] != 1) {
                        dy_vec[i][j] = dy_vec[i-1][j] + dy_vec[i][j-1];
                    }
                }
            }
        }
        return dy_vec[m-1][n-1];
    }
};