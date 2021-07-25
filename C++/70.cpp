class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        while (n)
        {
            auto temp = b;
            b = a + b;
            a = temp;
            --n;
        }
        return b;
    }
};