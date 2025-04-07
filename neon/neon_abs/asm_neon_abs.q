int64 pointerR
int64 pointerA

input pointerR
input pointerA

reg128 A
reg128 R


enter neon_abs_8

A = mem128[pointerA]

16x R = |A|

mem128[pointerR] = R

return



enter neon_abs_16

A = mem128[pointerA]

8x R = |A|

mem128[pointerR] = R

return



enter neon_abs_32

A = mem128[pointerA]

4x R = |A|

mem128[pointerR] = R

return


enter neon_abs_64

A = mem128[pointerA]

2x R = |A|

mem128[pointerR] = R

return