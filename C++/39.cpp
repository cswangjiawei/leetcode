class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> combine;
        dfs(result, target, candidates, 0, combine);
        return result;
    }

    void dfs(vector<vector<int> >& result, int target, vector<int>& candidates, int idx, vector<int>& combine)
    {
        if (idx == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            result.emplace_back(combine);
            return;
        }

        dfs(result, target, candidates, idx + 1, combine);
        if (target - candidates[idx] >= 0 )
        {
            combine.emplace_back(candidates[idx]);
            dfs(result, target - candidates[idx], candidates, idx, combine);
            combine.pop_back();
        }
        
    }
};