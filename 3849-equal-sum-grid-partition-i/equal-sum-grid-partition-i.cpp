class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;

        // total sum
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        long long sum = 0;

        // Horizontal cut
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                sum += grid[i][j];
            }

            if(sum * 2 == total)
                return true;
        }

        sum = 0;

        // Vertical cut
        for(int j = 0; j < n - 1; j++) {
            for(int i = 0; i < m; i++) {
                sum += grid[i][j];
            }

            if(sum * 2 == total)
                return true;
        }

        return false;
    }
};