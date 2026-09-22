class Node:
    def __init__(self, k):
        self.prod = 1
        self.freq = [0] * k

class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        n = len(nums)
        tree = [Node(k) for _ in range(4 * n)]
        
        def merge(left: Node, right: Node) -> Node:
            res = Node(k)
            res.prod = (left.prod * right.prod) % k
            
            for i in range(k):
                res.freq[i] += left.freq[i]
                
            for i in range(k):
                if right.freq[i] > 0:
                    new_remainder = (left.prod * i) % k
                    res.freq[new_remainder] += right.freq[i]
                    
            return res

        def build(node, start, end):
            if start == end:
                val = nums[start] % k
                tree[node].prod = val
                tree[node].freq[val] = 1
                return
                
            mid = (start + end) // 2
            build(2 * node, start, mid)
            build(2 * node + 1, mid + 1, end)
            tree[node] = merge(tree[2 * node], tree[2 * node + 1])

        def update(node, start, end, idx, val):
            if start == end:
                tree[node] = Node(k) 
                mod_val = val % k
                tree[node].prod = mod_val
                tree[node].freq[mod_val] = 1
                return
                
            mid = (start + end) // 2
            if idx <= mid:
                update(2 * node, start, mid, idx, val)
            else:
                update(2 * node + 1, mid + 1, end, idx, val)
            tree[node] = merge(tree[2 * node], tree[2 * node + 1])

        def query(node, start, end, q_start, q_end):
            if q_start <= start and end <= q_end:
                return tree[node]
                
            mid = (start + end) // 2
            if q_end <= mid:
                return query(2 * node, start, mid, q_start, q_end)
            if q_start > mid:
                return query(2 * node + 1, mid + 1, end, q_start, q_end)

            left_res = query(2 * node, start, mid, q_start, q_end)
            right_res = query(2 * node + 1, mid + 1, end, q_start, q_end)
            return merge(left_res, right_res)

        build(1, 0, n - 1)
        
        ans = []
        for idx, val, start_idx, target_x in queries:
            update(1, 0, n - 1, idx, val)
            
            result_node = query(1, 0, n - 1, start_idx, n - 1)

            ans.append(result_node.freq[target_x])
            
        return ans