class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int ans = 1;
        for (int num: arr) {
            int tmp = num - difference;
            mp[num] = mp[tmp] + 1;
            ans = max(mp[num], ans);
        }

        return ans;
    }
};