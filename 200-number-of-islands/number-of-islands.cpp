class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int m,int n,vector<vector<int>>& vis){
        if(i >= m || i < 0 || j >= n || j < 0 || vis[i][j] == true || grid[i][j] == '0'){
            return;
        }

        vis[i][j] = true;

        dfs(grid,i+1,j,m,n,vis);
        dfs(grid,i-1,j,m,n,vis);
        dfs(grid,i,j+1,m,n,vis);
        dfs(grid,i,j-1,m,n,vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,false));

        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    islands++;
                    dfs(grid,i,j,m,n,vis);
                }
            }
        }

        return islands;
    }
};