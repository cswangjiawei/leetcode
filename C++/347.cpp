class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map1;
        for (int &num: nums) {
            if (map1.find(num) == map1.end()) {
                map1[num] = 0;
            }
            map1[num] += 1;
        }

        vector<pair<int, int> > vec;
        for (auto &e: map1) {
            vec.push_back(e);
        }

        sort(vec.begin(), vec.end(), compare);

        vector<int> ans;
        for(int i=0; i<k; ++i) {
            ans.emplace_back(vec[i].first);
        }

        return ans;
    }

    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};