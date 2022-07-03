dictt = {}
dictt['Sergio'] = {}
d2 = {}

dictt['Sergio']['1'] = 1
dictt['Sergio']['2'] = 1
dictt['Sergio']['3'] = 1

d2['1'] = 1
d2['2'] = 1
d2['3'] = 2

print(dictt)
print(d2)
success_count = 0
for subseq in dictt['Sergio']:
    if dictt['Sergio'][subseq] == d2[subseq]:
        print('entrei')
        success_count += 1