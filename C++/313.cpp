class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int primes_size = primes.size();
        vector<int> pointers(primes_size, 0);
        vector<long> dp(n, 0);
        dp[0] = 1;
        int j = 1;
        while(j < n) {
            long cur_val = INT_MAX;
            for(int i=0; i<primes_size; ++i) {
                cur_val = min(cur_val, dp[pointers[i]]*primes[i]);
            }

            for (int i=0; i<primes_size; ++i) {
                if (cur_val == dp[pointers[i]]*primes[i]) {
                    ++pointers[i];
                }
            }
            dp[j] = cur_val;
            ++j;
        }
        return dp[n-1];
    }
};