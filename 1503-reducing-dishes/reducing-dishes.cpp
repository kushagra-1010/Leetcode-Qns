class Solution {
public:
    int solveMem(vector<int>& arr, int idx, int n, vector<vector<int>>& dp, int time){
        if(idx == n) return 0;

        if(dp[idx][time] != -1) return dp[idx][time];

        int take = arr[idx] * time + solveMem(arr, idx+1, n, dp, time+1);
        int noTake = solveMem(arr, idx+1, n, dp, time);

        return dp[idx][time] = max(take, noTake);
    }

    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solveMem(arr, 0, n, dp, 1);
    }
};