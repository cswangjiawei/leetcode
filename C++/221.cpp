class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        vector<vector<int> > dy_vec(m, vector<int>(n, 0));

        int max_side = 0;

        for (int i=0; i < m; ++i) {
            for (int j=0; j < n; ++j) {
                if (i==0 || j==0) {
                    if (matrix[i][j] == '1') {
                        dy_vec[i][j] = 1;
                    }
                } else {
                    if (matrix[i][j] == '1') {
                        dy_vec[i][j] = min(min(dy_vec[i-1][j], dy_vec[i][j-1]), dy_vec[i-1][j-1]) + 1;
                    }
                    
                }
                max_side = max(max_side, dy_vec[i][j]);
            }
        }

        ans = max_side * max_side;
        return ans;
    }
};