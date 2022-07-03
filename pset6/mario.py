height = int(input("Height: "))

def blocks(n):
    print(" "*(height - n) + "#"*n + "  " +"#"*n)

for i in range(1, height+1):
    blocks(i)