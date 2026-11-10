class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for(int j = 1; j <= n; j++){
            for(int i = max(0, j - 3); i < j; ++i){
                int jump_cost = costs[j - 1] + (j - i) * (j - i);
                dp[j] = min(dp[j], dp[i] + jump_cost);
            }
        }
        return dp[n];
    }
};