class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> tmp;

        my_combine(ans, tmp, 1, n, k);
        return ans;

    }

    void my_combine(vector<vector<int> >& ans, vector<int>& tmp, int index, int n, int k) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if (index > n) {
            return;
        }

        tmp.emplace_back(index);
        my_combine(ans, tmp, index+1, n, k);
        tmp.pop_back();

        my_combine(ans, tmp, index+1, n, k);

    }
};