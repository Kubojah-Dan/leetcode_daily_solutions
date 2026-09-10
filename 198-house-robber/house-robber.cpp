class Solution {
public:
    int fn(vector<int>& nums, int n, vector<int>& dp){
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int rob = nums[n] + fn(nums, n - 2, dp);
        int skip = fn(nums, n - 1, dp);

        return dp[n] = max(rob, skip);
    }
 
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n + 2, -1);
        return fn(nums, n - 1, dp);
    }
};