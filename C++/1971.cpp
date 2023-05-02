class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int n): count(n) {
        for (int i=0; i<n; ++i) {
            parent.emplace_back(i);
            rank.emplace_back(1);
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x != parent_y) {
            if (rank[parent_x] < rank[parent_y]) {
                swap(parent_x, parent_y);
            }
            parent[parent_y] = parent_x;
            if (rank[parent_x] == rank[parent_y]) {
                rank[parent_x] += 1;
            }
            --count;
        }
    }

    int is_haspath(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (auto& edge: edges) {
            uf.unite(edge[0], edge[1]);
        }

        return uf.is_haspath(source, destination);
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<vector<int> > adj(n);
        for (auto& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        dfs(edges, visited, adj, source);
        return visited[destination];
        
    }

    void dfs(vector<vector<int>>& edges, vector<bool>& visited, vector<vector<int> >& adj, int source) {
        visited[source] = true;
        for (auto& ele: adj[source]) {
            if (!visited[ele]) {
                dfs(edges, visited, adj, ele);
            }
        }
        return;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<vector<int> > adj(n);
        for (auto& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        bfs(edges, visited, adj, source);
        return visited[destination];
        
    }

    void bfs(vector<vector<int>>& edges, vector<bool>& visited, vector<vector<int> >& adj, int source) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while (!q.empty()) {
            auto e = q.front();
            q.pop();
            for (auto& ele: adj[e]) {
                if (!visited[ele]) {
                    q.push(ele);
                    visited[ele] = true;
                }
            }
        }
        return;
    }
};