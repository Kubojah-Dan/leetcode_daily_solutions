class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        def date_to_day_of_year(date_str: str) -> int:
            month, day = map(int, date_str.split('-'))
            return sum(days_in_month[:month - 1]) + day

        alice_start = date_to_day_of_year(arriveAlice)
        alice_end = date_to_day_of_year(leaveAlice)
        bob_start = date_to_day_of_year(arriveBob)
        bob_end = date_to_day_of_year(leaveBob)

        latest_start = max(alice_start, bob_start)
        earliest_end = min(alice_end, bob_end)

        if latest_start <= earliest_end:
            return earliest_end - latest_start + 1
        return 0