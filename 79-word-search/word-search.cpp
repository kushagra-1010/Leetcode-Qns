class Solution {
public:

    bool dfs(vector<vector<char>>& board,
             int i, int j,
             int idx,
             string& word,
             int m, int n,
             vector<vector<bool>>& vis) {

        if (idx == word.length()) {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n ||
            board[i][j] != word[idx] ||
            vis[i][j]) {
            return false;
        }

        vis[i][j] = true;

        bool found =
            dfs(board, i + 1, j, idx + 1, word, m, n, vis) ||
            dfs(board, i - 1, j, idx + 1, word, m, n, vis) ||
            dfs(board, i, j + 1, idx + 1, word, m, n, vis) ||
            dfs(board, i, j - 1, idx + 1, word, m, n, vis);

        vis[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs(board, i, j, 0, word, m, n, vis)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};