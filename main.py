def printme(n):
    cont = 0
    for i in range(1, n // 2 + 1):
        for j in range(i, n - i + 1):
            for k in range(1, j + 1):
                cont += 1
    return cont


print(printme(2))
print(printme(4))
print(printme(6))
print(printme(8))
print(printme(10))
