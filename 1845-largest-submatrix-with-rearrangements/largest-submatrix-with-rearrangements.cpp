class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Step 1: build heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        
        int ans = 0;
        
        // Step 2: for each row, sort heights
        for (int i = 0; i < m; i++) {
            vector<int> row = matrix[i];
            sort(row.begin(), row.end(), greater<int>());
            
            // Step 3: compute max area
            for (int j = 0; j < n; j++) {
                ans = max(ans, row[j] * (j + 1));
            }
        }
        
        return ans;
    }
};