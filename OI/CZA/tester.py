import os
import time

# 1- bud
# 2- bud
# 3- test


progname = input("nazwa programu ktory chcesz przetestowac : ")


TNAME = ""
PATH = f"oi_2023_testy/cza" 
mode = (input("przedzial testow podzadan w formacie `1-n`:")).split('-')

s = int(mode[0])
e = int(mode[1]) + 1

stats = 0
n = 0

pth = os.path.join(os.getcwd(), PATH)
for i in range(s, e):
    arg = f'< {os.path.join(pth,os.path.join("in",TNAME + str(i) + ".in"))}'
    ts = time.time()
    out = os.popen(f'./{progname} {arg}').read().replace(' ',"").replace('\t',"").replace("\n","")
    te = time.time()
    with open(os.path.join(pth,os.path.join("out",TNAME + str(i) + ".out")), 'r') as f:
        expected = f.read().replace(' ',"").replace('\t',"").replace("\n","")
        f.close()

    if out != expected:
        print(f"Error : {i} | expected: {expected} / got: {out}")
        break
        
    print(f"|\tOK {i}\t|\ttook {te - ts}s")
    stats += (te - ts)
    n+=1
print(f"Mean time : {stats/n}")




