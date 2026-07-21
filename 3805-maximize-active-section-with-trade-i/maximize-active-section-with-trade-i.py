class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        ones = 0
        prev_zero_group = float("-inf")
        max_merge = 0

        i = 0
        n = len(s)

        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            length = j - i

            if s[i] == '1':
                ones += length
            else:
                max_merge = max(max_merge, prev_zero_group + length)
                prev_zero_group = length

            i = j
        return ones + max_merge