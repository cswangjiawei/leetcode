class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s_count(26, 0);
        vector<int> p_count(26, 0);

        vector<int> ans;

        int n = static_cast<int>(s.size());
        int k = static_cast<int>(p.size());

        if (n < k) {
            return ans;
        }

        for (int i=0; i<k; ++i) {
            ++s_count[s[i] - 'a'];
            ++p_count[p[i] - 'a'];
        }

        if (s_count == p_count) {
            ans.emplace_back(0);
        }

        for (int i=k; i<n; ++i) {
            --s_count[s[i-k] - 'a'];
            ++s_count[s[i] - 'a'];
            if (s_count == p_count) {
                ans.emplace_back(i-k+1);
            }
        }

        return ans;
    }
};