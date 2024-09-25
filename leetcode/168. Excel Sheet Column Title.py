def convertToTitle(columnNumber: int) -> str:
    ans = ""
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    while columnNumber > 0:
        i = (columnNumber - 1) % 26
        ans = alphabet[i] + ans
        columnNumber = (columnNumber - 1) // 26

    return ans
