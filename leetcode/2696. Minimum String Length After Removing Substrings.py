def minLength( s: str) -> int:
    stack = []
    for i in s:
        stack.append(i)
        if len(stack) != 1:
            tocheck = f'{stack[-2]}{stack[-1]}'
            if tocheck == "AB" or tocheck == "CD":
                stack.pop()
                stack.pop()
    return len(stack)


print(minLength("ACBBD"))
