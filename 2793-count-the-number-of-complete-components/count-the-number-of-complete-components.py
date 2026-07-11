from collections import deque

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visited = [False] * n
        ans = 0

        def bfs(node):
            q = deque([node])
            visited[node] = True
            comp = []

            while q:
                cur = q.popleft()
                comp.append(cur)
                for neighbor in adj[cur]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        q.append(neighbor)

            return comp

        for i in range(n):
            if not visited[i]:
                comp = bfs(i)
                if all(len(adj[node]) == len(comp) - 1 for node in comp):
                    ans += 1

        return ans