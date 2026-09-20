class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum(i * (ord('z') - ord(c) + 1) for i, c in enumerate(s, 1))