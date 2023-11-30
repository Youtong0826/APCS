n = sorted(set(input().split()), key=int, reverse=True)
print(4-len(n), " ".join(n))