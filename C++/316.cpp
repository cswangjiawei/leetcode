class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<bool> visited(26, false);
        unordered_map<char, int> mp;
        int n = s.size();

        for (int i=0; i<n; ++i) {
            mp[s[i]] = i;
        }

        for (int i=0; i<n; ++i) {
            if (!visited[s[i] - 'a']) {
                if (!ans.empty() && ans.back() < s[i]) {
                    ans.push_back(s[i]);
                    visited[s[i] - 'a'] = true;
                    continue;
                }
                while (!ans.empty() && ans.back() > s[i]) {
                    if (i < mp[ans.back()]) {
                        visited[ans.back() - 'a'] = false;
                        ans.pop_back();
                    } else {
                        break;
                    }
                }
                ans.push_back(s[i]);
                visited[s[i] - 'a'] = true;
            }
        }

        return ans;
    }
};