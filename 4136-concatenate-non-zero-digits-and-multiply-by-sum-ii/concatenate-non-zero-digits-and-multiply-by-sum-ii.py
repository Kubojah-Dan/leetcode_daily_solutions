class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        digits = []
        positions = []
        for i, ch in enumerate(s):
            if ch != '0':
                digits.append(int(ch))
                positions.append(i)

        k = len(digits)
        if k == 0:
            return [0] * len(queries)

        pref_sum = [0] * (k + 1)
        pref_val = [0] * (k + 1)
        pow10 = [1] * (k + 1)

        for i in range(k):
            pref_sum[i+1] = pref_sum[i] + digits[i]
            pref_val[i+1] = (pref_val[i] * 10 + digits[i]) % MOD
            pow10[i+1] = (pow10[i] * 10) % MOD

        next_nz = [k] * (n + 1)
        curr = k
        for i in range(n - 1, -1, -1):
            if s[i] != '0':
                curr = bisect_left(positions, i)
            next_nz[i] = curr
        
        next_nz = [k] * n
        prev_nz = [-1] * n

        last = -1
        for i in range(n):
            if s[i] != '0':
                last += 1
            prev_nz[i] = last

        nxt = k
        for i in range(n - 1, -1, -1):
            if s[i] != '0':
                nxt -= 1
            next_nz[i] = nxt
        
        ans = []
        for l, r in queries:
            idx_l = next_nz[l]
            idx_r = prev_nz[r]

            if idx_l > idx_r:
                ans.append(0)
                continue
            
            s_val = pref_sum[idx_r + 1] - pref_sum[idx_l]
            length = idx_r - idx_l + 1
            x = (pref_val[idx_r + 1] - pref_val[idx_l] * pow10[length]) % MOD
            ans.append((x * s_val) % MOD)

        return ans