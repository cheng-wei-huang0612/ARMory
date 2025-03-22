int64 pointerR
int64 pointerA
int64 pointerB

input pointerR
input pointerA
input pointerB

int64 a
int64 b
int64 r


enter asm_add

a = mem64[pointerA]
b = mem64[pointerB]

r = a + b 

mem64[pointerR] = r

return
