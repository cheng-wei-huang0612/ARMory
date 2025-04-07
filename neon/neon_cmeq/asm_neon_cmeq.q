int64 pointerR
int64 pointerA
int64 pointerB


input pointerR
input pointerA
input pointerB


reg128 R
reg128 A
reg128 B


enter neon_cmeq


A = mem128[pointerA]
B = mem128[pointerB]

4x R = A >= 0

mem128[pointerR] = R

return