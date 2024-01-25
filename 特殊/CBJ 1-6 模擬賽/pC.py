while True:
    try:
        q = int(input())
        for i in range(q):
            n = int(input())
            l = 0
            r = 0
            while(n > 1):
                if n % 2:
                    r+=1
                else:
                    l+=1
                n = n // 2
            print(l,r)
            
    except EOFError:
        break