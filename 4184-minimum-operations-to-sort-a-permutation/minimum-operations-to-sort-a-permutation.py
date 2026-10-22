class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
        
        idx = nums.index(0)

        is_inc = all(nums[(idx + i) % n] == i for i in range(n))
        is_dec = all(nums[(idx - i + n) % n] == i for i in range(n))

        if not is_inc and not is_dec:
            return -1

        ans = float('inf')

        if is_inc:
            ans = min(ans, idx)
            ans = min(ans, 1 + (n - idx) + 1)
        if is_dec:
            ans = min(ans, 1 + (n - 1 - idx))
            ans = min(ans, ((idx + 1) % n) + 1)

        return ans