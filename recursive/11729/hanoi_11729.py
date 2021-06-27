def hanoi(n, first, second, thrid):
    if n == 1:
        print(first, thrid)
        return;
    else:
        hanoi(n-1, first, thrid, second)
        print(first, thrid)
        hanoi(n-1, second, first, thrid)
n = int(input())
count = 1
for i in range(n):
    count *= 2
print(count - 1)
hanoi(n, '1', '2', '3')
