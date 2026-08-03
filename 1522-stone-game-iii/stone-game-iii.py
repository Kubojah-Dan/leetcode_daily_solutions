from functools import cache
from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        @cache
        def maxDiff(i: int) -> int:
            if i == n:
                return 0
            
            res = float('-inf')
            total = 0

            for k in range(1, 4):
                if i + k <= n:
                    total += stoneValue[i + k - 1]
                    res = max(res, total - maxDiff(i + k))

            return res

        diff = maxDiff(0)
        if diff > 0:
            return "Alice"
        elif diff < 0:
            return "Bob"
        else:
            return "Tie"