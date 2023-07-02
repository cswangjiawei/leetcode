class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        for (int i=0, j=0; i<g.size() && j<s.size();++i, ++j) {
            while (i<g.size() && j<s.size() && g[i] > s[j]) {
                ++j;
            }
            if (j < s.size()) {
                ++ans;
            }
        }

        return ans;
    }
};