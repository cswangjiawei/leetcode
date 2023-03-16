class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = static_cast<int>(matrix.size());
        int n= static_cast<int>(matrix[0].size());

        int count=0;
        int i=0;
        int j=0;

        vector<vector<bool> > visited(m, vector<bool>(n, false));

        vector<vector<int> > directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int ptr = 0;

        while (count < m*n) {
            ans.emplace_back(matrix[i][j]);
            visited[i][j] = true;
            ++count;

            if (count >= m*n) {
                break;
            }
            int next_i = i + directions[ptr][0];
            int next_j = j + directions[ptr][1];

            while (next_i >= m || next_j >= n || next_i < 0 || next_j < 0 || visited[next_i][next_j]) {
                ptr = (ptr+1) % 4;
                next_i = i + directions[ptr][0];
                next_j = j + directions[ptr][1];
            }
            i = next_i;
            j = next_j;
            
        }

        return ans;
    }
};