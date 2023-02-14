class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set;
        for(string& word: wordDict) {
            word_set.insert(word);
        }

        int n = static_cast<int>(s.size());
        vector<bool> dy_vec(n, false);

        string s_0 = s.substr(0, 1);
        if (word_set.find(s_0) != word_set.end()) {
            dy_vec[0] = true;
        }

        for(int i=1; i<n; ++i) {
            string si = s.substr(0, i+1);
            if (word_set.find(si) != word_set.end()) {
                dy_vec[i] = true;
                continue;
            }
            for (int j=0; j<i; ++j) {
                if (dy_vec[i]) {
                    break;
                }
                string sj = s.substr(j+1, i-j);
                bool flag = false;
                if (word_set.find(sj) != word_set.end()) {
                    flag = true;
                }
                dy_vec[i] = dy_vec[j] && flag;
            }
        }
        return dy_vec[n-1];

    }
};