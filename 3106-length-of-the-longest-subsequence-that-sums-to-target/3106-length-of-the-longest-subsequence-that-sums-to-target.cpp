class Solution {
public:
    int solve(vector<int>& nums, int i, int target, vector<vector<int>>&dp, int n) {
        if(i==n) {
            if(target==0) 
                return 0;
            return INT_MIN;
        }

        if(dp[i][target]!=-1)
            return dp[i][target];

        int take = INT_MIN;
        if(target>=nums[i])
            take = 1 + solve(nums, i+1, target-nums[i], dp, n);

        int notTake = 0 + solve(nums, i+1, target, dp, n);

        return dp[i][target] = max(take, notTake);
    } 
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        int ans = solve(nums, 0, target, dp, n);
        return ans < 0 ? -1 : ans;
    }
};