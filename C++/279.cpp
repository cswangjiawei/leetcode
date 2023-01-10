class Solution {
public:
    int numSquares(int n) {
        int ans = 0;
        vector<int> dy_vec(n+1, INT_MAX);
        dy_vec[0] = 0;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j*j<=i; ++j) {
                dy_vec[i] = min(dy_vec[i-j*j]+1, dy_vec[i]);
            }
        }

        return dy_vec[n];
    }
};