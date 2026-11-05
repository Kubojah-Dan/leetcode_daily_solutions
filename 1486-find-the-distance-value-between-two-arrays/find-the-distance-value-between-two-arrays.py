import bisect

class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        count = 0

        for x in arr1:
            idx = bisect.bisect_left(arr2, x)

            is_valid = True

            if idx < len(arr2) and abs(arr2[idx] - x) <= d:
                is_valid = False

            if idx > 0 and abs(arr2[idx - 1] - x) <= d:
                is_valid = False

            if is_valid:
                count += 1

        return count