from collections import Counter
from typing import List

class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq = Counter(digits)
        count = 0

        for num in range(100, 1000, 2):
            d1, d2, d3 = num // 100, (num // 10) % 10, num % 10
            req = Counter([d1, d2, d3])

            if all(freq[d] >= req[d] for d in req):
                count += 1

        return count