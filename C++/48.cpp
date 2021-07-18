class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0;
        int j = matrix.size() - 1;
        while (i < j) 
        {
            auto temp = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = temp;

            ++i;
            --j;
        }

        for (int i=0; i < matrix.size(); ++i)
        {
            for (int j=i+1; j < matrix.size(); ++j)
            {
                auto temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
    }
};