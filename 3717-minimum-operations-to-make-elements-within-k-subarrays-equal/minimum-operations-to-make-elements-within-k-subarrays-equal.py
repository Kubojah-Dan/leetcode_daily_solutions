class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        n = len(nums)

        cost = [0] * n
        left_sl = SortedList()
        right_sl = SortedList()
        sum_left = 0
        sum_right = 0

        left_cap = (x + 1) // 2

        def balance():
            nonlocal sum_left, sum_right
            while len(left_sl) > left_cap:
                v = left_sl.pop(-1)
                right_sl.add(v)
                sum_left -= v
                sum_right += v
            while len(left_sl) < left_cap and right_sl:
                v = right_sl.pop(0)
                left_sl.add(v)
                sum_left += v
                sum_right -= v

        for i in range(n):
            val = nums[i]

            if not left_sl or val <= left_sl[-1]:
                left_sl.add(val)
                sum_left += val

            else:
                right_sl.add(val)
                sum_right += val

            balance()

            if i >= x:
                out = nums[i - x]
                if out <= left_sl[-1]:
                    left_sl.remove(out)
                    sum_left -= out
                else:
                    right_sl.remove(out)
                    sum_right -= out

                balance()

            if i >= x - 1:
                median = left_sl[-1]
                size_left = len(left_sl)
                size_right = len(right_sl)

                cost[i] = (size_left * median - sum_left) + (sum_right - size_right * median)


        INF = float('inf')
        dp = [[INF] * (k + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 0

        for j in range(1, k + 1):
            for i in range(x, n + 1):
                res = dp[i - 1][j]

                window_cost = cost[i - 1]
                if dp[i - x][j - 1] != INF:
                    res = min(res, dp[i - x][j - 1] + window_cost)

                dp[i][j] = res

        return dp[n][k]