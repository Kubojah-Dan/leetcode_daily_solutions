class Solution:
    def minimizeSum(self, nums: List[int]) -> int:
        smallNums = nsmallest(3, nums)
        largeNums = nlargest(3, nums)
        return min(largeNums[0] - smallNums[2], largeNums[1] - smallNums[1], largeNums[2] - smallNums[0])