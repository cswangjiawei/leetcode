class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) {
            return true;
        }
        for(int i=1; i<s.size() - 1; ++i) {
            if(wordBreak(s.substr(0, i), wordDict) && wordBreak(s.substr(i, s.size()-i), wordDict)) {
                return true;
            }
        }
        return false;

    }

};