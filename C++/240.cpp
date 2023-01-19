class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int cloumn = matrix[0].size();

        if(target > matrix[row-1][cloumn-1] || target < matrix[0][0]) {
            return false;
        }

        int cur_row = 0;
        while(cur_row < row) {
            if(target >= matrix[cur_row][0] && target <= matrix[cur_row][cloumn-1]) {
                int left = 0;
                int right = cloumn-1;
                while(left <= right) {
                    int mid = (left + right) / 2;
                    if (matrix[cur_row][mid] == target) {
                        return true;
                    }
                    if(matrix[cur_row][mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            ++cur_row;
        }
        
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());

        int i = 0;
        int j = n-1;

        while(i<m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }

            if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return false;
    }
};