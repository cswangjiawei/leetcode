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


class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
    
            int left = 0;
            int right = m * n - 1;
    
            while (left <= right) {
                int mid = (left + right) / 2;
                int i = mid / n;
                int j = mid % n;
                if (matrix[i][j] == target) {
                    return true;
                } else {
                    if (matrix[i][j] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            return false;
        }
    };