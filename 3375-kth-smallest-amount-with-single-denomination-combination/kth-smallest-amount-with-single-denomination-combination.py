import math
from itertools import combinations
from typing import List

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        n = len(coins)

        subsets = []
        for r in range(1, n + 1):
            sign = 1 if r % 2 == 1 else -1
            for combo in combinations(coins, r):
                current_lcm = combo[0]
                for coin in combo[1:]:
                    current_lcm = math.lcm(current_lcm, coin)
                subsets.append((current_lcm, sign))

        def count_amount_le(x: int) -> int:
            total = 0
            for lcm_val, sign in subsets:
                total += sign * (x // lcm_val)
            return total
        low = 1
        high = min(coins) * k
        ans = high

        while low <= high:
            mid = (low + high) // 2
            if count_amount_le(mid) >= k:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans