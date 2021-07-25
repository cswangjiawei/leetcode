class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        unordered_map<string, vector<string> > res_map;
        for (const auto &str: strs)
        {
            auto temp = str;
            sort(temp.begin(), temp.end());
            res_map[temp].emplace_back(str);
        }

        for (const auto &e: res_map)
        {
            result.emplace_back(e.second);
        }

        return result;
    }
};