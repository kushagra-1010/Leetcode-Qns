class Solution {
    const int MOD = 1e9 + 7;
    int lim;
    vector<vector<array<long long, 2>>> memo;

    long long dfs(int i, int j, int k) {
        // Base: out of bounds → invalid
        if (i < 0 || j < 0) return 0;
        // Base: no zeros left → only valid if placing 1s within limit
        if (i == 0) return (k == 1 && j <= lim) ? 1 : 0;
        // Base: no ones left → only valid if placing 0s within limit
        if (j == 0) return (k == 0 && i <= lim) ? 1 : 0;

        long long& res = memo[i][j][k];
        if (res != -1) return res;

        if (k == 0) {
            // Place a 0: came from either 0 or 1, minus illegal run of limit+1 zeros
            res = (dfs(i-1, j, 0) + dfs(i-1, j, 1) - dfs(i-lim-1, j, 1) + MOD) % MOD;
        } else {
            // Place a 1: came from either 0 or 1, minus illegal run of limit+1 ones
            res = (dfs(i, j-1, 0) + dfs(i, j-1, 1) - dfs(i, j-lim-1, 0) + MOD) % MOD;
        }
        return res;
    }

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        lim = limit;
        memo.assign(zero + 1, vector<array<long long, 2>>(one + 1, {-1LL, -1LL}));
        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
    }
};