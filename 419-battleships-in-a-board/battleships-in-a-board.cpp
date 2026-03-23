class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int m,int n,int i,int j){
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || board[i][j] == '.'){
            return;
        }
        vis[i][j] = 1;
        dfs(board,vis,m,n,i+1,j);
        dfs(board,vis,m,n,i-1,j);
        dfs(board,vis,m,n,i,j+1);
        dfs(board,vis,m,n,i,j-1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ships = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X' && !vis[i][j]){
                    dfs(board,vis,m,n,i,j);
                    ships++;
                }
            }
        }
        return ships;
    }
};