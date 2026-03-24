class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int k = n * m;

        vector<int> arr;
        for (auto &r : grid)
            for (int x : r)
                arr.push_back(x % mod);

        vector<int> pref(k,1), suff(k,1);

        for (int i = 1; i < k; i++)
            pref[i] = (pref[i-1] * arr[i-1]) % mod;

        for (int i = k-2; i >= 0; i--)
            suff[i] = (suff[i+1] * arr[i+1]) % mod;

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < k; i++) {
            int val = (pref[i] * suff[i]) % mod;
            ans[i/m][i%m] = val;
        }

        return ans;
    }
};