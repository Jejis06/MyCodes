import os
import re
import sys

def djb2(string: bytes) -> int:
    h = 5381
    for c in string:
        h = h * 33 + c
    return h % 2**64

baseDir = "../teksty/"
files = [
    "Mickiewicz.txt",
    "Prus.txt",
    "Sienkiewicz.txt"
]

# 750 - 790
def generateDataEnd(strname, curr,lenbeg=4, minLen=4, ammTopWords=790):
    with open(os.path.join(baseDir, files[curr]), 'r') as f:
        content = f.read()
        f.close()

    pattern = '[^A-Za-z0-9]+'
    words = [x.lower() for x in re.split(pattern, content)]

    validWords = [x for x in words if len(x) >= minLen]

    wordsDist = {}
    for word in validWords:
        word = word[::-1][:lenbeg]
        if word in wordsDist: wordsDist[word] += 1
        else: wordsDist[word] = 1

    wordsDist = (sorted(wordsDist.items(), key=lambda item: item[1],reverse=True))
    encodedWords = []
    ammTopWords = min(len(wordsDist), ammTopWords)

    for i in range(ammTopWords):
        # byteStr = bytes(wordsDist[i][0],'utf-8')
        # encodedWords.append(hex(djb2(byteStr)))
        encodedWords.append(wordsDist[i][0])

    


    enclosed = ""
    for eword in encodedWords:
        enclosed += f'{eword}'
    enclosed = enclosed[:-1]

    out = f'{strname}="{enclosed}"'
    return out

def generateDataStart(strname, curr,lenbeg=4, minLen=4, ammTopWords=790):
    with open(os.path.join(baseDir, files[curr]), 'r') as f:
        content = f.read()
        f.close()

    pattern = '[^A-Za-z0-9]+'
    words = [x.lower() for x in re.split(pattern, content)]

    validWords = [x for x in words if len(x) >= minLen]

    wordsDist = {}
    for word in validWords:
        word = word[:lenbeg]
        if word in wordsDist: wordsDist[word] += 1
        else: wordsDist[word] = 1

    wordsDist = (sorted(wordsDist.items(), key=lambda item: item[1],reverse=True))
    encodedWords = []
    ammTopWords = min(len(wordsDist), ammTopWords)

    for i in range(ammTopWords):
        # byteStr = bytes(wordsDist[i][0],'utf-8')
        # encodedWords.append(hex(djb2(byteStr)))
        encodedWords.append(wordsDist[i][0])

    


    enclosed = ""
    for eword in encodedWords:
        enclosed += f'{eword}'
    enclosed = enclosed[:-1]

    out = f'{strname}="{enclosed}"'
    return out


    return f"string {strname}[{ammTopWords}]={{{enclosed}}};"
#97


def generateData(strname, curr, minLen=5, ammTopWords=430):
    with open(os.path.join(baseDir, files[curr]), 'r') as f:
        content = f.read()
        f.close()

    pattern = '[^A-Za-z0-9]+'
    words = [x.lower() for x in re.split(pattern, content)]

    validWords = [x for x in words if len(x) >= minLen]

    wordsDist = {}
    for word in validWords:
        if word in wordsDist: wordsDist[word] += 1
        else: wordsDist[word] = 1

    wordsDist = (sorted(wordsDist.items(), key=lambda item: item[1],reverse=True))
    encodedWords = []
    ammTopWords = min(len(wordsDist), ammTopWords)

    for i in range(ammTopWords):
        # byteStr = bytes(wordsDist[i][0],'utf-8')
        # encodedWords.append(hex(djb2(byteStr)))
        encodedWords.append(wordsDist[i][0])

    


    enclosed = ""
    for eword in encodedWords:
        enclosed += f'{eword},'
    enclosed = enclosed[:-1]

    return f'{strname}="{enclosed}"'

    return f"string {strname}[{ammTopWords}]={{{enclosed}}};"


for i in range(3):
    print(generateDataStart(files[i][:3], i))

sys.exit(0)

for i in range(3):
    print(generateData(files[i][:3], i, 4, 1200))

linebeg = 4
ammTopWords = 385
for i in range(3):
    #print(generateDataStart(files[i][:3], i))
    parent = files[i][0]+files[i][:3]+'b'
    print(generateDataStart(parent,i,lenbeg=linebeg,minLen=4,ammTopWords=ammTopWords))
print()
for i in range(3):
    parent = files[i][0]+files[i][:3]+'b'
    print(parent[1:] + f"=[{parent}[i:i+{linebeg}] for i in range(0, len({parent}), {linebeg})]")
print()
for i in range(3):
    parent = files[i][0]+files[i][:3]+'e'
    print(generateDataEnd(parent,i,lenbeg=linebeg,minLen=4,ammTopWords=ammTopWords))
print()
for i in range(3):
    parent = files[i][0]+files[i][:3]+'e'
    print(parent[1:] + f"=[{parent}[i:i+{linebeg}] for i in range(0, len({parent}), {linebeg})]")
