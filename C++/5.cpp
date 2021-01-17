#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int s_size = s.size();
        vector<vector<bool>> dy_vecs(s_size, vector<bool>(s_size, false));

        int left_index = 0;
        int max_len = 0;
        int distance = 0;

        while (distance < s_size)
        {
            for (int i = 0; i + distance < s_size; ++i)
            {
                int j = i + distance;
                if (distance == 0)
                {
                    dy_vecs[i][j] = true;
                }
                else if (distance == 1)
                {
                    if (s[i] == s[j])
                    {
                        dy_vecs[i][j] = true;
                    }
                }
                else
                {
                    dy_vecs[i][j] = dy_vecs[i + 1][j - 1] && s[i] == s[j];
                }
                if (dy_vecs[i][j])
                {
                    if (distance + 1 > max_len)
                    {
                        left_index = i;
                        max_len = distance + 1;
                        //break;
                    }
                }
            }
            ++distance;
        }
        string max_s = s.substr(left_index, max_len);
        return max_s;
    }
};
