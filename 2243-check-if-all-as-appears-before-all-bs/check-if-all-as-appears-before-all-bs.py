class Solution:
    def checkString(self, s: str) -> bool:
        for a, b in zip(s, s[1:]):
            if ord(a) > ord(b):
                return False

        return True
                