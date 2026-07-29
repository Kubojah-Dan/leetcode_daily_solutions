class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        n = len(s)
        n0 = n // 2
        
        freq = Counter(s[:n0])
        INF = 10**6 + 1

        def count_permutations(f_dict, sz):
            ans = 1
            curr_sz = sz
            for ch in sorted(f_dict.keys()):
                f = f_dict[ch]
                if f > 0:
                    ans *= math.comb(curr_sz, f)
                    if ans >= INF:
                        return INF
                    curr_sz -= f
            return ans

        total = count_permutations(freq, n0)
        if k > total:
            return ""

        left = []
        sz = n0

        for _ in range(n0):
            for c_code in range(26):
                ch = chr(ord('a') + c_code)
                if freq[ch] == 0:
                    continue

                freq[ch] -= 1
                cnt = count_permutations(freq, sz - 1)

                if cnt >= k:
                    left.append(ch)
                    sz -= 1
                    break
                else:
                    k -= cnt
                    freq[ch] += 1 

        left_str = "".join(left)
        right_str = left_str[::-1]
        mid_str = s[n0] if (n % 2 == 1) else ""

        return left_str + mid_str + right_str