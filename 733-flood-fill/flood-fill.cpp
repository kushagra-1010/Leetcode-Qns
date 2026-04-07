class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans,
             int i, int j, int color, int original) {

        int n = image.size();
        int m = image[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (image[i][j] != original) return;
        if (ans[i][j] == color) return;

        ans[i][j] = color;

        dfs(image, ans, i+1, j, color, original);
        dfs(image, ans, i-1, j, color, original);
        dfs(image, ans, i, j+1, color, original);
        dfs(image, ans, i, j-1, color, original);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;

        int original = image[sr][sc];

        if (original == color) return image;

        dfs(image, ans, sr, sc, color, original);

        return ans;
    }
};