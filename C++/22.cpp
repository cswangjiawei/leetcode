class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;
        generate_brackets(0, 0, 0, n, str, result);
        return result;
    }

    void generate_brackets(int left_bracket, int right_bracket, int idx, int n, string &str, vector<string> &result)
    {
        if (idx == 2 * n)
        {
            result.emplace_back(str);
            return;
        }
        if (left_bracket < n)
        {
            str.push_back('(');
            generate_brackets(left_bracket+1, right_bracket, idx + 1, n, str, result);
            str.pop_back();
        }
        if (right_bracket < left_bracket && left_bracket <= n)
        {
            str.push_back(')');
            generate_brackets(left_bracket, right_bracket + 1, idx + 1, n, str, result);
            str.pop_back();
        }
    }
};