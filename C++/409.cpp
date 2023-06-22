class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto& ch: s) {
            ++mp[ch];
        }

        int ans = 0;
        bool odd_flag = false;
        for (auto& [ch, cnt]: mp) {
            if (cnt%2==0) {
                ans += cnt;
            } else {
                ans += (cnt - 1);
                odd_flag = true;
            }
        }
        
        if (odd_flag)
            ans += 1;

        return ans;

    }
};