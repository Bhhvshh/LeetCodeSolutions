

class Solution {
public:
    pair<int, int> bfs(vector<vector<int>>& adj, int src, vector<int>& color) {
        queue<int> q;
        q.push(src);
        bool white = true;
        color[src] = white + 1;
        int w = 1, b = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            white = !white;

            for (int i = 0; i < levelSize; i++) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) {
                    if (color[v] == 0) {
                        q.push(v);
                        color[v] = white + 1;
                        w+=white;
                        b+=!white;
                        
                    }
                }
            }
        }

        return {w, b};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);

        for (auto x : edges1) {
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }
        for (auto x : edges2) {
            adj2[x[0]].push_back(x[1]);
            adj2[x[1]].push_back(x[0]);
        }

        vector<int> colort2(m), colort1(n);
        auto t2Col = bfs(adj2, 0, colort2);
        auto t1Col = bfs(adj1, 0, colort1);

        vector<int> even1(n), odd2(m);
        int maxtree = 0;

        for (int i = 0; i < m; i++) {
            odd2[i] =   (colort2[i]==2) ?   t2Col.second:t2Col.first;
            maxtree = max(maxtree, odd2[i]);
        }
        

        for (int i = 0; i < n; i++) {
            even1[i]    =   (colort1[i]==2) ?   t1Col.first:t1Col.second;
            even1[i]+=maxtree;
        }

        return even1;
    }
};
