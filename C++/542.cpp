class Solution {
struct Point {
    Point(int x, int y): x(x), y(y) {}
    int x;
    int y;
};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<Point> que;
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int> > ans(row, vector<int>(col));
        vector<vector<int> > visited(row, vector<int>(col));
        for (int i=0; i<row; ++i) {
            for (int j=0; j<col; ++j) {
                if (!mat[i][j]) {
                    que.push(Point(i, j));
                    ans[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }

        while (!que.empty()) {
            auto point = que.front();
            que.pop();
            int x = point.x;
            int y = point.y;
            if (x+1 < row && !visited[x+1][y]) {
                ans[x+1][y] = ans[x][y] + 1;
                que.push(Point(x+1, y));
                visited[x+1][y] = 1;
            }
            if (x-1 >= 0 && !visited[x-1][y]) {
                ans[x-1][y] = ans[x][y] + 1;
                que.push(Point(x-1, y));
                visited[x-1][y] = 1;
            }
            if (y+1 < col && !visited[x][y+1]) {
                ans[x][y+1] = ans[x][y] + 1;
                que.push(Point(x, y+1));
                visited[x][y+1] = 1;
                
            }
            if (y-1 >= 0 && !visited[x][y-1]) {
                ans[x][y-1] = ans[x][y] + 1;
                que.push(Point(x, y-1));
                visited[x][y-1] = 1;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int> > dist(m, vector<int>(n, INT_MAX/2));

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i-1>=0) {
                        dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    }
                    if (j-1>=0) {
                        dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                    }
                }
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=n-1; j>=0; --j) {
                if (mat[i][j]==0) {
                    dist[i][j] = 0;
                } else {
                    if (i-1>=0) {
                         dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    }
                    if (j+1<n) {
                        dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
                    }
                }
            }
        }

        for (int i=m-1; i>=0; --i) {
            for (int j=0; j<n; ++j) {
                if (i+1<m) {
                    dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                }
                if (j-1>=0) {
                    dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }
        }

        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                if (i+1<m) {
                    dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                }
                if (j+1<n) {
                    dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
                }
            }
        }

        return dist;
    }
};