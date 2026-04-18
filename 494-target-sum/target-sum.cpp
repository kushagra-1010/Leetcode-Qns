class Solution {
public:
    int solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case
        if(idx == 0) {
            if(target == 0 && nums[0] == 0) return 2; // +0, -0
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = solve(idx-1, target, nums, dp);

        int take = 0;
        if(nums[idx] <= target)
            take = solve(idx-1, target - nums[idx], nums, dp);

        return dp[idx][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int x : nums) total += x;

        if((total + target) % 2 != 0 || total < abs(target)) return 0;

        int s1 = (total + target) / 2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));

        return solve(n-1, s1, nums, dp);
    }
};