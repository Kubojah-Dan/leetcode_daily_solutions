class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        stack = []
        union_set = set()
        product_set = {""}

        for char in expression:

            if char.isalpha():
                product_set = {p + char for p in product_set}

            elif char == '{':
                stack.append((union_set, product_set))
                union_set = set()
                product_set = {""}
            
            elif char == ',':
                union_set |= product_set
                product_set = {""}
            
            elif char == '}':
                union_set |= product_set
                prev_union, prev_product = stack.pop()
                product_set = {p + u for p in prev_product for u in union_set}
                union_set = prev_union

        res_set = union_set | product_set

        return sorted(list(res_set))