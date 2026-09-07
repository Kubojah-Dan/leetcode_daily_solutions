class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        total = 0
        last_added = [0] * 26

        for char in s:
            idx = ord(char) - ord('a')
            new_subseqs = (total + 1 - last_added[idx]) % MOD
            total = (total + new_subseqs) % MOD
            last_added[idx] = (last_added[idx] + new_subseqs) % MOD

        return total