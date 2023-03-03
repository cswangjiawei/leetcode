class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i=0; i<=n; ++i) {
            auto res = count_one(i);
            ans.emplace_back(res);
        }

        return ans;
    }

    int count_one(int x) {
        int ans = 0;
        while (x) {
            ans += x & 1;
            x = x>>1;
        }

        return ans;
    }
};