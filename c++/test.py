def insert(B, x):
    for y in B:
        if x >> y.bit_length() == y:
            return
        x ^= y
    B.append(x)

def solve(s):
    B = []
    for x in s:
        insert(B, x)
    return len(B)

s = [0b110, 0b1010, 0b1111, 0b11000, 0b101011]
print(solve(s))



