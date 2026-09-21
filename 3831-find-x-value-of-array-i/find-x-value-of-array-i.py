class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * k
        dp = [0] * k

        for num in nums:
            val = num % k
            next_dp = [0] * k

            for r in range(k):
                if dp[r] > 0:
                    next_dp[(r * val) % k] += dp[r]

            next_dp[val] += 1

            for r in range(k):
                ans[r] += next_dp[r]

            dp = next_dp

        return ans