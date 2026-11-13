class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        q = deque()
        cost = 0
        total_valid_subarrays = 0
        R = n - 1

        for L in range(n - 1, -1, -1):
            val = nums[L]
            current_len = 1

            while q and q[0][0] <= val:
                popped_val, popped_len = q.popleft()
                cost += (val - popped_val) * popped_len
                current_len += popped_len

            q.appendleft([val, current_len])

            while cost > k:
                last_val, last_len = q[-1]
                cost -= (last_val - nums[R])
                R -= 1

                if last_len == 1:
                    q.pop()
                else:
                    q[-1][1] -= 1

            total_valid_subarrays += (R - L + 1)

        return total_valid_subarrays