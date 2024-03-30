
def optimal_choices(tasks):
    tp = -1
    chosen = []

    for task in tasks:
        s,e,ind = task

        if s >= tp:
            # chosen.append(ind)
            chosen.append((s,e))
            tp = e

    print(chosen)
    return chosen

n = int(input())

lt = []
for i in range(0,n):
    a,b = (input().split(' '))
    a = int(a)
    b = int(b)

    lt.append((a,b,i))

lt.sort(key=lambda x : x[1])
# print(lt)
o = (optimal_choices(lt))





