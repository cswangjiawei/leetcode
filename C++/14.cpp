class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        bool flag = true;
        while (flag)
        {
            for (int j = 1; j < strs.size(); ++j)
            {
                if (i < strs[j].size())
                {
                    if (strs[j][i] != strs[j-1][i])
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (strs.size() == 0 || strs.size() == 1)
            {
                flag = false;
            }
            if (flag)
            {
                ++i;
            }
        }

        string result = "";
        if (strs.size() > 1)
        {
            result = strs[0].substr(0, i);
        }
        if (strs.size() == 1)
        {
            result = strs[0];
        }
        return result;
    }
};