class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        bool going_down = true;
        vector<string> vec(numRows, "");
        int cur_row = 0;
        for (const auto &c: s)
        {
            vec[cur_row] += string(1, c);
            if (going_down) 
            {
                cur_row += 1;
            }
            else
            {
                cur_row -= 1;
            }
            if (cur_row == 0 || cur_row == numRows - 1)
            {
                going_down = !going_down;
            }
        }
        string result;
        for (const auto &str: vec)
        {
            result += str;
        }
        return result;
    }
};