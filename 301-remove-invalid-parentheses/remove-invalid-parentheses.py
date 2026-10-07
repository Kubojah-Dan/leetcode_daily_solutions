class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        left_rem = 0
        right_rem = 0
        for char in s:
            if char == '(':
                left_rem += 1
            elif char == ')':
                if left_rem > 0:
                    left_rem -= 1
                else:
                    right_rem += 1

        res = set()

        def backtrack(index, left_rem, right_rem, balance, path):
            if index == len(s):
                if left_rem == 0 and right_rem == 0 and balance == 0:
                    res.add("".join(path))
                return

            char = s[index]

            if char == '(' and left_rem > 0:
                backtrack(index + 1, left_rem - 1, right_rem, balance, path)
            elif char == ')' and right_rem > 0:
                backtrack(index + 1, left_rem, right_rem - 1, balance, path)

            if char == '(':
                path.append(char)
                backtrack(index + 1, left_rem, right_rem, balance + 1, path)
                path.pop()
            elif char == ')':
                if balance > 0:
                    path.append(char)
                    backtrack(index + 1, left_rem, right_rem, balance - 1, path)
                    path.pop()
            else:
                path.append(char)
                backtrack(index + 1, left_rem, right_rem, balance, path)
                path.pop()

        backtrack(0, left_rem, right_rem, 0, [])
        return list(res)