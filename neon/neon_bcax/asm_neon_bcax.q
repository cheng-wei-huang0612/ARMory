int64 pointerR
int64 pointerA
int64 pointerB
int64 pointerC

input pointerR
input pointerA
input pointerB
input pointerC

reg128 R
reg128 A
reg128 B
reg128 C

enter neon_bcax_128

A = mem128[pointerA]
B = mem128[pointerB]
C = mem128[pointerC]

R = A ^ (B & ~C)

mem128[pointerR] = R

return