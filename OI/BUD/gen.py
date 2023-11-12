import random

choices = ['X', '.']

n = 1500
out = ""
for i in range(0,n):
    for j in range(0,n):
        out += random.choice(choices)
    out += '\n'

print(out)

