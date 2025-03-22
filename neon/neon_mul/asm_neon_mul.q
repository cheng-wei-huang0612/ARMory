int64 pointerR
int64 pointerA
int64 pointerB

input pointerR
input pointerA
input pointerB

reg128 A
reg128 B
reg128 R


enter neon_mul_8

A = mem128[pointerA]
B = mem128[pointerB]

16x R = A * B

mem128[pointerR] = R




return

enter neon_mul_16
A = mem128[pointerA]
B = mem128[pointerB]

8x R = A * B


mem128[pointerR] = R

return


enter neon_mul_32
A = mem128[pointerA]
B = mem128[pointerB]

4x R = A * B

mem128[pointerR] = R


return




