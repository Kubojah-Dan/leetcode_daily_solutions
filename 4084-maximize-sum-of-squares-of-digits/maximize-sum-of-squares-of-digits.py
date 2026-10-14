class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > num * 9:
            return ''
        
        quotient, remainder = divmod(sum, 9)
        res = '9' * quotient + (str(remainder) if remainder else '')

        return res + '0' * (num - len(res))