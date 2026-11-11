class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        def bound(need_a: int, cost_a: int, need_b: int, cost_b: int) -> int:
            price_a = min(cost_a, costBoth)
            price_b = min(cost_b, costBoth - price_a)
            return need_a * price_a + need_b * price_b

        return max(bound(need1, cost1, need2, cost2), bound(need2, cost2, need1, cost1))