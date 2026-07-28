class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        half_len = n // 2

        sorted_half = "".join(sorted(s[:half_len]))

        middle = s[half_len] if n % 2 != 0 else ""

        return sorted_half + middle + sorted_half[::-1]