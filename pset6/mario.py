
while True:
    height = int(input("Height: "))
    if height > 0:
        break

def blocks(n):
    print(" "*(height - n) + "#"*n + "  " +"#"*n)

for i in range(1, height+1):
    blocks(i)