class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int tmp = 0;
        int n = static_cast<int>(s.size());
        for(int i=0; i<n; ++i) {
            if (s[i] != ' ') {
                ++tmp;
            } else {
                if (tmp) {
                    ans = tmp;
                }
                tmp = 0;
            }
        }

        if (tmp) {
            ans = tmp;
        }
        return ans;
    }
};