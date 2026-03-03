class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n,int &peri){
        if(i < 0 || j < 0 || i>=m || j>=n || grid[i][j] == 0){
            peri++;
            return;
        }

        if(grid[i][j] == -1) return;

        grid[i][j] = -1;
        dfs(grid,i+1,j,m,n,peri);
        dfs(grid,i-1,j,m,n,peri);
        dfs(grid,i,j+1,m,n,peri);
        dfs(grid,i,j-1,m,n,peri);

    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int peri=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j,m,n,peri);
                    return peri;
                }
            }
        }

        return -1;
    }
};