
while True:
    try:
        height = int(input("Height: "))
    except:
        continue
    if height > 0 and height < 9:
        break

def blocks(n):
    print(" "*(height - n) + "#"*n + "  " +"#"*n)

for i in range(1, height+1):
    blocks(i)