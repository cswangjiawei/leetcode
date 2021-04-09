class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

    void backtrack(vector<int> &candidates, int target, int idx, vector<int> &combination, 
                    vector<vector<int> > &result)
    {
        if (target==0)
        {
            result.emplace_back(combination);
            return;
        }
        if (idx>=candidates.size())
        {
            return;
        }
        if (target-candidates[idx] >= 0)
        {
            combination.push_back(candidates[idx]);
            backtrack(candidates, target-candidates[idx], idx+1, combination, result);
            combination.pop_back();
        }
        while(idx+1<candidates.size() && candidates[idx] == candidates[idx+1])
        {
            ++idx;
        }
        backtrack(candidates, target, idx+1, combination, result);
    }
};