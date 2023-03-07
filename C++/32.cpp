class Solution {
public:
    int longestValidParentheses(string s) {
        int n = static_cast<int>(s.size());
        if (n==0 || n == 1) {
            return 0;
        }

        vector<int> dp(n, 0);
        int ans = 0;

        for (int i=0; i<2; ++i) {
            if (i == 0) {
                dp[i] = 0;
            }
            else if (i==1 && s[i] == ')' && s[i-1] == '(') {
                dp[i] = 2;
            }
            ans = max(dp[i], ans);
        }

        for (int i=2; i<n; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = dp[i-2] + 2;
                } else {
                    if (i-dp[i-1]-1 >=0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1] + 2;
                        if (i-dp[i-1]-2 >= 0) {
                            dp[i] += dp[i-dp[i-1] - 2];
                        }
                    }   
                }
                ans = max(dp[i], ans);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;

        int left = 0;
        int right = 0;

        int n = static_cast<int>(s.size());

        for (char &c: s) {
            if (c == '(') {
                ++left;
            } else if (c == ')') {
                ++right;
            }

            if (left == right) {
                ans = max(ans, left*2);
            }
            if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for (int i=n-1; i>=0; --i) {
            if (s[i]==')') {
                ++right;
            } else if (s[i]=='(') {
                ++left;
            }

            if (left == right) {
                ans = max(ans, right*2);
            }
            
            if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};