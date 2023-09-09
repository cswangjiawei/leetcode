class Solution {
public:
    int fib(int n) {
        if (n==0 || n==1) {
            return n;
        }
        int fb1 = 0;
        int fb2 = 1;
        int ans;
        n = n - 1;
        while (n) {
            ans = fb1 + fb2;
            fb1 = fb2;
            fb2 = ans;
            --n;
        }
        return ans;

    }
};