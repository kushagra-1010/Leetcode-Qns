class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> oneRow(m,0), oneCol(n,0);
        vector<int> zeroRow(m,0), zeroCol(n,0);

        // count ones and zeros in rows and columns
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    oneRow[i]++;
                    oneCol[j]++;
                }else{
                    zeroRow[i]++;
                    zeroCol[j]++;
                }
            }
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }

        return ans;
    }
};