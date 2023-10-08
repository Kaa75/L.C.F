class Solution:
    def convert(self, s: str, rows: int) -> str:
        if rows ==1: return s
        index=0
        index2=0
        counter= 2 * (rows -1)
        counter2 = counter
        ans =""
        for i in range(rows):
            index =i
            while (index < len(s)):
                ans += s[index]
                if i != 0 and i != rows -1:
                    counter2 = counter - 2 * i
                    index2 = index + counter2
                    if index2 < len(s):
                        ans += s[index2]
                index += counter
        return ans