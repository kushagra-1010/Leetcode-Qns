class Solution {
public:
    void dfs(int st, vector<bool>& vis, vector<vector<int>>& isConnected) {
        vis[st] = true;

        for (int j = 0; j < isConnected[st].size(); j++) {
            if (!vis[j] && isConnected[st][j] == 1) {  // check adjacency
                dfs(j, vis, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, isConnected);
                count++;
            }
        }

        return count;
    }
};