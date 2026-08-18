from collections import Counter
from typing import List

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)
        counts = Counter(nums)

        if k == 1:
            valid = [num for num, count in counts.items() if count == 1]
            return max(valid) if valid else -1

        if k == n:
            return max(nums)

        ans = -1
        if counts[nums[0]] == 1:
            ans = max(ans, nums[0])
        if counts[nums[-1]] == 1:
            ans = max(ans, nums[-1])

        return ans