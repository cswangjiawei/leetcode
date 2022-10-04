class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_set<char> tmp_set;
        vector<char> tmp_vec;
        int i = 0;
        for(char& c: s) {
            if (tmp_set.count(c) == 0) {
                tmp_set.insert(c);
                tmp_vec.emplace_back(c);
                if (tmp_set.size() > max_length) {
                    max_length = tmp_set.size();
                }
            } else {
                while(tmp_set.count(c)) {
                    tmp_set.erase(tmp_vec[i]);
                    ++i;
                }
                tmp_set.insert(c);
                tmp_vec.emplace_back(c);
                if (tmp_set.size() > max_length) {
                    max_length = tmp_set.size();
                }
            }
        }
        return max_length;

    }
};