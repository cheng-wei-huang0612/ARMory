int64 pointerR
int64 pointerA

input pointerR
input pointerA

reg128 A
reg128 R

enter neon_addp_scalar

A = mem128[pointerA]

R = A[0] + A[1]

mem128[pointerR] = R

return
