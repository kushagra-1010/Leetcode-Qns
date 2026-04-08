class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj){
        int n = adj.size();
        vector<int> indegree(n, 0);

        // Calculate indegree
        for(int i = 0; i < n; i++){
            for(int v : adj[i]){
                indegree[v]++;
            }
        }

        queue<int> q;

        // Push nodes with 0 indegree
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return topo;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Build graph
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> ans = topoSort(adj);

        // If cycle exists
        if(ans.size() != numCourses){
            return {};
        }

        return ans;
    }
};