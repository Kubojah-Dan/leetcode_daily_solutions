# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        if not head or not head.next or not head.next.next:
            return [-1, -1]

        prev = head
        curr = head.next
        nxt = head.next.next

        first_crit_idx = -1
        prev_crit_idx = -1
        min_dist = float('inf')
        curr_idx = 1

        while nxt:
            is_maxima = (curr.val > prev.val) and (curr.val > nxt.val)
            is_minima = (curr.val < prev.val) and (curr.val < nxt.val)

            if is_maxima or is_minima:
                if first_crit_idx == -1:
                    first_crit_idx = curr_idx

                else:
                    min_dist = min(min_dist, curr_idx - prev_crit_idx)

                prev_crit_idx = curr_idx

            prev = curr
            curr = nxt
            nxt = nxt.next
            curr_idx += 1

        if first_crit_idx == -1 or first_crit_idx == prev_crit_idx:
            return [-1, -1]

        max_dist = prev_crit_idx - first_crit_idx
        return [min_dist, max_dist]