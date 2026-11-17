class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        const int INF = 1e9;

        vector<vector<int>> divisors(n + 1);
        for(int len = 2; len <= n; ++len){
            for(int d = 1; d * d <= len; ++d){
                if(len % d == 0){
                    divisors[len].push_back(d);
                    if(d != 1 && d * d != len){
                        divisors[len].push_back(len / d);
                    }
                }
            }
        }
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int len = j - i + 1;
                for(int d : divisors[len]){
                    int changes = 0;
                    for(int offset = 0; offset < d; ++offset){
                        int left = i + offset;
                        int right = j - (d - 1 - offset);
                        while(left < right){
                            if(s[left] != s[right]){
                                changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for(int p = 1; p <= k; ++p){
            for(int i = 2 * p; i <= n; ++i){
                for(int m = 2 * (p - 1); m <= i - 2; ++m){
                if(dp[p - 1][m] != INF){
                    dp[p][i] = min(dp[p][i], dp[p - 1][m] + cost[m][i - 1]);
                }
            }
            }
        }
        return dp[k][n];
    }
};