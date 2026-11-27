class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;
        int n = static_cast<int>(items.size());

        vector<int> divCount(MAXF + 1, 0);
        for (const auto& item : items) {
            int f = item[0];
            for (int d = 1; d * d <= f; ++d) {
                if (f % d == 0) {
                    divCount[d]++;
                    if (d * d != f) {
                        divCount[f / d]++;
                    }
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (const auto& item : items) {
            int f = item[0];
            int price = item[1];
            int freeBonus = divCount[f] - 1;

            vector<int> nextDp = dp;
            for (int b = budget; b >= price; --b) {
                nextDp[b] = max(nextDp[b], dp[b - price] + 1 + freeBonus);
            }

            for (int b = price; b <= budget; ++b) {
                nextDp[b] = max(nextDp[b], nextDp[b - price] + 1);
            }

            dp = move(nextDp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};