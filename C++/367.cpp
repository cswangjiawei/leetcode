class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==1) {
            return true;
        }

        int half = num/2;
        for (int i=1; i<=half; ++i) {
            if (num/i == i && num%i==0) {
                return true;
            }
            if (num/i < i) {
                return false;
            }
        }
        return false;
    }
};