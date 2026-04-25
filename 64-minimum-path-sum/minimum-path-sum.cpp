class Solution {
public:
    int solveMem(vector<vector<int>>& grid, int i, int j,
                 vector<vector<int>>& dp) {

        if (i == 0 && j == 0)
            return grid[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = INT_MAX;
        if (i > 0)
            up = grid[i][j] + solveMem(grid, i - 1, j, dp);

        int left = INT_MAX;
        if (j > 0)
            left = grid[i][j] + solveMem(grid, i, j - 1, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solveMem(grid, m - 1, n - 1, dp);
    }
};
