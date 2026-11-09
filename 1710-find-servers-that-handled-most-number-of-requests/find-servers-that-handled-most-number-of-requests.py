class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        free = list(range(k))
        heapq.heapify(free)

        busy = []
        counts = [0] * k

        for i in range(len(arrival)):
            t = arrival[i]
            d = load[i]

            while busy and busy[0][0] <= t:
                finish_time, server_id = heapq.heappop(busy)

                virtual_id = i + (server_id - i) % k
                heapq.heappush(free, virtual_id)

            if free:
                virtual_id = heapq.heappop(free)
                actual_id = virtual_id % k

                heapq.heappush(busy, (t + d, actual_id))
                counts[actual_id] += 1

        max_handled = max(counts)
        return [i for i, count in enumerate(counts) if count == max_handled]