class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());

        for(int i=0; i<m; ++i) {
            if (target>=matrix[i][0] && target<=matrix[i][n-1]) {
                int left = 0;
                int right = n - 1;
                while(left <= right) {
                    int mid = (left + right) >> 1;
                    if (matrix[i][left] == target) {
                        return true;
                    }
                    if (matrix[i][left] > target) {
                        --right;
                    } else {
                        ++left;
                    }
                }
            }
        }
        return false;
    }
};