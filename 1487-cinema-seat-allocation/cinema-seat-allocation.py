class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        seats = defaultdict(set)
        for r, c in reservedSeats:
            if 2 <= c <= 9: 
                seats[r].add(c)

        max_groups = (n - len(seats)) * 2
        
        for r, reserved in seats.items():
            left = not (reserved & {2, 3, 4, 5})
            right = not (reserved & {6, 7, 8, 9})
            middle = not (reserved & {4, 5, 6, 7})
            
            if left and right:
                max_groups += 2
            elif left or right or middle:
                max_groups += 1
                
        return max_groups