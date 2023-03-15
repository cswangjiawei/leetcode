class Solution {
public:
    int mySqrt(int x) {
        for (int i=0; i<=x; ++i) {
            long long tmp = static_cast<long long>(i) * static_cast<long long>(i);
            if (tmp == x) {
                return i;
            }
            if (tmp > x) {
                return i-1;
            }
        }

        return 0;
    }
};