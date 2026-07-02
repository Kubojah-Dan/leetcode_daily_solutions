class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        start_health = health - grid[0][0]
        if start_health <= 0:
            return False
        
        queue = deque([(0, 0, start_health)])
        visited = set([(0, 0, start_health)])

        while queue:
            x, y, remaining_health = queue.popleft()
            if x == m - 1 and y == n - 1:
                return remaining_health > 0

            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    new_health = remaining_health - grid[nx][ny]

                    if new_health > 0 and (nx, ny, new_health) not in visited:
                        visited.add((nx, ny, new_health))
                        queue.append((nx, ny, new_health))

        return False
