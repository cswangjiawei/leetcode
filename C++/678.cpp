class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stk_1;
        stack<int> stk_2;

        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                stk_1.push(i);
                continue;
            }
            if (s[i] == '*') {
                stk_2.push(i);
                continue;
            }
            
            if (!stk_1.empty()) {
                stk_1.pop();
            } else if (!stk_2.empty()) {
                stk_2.pop();
            } else {
                return false;
            }
        }

        while (!stk_1.empty()) {
            int index_1 = stk_1.top();
            stk_1.pop();
            if (!stk_2.empty()) {
                int index_2 = stk_2.top();
                stk_2.pop();
                if (index_1 > index_2) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};


class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));

        for (int i=0; i<n; ++i) {
            if (s[i] == '*')
                dp[i][i] = true;
        }

        for (int i=0; i<n-1; ++i) {
            if (s[i]=='(') {
                if (s[i+1]==')' || s[i+1]=='*') {
                    dp[i][i+1] = true;
                }
                continue;
            }
            if (s[i]=='*') {
                if (s[i+1]==')' || s[i+1]=='*') {
                    dp[i][i+1] = true;
                }
            }
        }

        int distance = 2;
        while (distance<n) {
            for (int i=0; i+distance<n;++i) {
                int j = i + distance;
                if (dp[i+1][j-1]) {
                    if (s[i]=='(') {
                        if (s[j]==')' || s[j]=='*') {
                            dp[i][j] = true;
                        }
                        continue;
                    }
                    if (s[i]=='*') {
                        if (s[j]==')' || s[j]=='*') {
                            dp[i][j] = true;
                        }
                    }
                } else {
                    for (int k=i; k<j && !dp[i][j]; ++k) {
                        dp[i][j] = dp[i][k] && dp[k+1][j];
                    }
                }
            }
            ++distance;
        }
        return dp[0][n-1];
    }
};