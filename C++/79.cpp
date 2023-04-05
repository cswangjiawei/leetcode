class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());
        int word_size = static_cast<int>(word.size());
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                bool flag = check(board, word, visit, m, n, i, j, 0, word_size);
                if (flag) {
                    return true;
                }
            }
        }

        return false;
    }

    bool check(vector<vector<char>>& board, string& word, vector<vector<bool> >& visit, int m, int n, int i, int j, int k, int word_size) {
        if (k==word_size) {
            return true;
        }
        if (board[i][j] != word[k]) {
            return false;
        }
        visit[i][j] = true;
        if (i+1<m && !visit[i+1][j]) {
            bool flag = check(board, word, visit, m, n, i+1, j, k+1, word_size);
            if (flag) {
                return true;
            }
        }

        if (i-1>=0 && !visit[i-1][j]) {
            bool flag = check(board, word, visit, m, n, i-1, j, k+1, word_size);
            if (flag) {
                return true;
            }
        }

        if (j+1<n && !visit[i][j+1]) {
            bool flag = check(board, word, visit, m, n, i, j+1, k+1, word_size);
            if (flag) {
                return true;
            }
        }

        if (j-1>=0 && !visit[i][j-1]) {
            bool flag = check(board, word, visit, m, n, i, j-1, k+1, word_size);
            if (flag) {
                return true;
            }
        }
        
        visit[i][j] = false;
        if (k+1 == word_size) {
            return true;
        }
        return false;
    } 
};