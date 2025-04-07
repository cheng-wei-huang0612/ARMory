int64 pointerR
int64 pointerA
int64 pointerB

input pointerR
input pointerA
input pointerB

reg128 A
reg128 B
reg128 R



enter neon_zip1_8

A = mem128[pointerA]
B = mem128[pointerB]

16x R = A[0/16] B[0/16] A[1/16] B[1/16]

mem128[pointerR] = R

return

enter neon_zip2_8

A = mem128[pointerA]
B = mem128[pointerB]

16x R = A[8/16] B[8/16] A[9/16] B[9/16]

mem128[pointerR] = R

return


enter neon_zip1_16

A = mem128[pointerA]
B = mem128[pointerB]

8x R = A[0/8] B[0/8] A[1/8] B[1/8]

mem128[pointerR] = R

return

enter neon_zip2_16

A = mem128[pointerA]
B = mem128[pointerB]

8x R = A[4/8] B[4/8] A[5/8] B[5/8]

mem128[pointerR] = R

return


enter neon_zip1_32

A = mem128[pointerA]
B = mem128[pointerB]

4x R = A[0/4] B[0/4] A[1/4] B[1/4]

mem128[pointerR] = R

return

enter neon_zip2_32

A = mem128[pointerA]
B = mem128[pointerB]

4x R = A[2/4] B[2/4] A[3/4] B[3/4]

mem128[pointerR] = R

return