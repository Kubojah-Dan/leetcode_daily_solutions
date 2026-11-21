class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)

        children = [[] for _ in range(n)]
        for i in range(1, n):
            children[parent[i]].append(i)

        ans = [1] * n
        last_seen = [-1] * 26

        def dfs(u: int) -> None:
            char_idx = ord(s[u]) - ord('a')
            prev_ancestor = last_seen[char_idx]

            last_seen[char_idx] = u

            for v in children[u]:
                dfs(v)

            last_seen[char_idx] = prev_ancestor

            if u != 0:
                new_parent = prev_ancestor if prev_ancestor != -1 else parent[u]
                ans[new_parent] += ans[u]

        dfs(0)
        return ans