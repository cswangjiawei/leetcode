class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = static_cast<int>(s.size());

        for (int i=0; i<n; ++i) {
            ans += 1;
            for (int j=i-1, k=i+1; j>=0 && k<n; --j, ++k) {
                if (s[j] == s[k]) {
                    ++ans;
                } else {
                    break;
                }
            }
        }

        for (int i=0; i<n-1; ++i) {
            int j = i+1;
            if (s[i] == s[j]) {
                ++ans;
            } else {
                continue;
            }

            for (int k=i-1, m=j+1; k>=0 && m<n; --k, ++m) {
                if (s[k] == s[m]) {
                    ++ans;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};