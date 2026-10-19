class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        target_nums = []

        nums.sort()
        n = len(nums)
        for i in range(n):
            if nums[i] == target:
                target_nums.append(i)

        return target_nums