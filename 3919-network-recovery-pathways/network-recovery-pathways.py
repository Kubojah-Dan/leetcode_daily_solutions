class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        adj = [[] for _ in range(n)]
        unique_costs = set()
        for u, v, cost in edges:
            adj[u].append((v, cost))
            unique_costs.add(cost)

        topo_order = []
        visited = [False] * n

        def dfs(u):
            visited[u] = True
            for v, _ in adj[u]:
                if not visited[v]:
                    dfs(v)
            topo_order.append(u)

        for i in range(n):
            if not visited[i]:
                dfs(i)
        topo_order.reverse()

        def can_reach(mid):
            dist = [float('inf')] * n
            dist[0] = 0

            for u in topo_order:
                if dist[u] == float('inf'):
                    continue
                for v, cost in adj[u]:
                    if cost >= mid and online[v]:
                        if dist[u] + cost < dist[v]:
                            dist[v] = dist[u] + cost

            return dist[n - 1] <= k

        sorted_costs = sorted(list(unique_costs))

        if not can_reach(0):
            return -1

        low = 0
        high = len(sorted_costs) - 1
        ans = 0

        while low <= high:
            mid_idx = (low + high) // 2
            target_cost = sorted_costs[mid_idx]

            if can_reach(target_cost):
                ans = target_cost
                low = mid_idx + 1
            else:
                high = mid_idx - 1
        
        return ans