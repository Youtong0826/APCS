from sys import stdin
t = int(stdin.readline())
print(min(stdin.readlines(), key=lambda x: (len(set(x)), x)))