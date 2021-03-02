class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, string> digit_letter = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> combinations;
        if (digits.empty()) {
            return combinations;
        }
        string combination;
        backtrack(digits, digit_letter, combination, combinations, 0);
        return combinations;
    }

    void backtrack(const string &digits, unordered_map<char, string> &digit_letter, string &combination,  vector<string> &combinations, int index)
    {
        if (index == digits.size())
        {
            combinations.emplace_back(combination);
            return;
        }
        string letters = digit_letter.at(digits[index]);
        for(char &letter: letters)
        {
            combination.push_back(letter);
            backtrack(digits, digit_letter, combination, combinations, index+1);
            combination.pop_back();
        }
    }

    
};