class Solution:
    def maxProduct(self, n: int) -> int:
        nums = sorted(str(n))
        return int(nums[-1]) * int(nums[-2])


