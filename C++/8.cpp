#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string s_num;
        bool flag = false;
        bool is_first = true;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ' && is_first)
            {
                continue;
            }
            if (s[i] == '-' && is_first && s_num.size() == 0)
            {
                flag = true;
                is_first = false;
                continue;
            }
            if (s[i] == '+' && is_first && s_num.size() == 0)
            {
                is_first = false;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                s_num += s[i];
                is_first = false;
                continue;
            }
            else
            {
                break;
            }
        }

        int num = 0;
        for (char& c : s_num)
        {
            int temp = c - '0';
            if (!flag && (INT_MAX / 10 < num || INT_MAX / 10 == num && temp >= 7))
            {
                return INT_MAX;
            }
            if (flag && (INT_MAX / 10 < num || INT_MAX / 10 == num && temp >= 8))
            {
                return INT_MIN;
            }
            num = (c - '0') + num * 10;
        }
        if (flag)
        {
            num *= -1;
        }
        return num;
    }
};