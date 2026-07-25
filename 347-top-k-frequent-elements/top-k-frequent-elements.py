class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        top = sorted(freq.items(), key=lambda x: (-x[1], -x[0]))[:k]

        return sorted([num for num, _ in top])