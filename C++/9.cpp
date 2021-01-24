#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        vector<int> vec;
        int quotient = 0;
        int remainder = 0;
        while (x)
        {
            quotient = x / 10;
            remainder = x % 10;
            vec.emplace_back(remainder);
            x = quotient;
        }

        int i = 0;
        int j = vec.size() - 1;
        while ( i <= j && i < vec.size() && j < vec.size())
        {
            if (vec[i] != vec[j])
            {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};