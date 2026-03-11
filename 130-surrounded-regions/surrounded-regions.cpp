class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O' || vis[i][j])
            return;

        vis[i][j] = 1;

        dfs(board, vis, i+1, j);
        dfs(board, vis, i-1, j);
        dfs(board, vis, i, j+1);
        dfs(board, vis, i, j-1);
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // first & last column
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O')
                dfs(board, vis, i, 0);

            if(board[i][n-1] == 'O')
                dfs(board, vis, i, n-1);
        }

        // first & last row
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O')
                dfs(board, vis, 0, j);

            if(board[m-1][j] == 'O')
                dfs(board, vis, m-1, j);
        }

        // flip surrounded regions
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};