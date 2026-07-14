class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:

        MOD = 10**9 + 7
        n = len(nums)

        @cache
        def dp(i, g1, g2):
            if i == n:
                return 1 if g1 == g2 and g1 > 0 else 0

            res = dp(i + 1, g1, g2)

            new_g1 = nums[i] if g1 == 0 else math.gcd(g1, nums[i])
            res = (res + dp(i + 1, new_g1, g2)) % MOD

            new_g2 = nums[i] if g2 == 0 else math.gcd(g2, nums[i])
            res = (res + dp(i + 1, g1, new_g2)) % MOD

            return res

        return dp(0, 0, 0)