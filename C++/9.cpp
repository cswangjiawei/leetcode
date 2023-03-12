class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reverse_member = 0;
        while (x > reverse_member) {
            int remainder = x % 10;
            x = x / 10;
            reverse_member = reverse_member * 10 + remainder;
        }

        return x == reverse_member || x == reverse_member/10;
    }
};