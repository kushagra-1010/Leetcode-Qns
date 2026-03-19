class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // prefix sums for X and Y
        vector<vector<int>> px(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> py(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                px[i][j] = px[i-1][j] + px[i][j-1] - px[i-1][j-1];
                py[i][j] = py[i-1][j] + py[i][j-1] - py[i-1][j-1];

                if (grid[i-1][j-1] == 'X') px[i][j]++;
                if (grid[i-1][j-1] == 'Y') py[i][j]++;
            }
        }

        int ans = 0;

        // submatrix must start at (0,0)
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int x = px[i][j];
                int y = py[i][j];

                if (x > 0 && x == y) {
                    ans++;
                }
            }
        }

        return ans;
    }
};