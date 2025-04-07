int64 pointerR
int64 pointerA
int64 pointerB

input pointerR
input pointerA
input pointerB

reg128 A
reg128 B
reg128 R


enter neon_addhn_16_to_8

A = mem128[pointerA]
B = mem128[pointerB]

2x R[0] = (A + B) >> 32

mem128[pointerR] = R

return

enter neon_addhn2_16_to_8

A = mem128[pointerA]
B = mem128[pointerB]

2x R[1] = (A + B) >> 32

mem128[pointerR] = R

return


enter neon_addhn_32_to_16

A = mem128[pointerA]
B = mem128[pointerB]

2x R[0] = (A + B) >> 32

mem128[pointerR] = R

return

enter neon_addhn2_32_to_16

A = mem128[pointerA]
B = mem128[pointerB]

2x R[1] = (A + B) >> 32

mem128[pointerR] = R

return


enter neon_addhn_64_to_32

A = mem128[pointerA]
B = mem128[pointerB]

2x R[0] = (A + B) >> 32

mem128[pointerR] = R

return

enter neon_addhn2_64_to_32

A = mem128[pointerA]
B = mem128[pointerB]

2x R[1] = (A + B) >> 32

mem128[pointerR] = R

return