int64 pointerR
int64 pointerA
int64 pointerB

input pointerR
input pointerA
input pointerB

reg128 A
reg128 B
reg128 R


enter neon_addp_8_8b

A = mem128[pointerA]
B = mem128[pointerB]

8x 8bits R = A[2i]+A[2i+1] B[2i]+B[2i+1]

mem128[pointerR] = R

return


enter neon_addp_8_16b

A = mem128[pointerA]
B = mem128[pointerB]

16x 8bits R = A[2i]+A[2i+1] B[2i]+B[2i+1]

mem128[pointerR] = R

return


enter neon_addp_16_4h

A = mem128[pointerA]
B = mem128[pointerB]

4x 16bits R = A[2i]+A[2i+1] B[2i]+B[2i+1]

mem128[pointerR] = R

return



enter neon_addp_16_8h

A = mem128[pointerA]
B = mem128[pointerB]

8x 16bits R = A[2i]+A[2i+1] B[2i]+B[2i+1]

mem128[pointerR] = R

return


enter neon_addp_32_2s

A = mem128[pointerA]
B = mem128[pointerB]

2x 32bits R = A[2i]+A[2i+1] B[2i]+B[2i+1]

mem128[pointerR] = R

return



enter neon_addp_32_4s

A = mem128[pointerA]
B = mem128[pointerB]

4x 32bits R = A[2i]+A[2i+1] B[2i]+B[2i+1]

mem128[pointerR] = R

return



enter neon_addp_64_2d

A = mem128[pointerA]
B = mem128[pointerB]

2x R = A[0]+A[1] B[0]+B[1]

mem128[pointerR] = R

return