from collections import deque

class RecentCounter:
    def __init__(self):
        self.counter = 0
        self.in_time = deque([])
        

    def ping(self, t: int) -> int:
        self.in_time.append(t)
        self.counter += 1
        while self.in_time[0] < t - 3000:
            self.in_time.popleft()
            self.counter -= 1
        return self.counter
        