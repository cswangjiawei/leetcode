class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minn = INT_MAX;
        for(int i=0; i<prices.size(); ++i) {
            if(prices[i] < minn) {
                minn = prices[i];
            }
            ans = max(prices[i]-minn, ans);
        }

        return ans;

    }
};