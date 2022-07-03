height = int(input("Height: "))

def blocks(n):
    print(" "*(height - n) + "#"*n + "  " +"#"*n)

for i in range(height):
    blocks(i)