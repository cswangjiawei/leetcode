class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> bracket_map = { {')', '('},
                                                  {']', '['},
                                                  {'}', '{'} };
        
        stack<char> stk;
        for (const auto &c: s) 
        {
            if (bracket_map.find(c) != bracket_map.end()) 
            {
                if (stk.empty() || stk.top() != bracket_map[c]) 
                {
                    return false;
                }
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};