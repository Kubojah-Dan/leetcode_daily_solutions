from functools import lru_cache
from typing import List

class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stoneValue[i]

        @lru_cache(None)
        def solve(i, j):
            if i == j:
                return 0

            total = prefix[j + 1] - prefix[i]
            res = 0

            for k in range(i, j):
                left_sum = prefix[k + 1] - prefix[i]
                right_sum = total - left_sum

                if left_sum * 2 > total:

                    res = max(res, right_sum + solve(k + 1, j))

                    for k2 in range(k + 1, j):
                        r_sum = total - (prefix[k2 + 1] - prefix[i])
                        res = max(res, r_sum + solve(k2 + 1, j))
                    break

                elif left_sum * 2 < total:
                    res = max(res, left_sum + solve(i, k))
                else:
                    res = max(res, left_sum + max(solve(i, k), solve(k + 1, j)))

            return res

        return solve(0, n - 1)