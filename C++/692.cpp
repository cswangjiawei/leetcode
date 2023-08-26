class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int > word_count;
        for (auto& word: words) {
            word_count[word]++;
        }

        vector<pair<string, int> > vec_word_count;
        for (auto& ele: word_count) {
            vec_word_count.push_back(ele);
        }

        auto compare = [](pair<string, int>&a, pair<string, int>&b) {
            if (a.second < b.second)
                return false;
            if (a.second > b.second)
                return true;
            if (a.second == b.second && a.first > b.first) 
                return false;
            else
                return true;
        };

        sort(vec_word_count.begin(), vec_word_count.end(), compare);
        vector<string> ans;
        int i = 0;
        for (auto &[word, count]: vec_word_count) {
            ans.emplace_back(word);
            ++i;
            if (i == k) {
                break;
            }
        }
        return ans;
    }
};