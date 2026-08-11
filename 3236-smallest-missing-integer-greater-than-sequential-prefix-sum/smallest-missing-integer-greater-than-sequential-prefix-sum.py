class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        seq_sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                seq_sum += nums[i]

            else:
                break

        nums_set = set(nums)
        
        while seq_sum in nums_set:
            seq_sum += 1

        return seq_sum