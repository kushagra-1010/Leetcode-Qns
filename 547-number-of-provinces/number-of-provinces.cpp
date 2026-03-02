class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;

        for(int& neighbor : adj[node]) {
            if(!vis[neighbor]) {
                dfs(neighbor, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int count = 0;

        // Build adjacency list
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // DFS
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                count++;
            }
        }

        return count;
    }
};