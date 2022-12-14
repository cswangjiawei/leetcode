class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for(auto &word: wordDict) {
            wordSet.insert(word);
        }
        
        vector<bool> dy_vec(s.size());
        if (wordSet.find(s.substr(0,1)) != wordSet.end()) {
            dy_vec[0] = true;
        }
        for(int i=1; i < s.size(); ++i) {
            for(int j=0; j<=i; ++j) {
                if(j < i) {
                    auto tmp = s.substr(j+1, i-j);
                    bool is_in;
                    if(wordSet.find(tmp) != wordSet.end()) {
                        is_in = true;
                    } else {
                        is_in = false;
                    }
                    dy_vec[i] = (dy_vec[j] && is_in);
                    if (dy_vec[i]) {
                        break;
                    }
                } else {
                    auto tmp = s.substr(0, i+1);
                     if(wordSet.find(tmp) != wordSet.end()) {
                        dy_vec[i] = true;
                        break;
                    }
                }

            }
        }
        return dy_vec[s.size()-1];
        
    }

};