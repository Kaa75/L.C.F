class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        start, end = 0, len(people)-1
        boats = 0
        
        while(start<=end):
            if people[end] == limit or people[end]+people[start] > limit:
                boats+=1
                end-=1
            else:
                boats+=1
                end-=1
                start+=1
        return boats
