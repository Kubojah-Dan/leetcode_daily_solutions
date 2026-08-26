class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)
        ans = ""
        min_len = float('inf')

        count = 0
        l = 0

        for r in range(n):
            if s[r] == '1':
                count += 1

            while count == k:
                while s[l] == '0':
                    l += 1

                cur_len = r - l + 1
                sub = s[l : r + 1]

                if cur_len < min_len:
                    min_len = cur_len
                    ans = sub

                elif cur_len == min_len:
                    ans = min(ans, sub)

                count -= 1
                l += 1
 
        return ans