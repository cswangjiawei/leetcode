class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = static_cast<int>(text1.size());
        int len2 = static_cast<int>(text2.size());

        vector<vector<int> > dy_vec(len1+1, vector<int>(len2+1, 0));


        for (int i=1; i<=len1; ++i) {
            for (int j=1; j<=len2; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dy_vec[i][j] = dy_vec[i-1][j-1] + 1;
                } else {
                    dy_vec[i][j] = max(dy_vec[i-1][j], dy_vec[i][j-1]);
                }
            }
        }

        return dy_vec[len1][len2];
    }
};