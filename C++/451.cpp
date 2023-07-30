class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char& ch:s) {
            ++mp[ch];
        }

        priority_queue<pair<char,int>, vector<pair<char,int> >, decltype(&compare)> queue(compare);
        for (auto& ele: mp) {
            queue.push(ele);
        }

        string ans;
        while (!queue.empty()) {
            auto tmp = queue.top();
            ans += string(tmp.second, tmp.first);
            queue.pop();
        }

        return ans;

        
    }
    static bool compare(const pair<char, int>& pair1, const pair<char, int>& pair2) {
        return pair1.second < pair2.second;
    }
};