class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7

        bit_counts = [0] * 30
        for num in nums:
            for bit in range(30):
                if (num >> bit) & 1:
                    bit_counts[bit] += 1

        total_sum = 0

        for _ in range(k):
            val = 0
            for bit in range(30):
                if bit_counts[bit] > 0:
                    val |= 1 << bit
                    bit_counts[bit] -= 1

            total_sum = (total_sum + val * val) % MOD

        return total_sum