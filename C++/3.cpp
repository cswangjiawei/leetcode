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


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set1;
        int left = 0;
        int ans = 0;
        for (auto& ch: s) {
            if (set1.count(ch)==0) {
                set1.insert(ch);
            } else {
                int set_len = set1.size();
                if (set_len > ans) {
                    ans = set_len;
                }
                while(set1.count(ch)) {
                    set1.erase(s[left++]);
                }
                set1.insert(ch);
            }
        }

        if (set1.size() > ans) {
            ans = set1.size();
        }

        return ans;
    }
};