int64 pointerR
int64 pointerA
int64 pointerB

input pointerR
input pointerA
input pointerB

reg128 A
reg128 B
reg128 R


enter neon_umull_8

A = mem128[pointerA]
B = mem128[pointerB]

8x R = A[0] unsigned* B[0]

mem128[pointerR] = R




return

enter neon_umull_16
A = mem128[pointerA]
B = mem128[pointerB]

4x R = A[0] unsigned* B[0]


mem128[pointerR] = R

return


enter neon_umull_32
A = mem128[pointerA]
B = mem128[pointerB]

2x R = A[0] unsigned* B[0]

mem128[pointerR] = R


return




enter neon_umull2_8

A = mem128[pointerA]
B = mem128[pointerB]

8x R = A[1] unsigned* B[1]

mem128[pointerR] = R




return

enter neon_umull2_16
A = mem128[pointerA]
B = mem128[pointerB]

4x R = A[1] unsigned* B[1]


mem128[pointerR] = R

return


enter neon_umull2_32
A = mem128[pointerA]
B = mem128[pointerB]

2x R = A[1] unsigned* B[1]

mem128[pointerR] = R


return


