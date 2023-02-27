class Solution {
public:
    string decodeString(string s) {
        stack<int> stk_digit;
        stack<string> stk_string;

        for (int i=0; i<s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                string digit_c = string(1, c);
                for(int j=i+1; j<s.size(); ++j) {
                    if (isdigit(s[j])) {
                        digit_c += string(1, s[j]);
                    } else {
                        i=j-1;
                        break;
                    }
                }
                int digit = stoi(digit_c);
                stk_digit.push(digit);
                continue;
            }
            if (c != ']') {
                string s_c = string(1, c);
                stk_string.push(s_c);
                continue;
            }
            if (c == ']') {
                string tmp = "";
                int digit = 1;
                while (!stk_string.empty()) {
                    string s = stk_string.top();
                    stk_string.pop();
                    if (s == "[") {
                        break;
                    }
                    tmp = s + tmp;
                }
                if (!stk_digit.empty()) {
                    digit = stk_digit.top();
                    stk_digit.pop();
                }
                string tmp2 = "";
                while (digit) {
                    tmp2 += tmp;
                    --digit;
                }
                stk_string.push(tmp2);
            }
        }

        string ans = "";
        while (!stk_string.empty()) {
            ans = stk_string.top() + ans;
            stk_string.pop();
        }
        return ans;
    }
};