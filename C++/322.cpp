class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = 0;
        vector<int> dy_vec(amount+1, amount+1);
        dy_vec[0] = 0;
        for(int i=1; i <= amount; ++i) {
            for(int j=0; j<coins.size(); ++j) {
                if (coins[j] <= i) {
                    dy_vec[i] = min(dy_vec[i], dy_vec[i-coins[j]] + 1);
                }
            }
        }

        return dy_vec[amount] > amount ? -1 : dy_vec[amount];

    }

    
};