class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        int t_size = static_cast<int>(t.size());
        int s_size = static_cast<int>(s.size());

        for(char& ch: t) {
            t_map[ch]++;
        }

        int correct_size = 0;
        int left = 0;
        string ans = "";

        for (int right=0; right<s_size; ++right) {
            s_map[s[right]]++;
            if (t_map.find(s[right]) != t_map.end()) {
                if (t_map[s[right]] >= s_map[s[right]])
                    ++correct_size;
                if (correct_size >= t_size) {
                    while (left < right && ((s_map[s[left]]-1) >= t_map[s[left]] || t_map[s[left]]==0)) {
                        s_map[s[left]]--;
                        ++left;
                    }
                    if (right-left+1 < ans.size() || ans == "")
                        ans = s.substr(left, right-left+1);
                }
            } else {
                continue;
            }
            
        }

        return ans;
        
    }
};