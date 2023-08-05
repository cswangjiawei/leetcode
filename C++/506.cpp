class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int> > vecs;
        for(int i=0; i<score.size(); ++i) {
            vecs.emplace_back(make_pair(-score[i], i));
        }

        vector<string> title = {"Gold Medal","Silver Medal","Bronze Medal"};

        sort(vecs.begin(), vecs.end());
        
        vector<string> ans(vecs.size());

        for (int i=0; i<vecs.size(); ++i) {
            if (i>=3) {
                ans[vecs[i].second] =  to_string(i+1);
            } else {
                ans[vecs[i].second] = title[i];
            }
        }

        return ans;
        
    }
};