class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        half_len = (n + 1) // 2
        counts = Counter(s)
        
        odd_chars = [char for char, cnt in counts.items() if cnt % 2 != 0]
        if len(odd_chars) > 1:
            return ""
        
        mid_char = odd_chars[0] if odd_chars else ""

        half_counts = {char: cnt // 2 for char, cnt in counts.items()}
        
        prefix = []
        
        def build_full_palindrome(pref):
            if n % 2 == 1:
                first_part = pref[:-1]
                mid = pref[-1]
                return "".join(first_part) + mid + "".join(reversed(first_part))
            else:
                return "".join(pref) + "".join(reversed(pref))

        def can_complete(idx, current_counts):
            rem_len = half_len - idx
            return sum(current_counts.values()) >= rem_len

        def find_permutation(idx, is_greater):
            if idx == half_len:
                res = build_full_palindrome(prefix)
                return res if res > target else None

            start_char = 'a' if is_greater else target[idx]

            for ch_code in range(ord(start_char), ord('z') + 1):
                ch = chr(ch_code)

                if n % 2 == 1 and idx == half_len - 1:
                    if ch == mid_char or half_counts.get(ch, 0) > 0:
                        prefix.append(ch)
                        res = build_full_palindrome(prefix)
                        prefix.pop()
                        if res > target:
                            return res
                    continue

                if half_counts.get(ch, 0) > 0:
                    half_counts[ch] -= 1
                    prefix.append(ch)
                    
                    next_greater = is_greater or (ch > target[idx])
                    res = find_permutation(idx + 1, next_greater)
                    if res:
                        return res
                    
                    prefix.pop()
                    half_counts[ch] += 1
            
            return None

        result = find_permutation(0, False)
        return result if result else ""