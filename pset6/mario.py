height = int(input("Height: "))

def blocks(n):
    print("#"*n + "  " +"#"*n)

for i in range(height):
    blocks(i)