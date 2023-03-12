def check(c):
    # Tworzymy tablicę o wymiarach (suma_częściowa, indeks)
    # dla największej możliwej sumy częściowej równiej 360 * 2.
    # Dodajemy jeszcze jeden indeks dla wygody.
    tablica = [[False for _ in range(len(c) + 1)] for _ in range(361)]

    # Ustawiamy wartość na True dla sumy częściowej równiej 0.
    tablica[0][0] = True

    for i in range(1, len(c) + 1):
        for j in range(361):
            # Sprawdzamy, czy jesteśmy w stanie osiągnąć sumę częściową j
            # poprzez dodanie lub odjęcie wartości z aktualnego indeksu.
            if tablica[j][i - 1]:
                tablica[(j + c[i - 1]) % 360][i] = True
                tablica[(j - c[i - 1] + 360) % 360][i] = True

    
    for i in range(0, len(c) + 1):
        print(i, end=" ")
    print()
    for j in range(361):
        print(j,end=" : ")
        for i in range(0, len(c) + 1):
            print(tablica[j][i],end=" ")
        print()
    # Sprawdzamy, czy udało się osiągnąć sumę równą 0 lub podzielną przez 360.
    return tablica[0][len(c)] or tablica[360][len(c)]

n = int(input("size : "))
l = []
for i in range(0,n):
    a = int(input())
    l.append(a)
check(l)
