class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;

        int tmp = x ^ y;

        while (tmp) {
            ans += tmp & 1;
            tmp = tmp >> 1;
        }

        return ans;
    }
};