class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(366, -1);
        unordered_set<int> days_set;
        for (int day: days) {
            days_set.insert(day);
        }
        return dp(1, costs, days_set, memo);
        
    }

    int dp(int i, vector<int>& costs, unordered_set<int>& days_set,vector<int>& memo) {
        if (i>365) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        if (days_set.count(i) == 0) {
            memo[i] = dp(i+1, costs, days_set, memo);
            return memo[i];
        }
    
        memo[i] = min(min(costs[2] + dp(i+30, costs, days_set, memo), costs[1] + dp(i+7, costs, days_set, memo)), costs[0] + dp(i+1, costs, days_set, memo));
        return memo[i];
    }
};