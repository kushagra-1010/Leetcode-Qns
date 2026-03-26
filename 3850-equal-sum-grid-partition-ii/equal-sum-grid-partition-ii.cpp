#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        auto check = [&](vector<vector<int>>& g) -> bool {
            int m = g.size(), n = g[0].size();

            long long s1 = 0, s2 = 0;
            unordered_map<int,int> cnt1, cnt2;

            for (auto& row : g)
                for (int x : row) { s2 += x; cnt2[x]++; }

            for (int i = 0; i < m - 1; i++) {
                for (int x : g[i]) { s1 += x; s2 -= x; cnt1[x]++; cnt2[x]--; }

                if (s1 == s2) return true;

                if (s1 < s2) {
                    long long diff = s2 - s1;
                    if (diff > INT_MAX) continue;
                    int d = (int)diff;
                    if (cnt2[d] > 0) {
                        // bottom section is rows [i+1 .. m-1], border row = i+1
                        int botRows = m - i - 1;
                        if ((botRows > 1 && n > 1) ||
                            (i == m - 2 && (g[i+1][0] == d || g[i+1][n-1] == d)) ||
                            (n == 1 && (g[i+1][0] == d || g[m-1][0] == d)))
                            return true;
                    }
                } else {
                    long long diff = s1 - s2;
                    if (diff > INT_MAX) continue;
                    int d = (int)diff;
                    if (cnt1[d] > 0) {
                        // top section is rows [0 .. i], border row = i
                        int topRows = i + 1;
                        if ((topRows > 1 && n > 1) ||
                            (i == 0 && (g[0][0] == d || g[0][n-1] == d)) ||
                            (n == 1 && (g[0][0] == d || g[i][0] == d)))
                            return true;
                    }
                }
            }
            return false;
        };

        if (check(grid)) return true;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> tr(n, vector<int>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tr[j][i] = grid[i][j];

        return check(tr);
    }
};