class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(
            zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );

        dp[0][0][0] = dp[0][0][1] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                // place 0
                for (int k = 1; k <= limit && i - k >= 0; k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
                }

                // place 1
                for (int k = 1; k <= limit && j - k >= 0; k++) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};