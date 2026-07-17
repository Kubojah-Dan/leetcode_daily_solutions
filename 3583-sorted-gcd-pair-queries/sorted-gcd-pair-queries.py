from typing import List
import bisect

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        max_val = max(nums)

        counts = [0] * (max_val + 1)
        for num in nums:
            counts[num] += 1

        gcd_pairs = [0] * (max_val + 1)
        for i in range(max_val, 0, -1):
            multiples_count = 0
            for j in range(i, max_val + 1, i):
                multiples_count += counts[j]

            total_pairs = (multiples_count * (multiples_count - 1)) // 2
            for j in range(2 * i, max_val + 1, i):
                total_pairs -= gcd_pairs[j]
            
            gcd_pairs[i] = total_pairs

        prefix_sums = [0] * (max_val + 1)
        for i in range(1, max_val + 1):
            prefix_sums[i] = prefix_sums[i - 1] + gcd_pairs[i]

        ans = []
        for q in queries:
            gcd_val = bisect.bisect_right(prefix_sums, q)
            ans.append(gcd_val)

        return ans