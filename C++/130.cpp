class Solution {
private:
    vector<vector<int> > direction = {{1,0}, {-1, 0}, {0, 1}, {0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if ((i==0 || i==m-1 || j==0 || j==n-1) && !visited[i][j] && board[i][j]=='O') {
                    dfs(board, visited, i, j);
                }
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j]=='O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool> >& visited, int i, int j) {
        visited[i][j] = true;
        for (auto& direct: direction) {
            int next_i = i + direct[0];
            int next_j = j + direct[1];
            if (next_i<0 || next_i>=board.size() || next_j<0 || next_j>=board[0].size() || visited[next_i][next_j] || board[i][j]=='X') {
                continue;
            }
            dfs(board, visited, next_i, next_j);
        }
        return;
    }

};