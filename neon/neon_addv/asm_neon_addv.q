int64 pointerR
int64 pointerA

input pointerR
input pointerA

reg128 A
reg128 R


enter neon_addv_8_8b

A = mem128[pointerA]

8x R = sum(A[0/2])

mem128[pointerR] = R

return



enter neon_addv_8_16b

A = mem128[pointerA]

16x R = sum(A)

mem128[pointerR] = R

return



enter neon_addv_16_4h

A = mem128[pointerA]

4x R = sum(A[0/2])

mem128[pointerR] = R

return



enter neon_addv_16_8h

A = mem128[pointerA]

8x R = sum(A)

mem128[pointerR] = R

return



enter neon_addv_32_4s

A = mem128[pointerA]

4x R = sum(A)

mem128[pointerR] = R

return