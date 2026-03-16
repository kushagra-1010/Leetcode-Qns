#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        set<int> st;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // size = 0 (single cell)
                st.insert(grid[r][c]);

                // try bigger rhombus
                for (int k = 1; r-k >= 0 && r+k < m && c-k >= 0 && c+k < n; k++) {

                    int sum = 0;

                    int x = r - k;
                    int y = c;

                    // 4 sides
                    for (int i = 0; i < k; i++) {
                        sum += grid[x + i][y - i];
                    }

                    for (int i = 0; i < k; i++) {
                        sum += grid[r + i][c - k + i];
                    }

                    for (int i = 0; i < k; i++) {
                        sum += grid[r + k - i][c + i];
                    }

                    for (int i = 0; i < k; i++) {
                        sum += grid[r - i][c + k - i];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;

        for (auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};