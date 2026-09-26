class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        lookup = {key: value for key, value in knowledge}

        result = []
        key_buffer = []
        in_bracket = False

        for char in s:
            if char == '(':
                in_bracket = True
            elif char == ')':
                in_bracket = False
                key = "".join(key_buffer)

                result.append(lookup.get(key, "?"))
                key_buffer = []
            else:
                if in_bracket:
                    key_buffer.append(char)
                else:
                    result.append(char)
            
        return "".join(result)