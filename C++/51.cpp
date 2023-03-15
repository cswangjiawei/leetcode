class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> col_set;
        unordered_set<int> diagnoal_set_1;
        unordered_set<int> diagnoal_set_2;

        vector<int> tmp;
        vector<vector<string> > ans;
        my_solveQueens(ans, tmp, col_set, diagnoal_set_1, diagnoal_set_2, 0, n);
        return ans;

    }

    void my_solveQueens(vector<vector<string> >& ans, vector<int>& tmp, unordered_set<int>& col_set, unordered_set<int>& diagnoal_set_1, unordered_set<int>& diagnoal_set_2, int row, int n) {
        if (row == n) {
            place_queen(ans, tmp, n);
            return;
        }
        for (int i=0; i<n; ++i) {
            if (col_set.find(i) != col_set.end()) {
                continue;
            }
            int andd = row + i;
            if (diagnoal_set_1.find(andd) != diagnoal_set_1.end()) {
                continue;
            }
            int difference = row - i;
            if (diagnoal_set_2.find(difference) != diagnoal_set_2.end()) {
                continue;
            }

            col_set.insert(i);
            diagnoal_set_1.insert(andd);
            diagnoal_set_2.insert(difference);
            tmp.emplace_back(i);

            my_solveQueens(ans, tmp, col_set, diagnoal_set_1, diagnoal_set_2, row+1, n);

            col_set.erase(i);
            diagnoal_set_1.erase(andd);
            diagnoal_set_2.erase(difference);
            tmp.pop_back();  
        }

        return;

    }

    void place_queen(vector<vector<string> >& ans, vector<int>& tmp, int n) {
        vector<string> e_str;
        for(int &val: tmp) {
            string s = string(n, '.');
            s[val] = 'Q';
            e_str.push_back(s);
        }
        ans.push_back(e_str);
    }
};