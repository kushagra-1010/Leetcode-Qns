class Solution {
public:

    void solve(vector<int>& nums,
               int n,
               vector<int>& curr,
               vector<vector<int>>& ans,
               int idx) {

        if (idx >= n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(nums, n, curr, ans, idx + 1);
        curr.pop_back();

        solve(nums, n, curr, ans, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        int n = nums.size();

        solve(nums, n, curr, ans, 0);

        return ans;
    }
};