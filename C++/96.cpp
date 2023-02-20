class Solution {
public:
    int numTrees(int n) {
        vector<int> dy_vec(n+1, 0);
        dy_vec[0] = 1;
        dy_vec[1] = 1;

        for (int i=2; i<=n; ++i) {
            for (int j=1; j<=i; ++j) {
                dy_vec[i] += dy_vec[j-1] * dy_vec[i-j];
            }
        }

        return dy_vec[n];
    }
};