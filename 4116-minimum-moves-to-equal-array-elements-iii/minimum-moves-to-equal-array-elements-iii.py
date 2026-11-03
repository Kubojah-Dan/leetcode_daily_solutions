class Solution:
    def minMoves(self, nums: List[int]) -> int:
        maximum = max(nums)
        moves = 0
        for num in nums:
            if num < maximum:
                moves += (maximum - num)
        return moves