
# qhasm: int64 input_x0

# qhasm: int64 input_x1

# qhasm: int64 input_x2

# qhasm: int64 input_x3

# qhasm: int64 input_x4

# qhasm: int64 input_x5

# qhasm: int64 input_x6

# qhasm: int64 input_x7

# qhasm: int64 output_x0

# qhasm: int64 calleesaved_x18

# qhasm: int64 calleesaved_x19

# qhasm: int64 calleesaved_x20

# qhasm: int64 calleesaved_x21

# qhasm: int64 calleesaved_x22

# qhasm: int64 calleesaved_x23

# qhasm: int64 calleesaved_x24

# qhasm: int64 calleesaved_x25

# qhasm: int64 calleesaved_x26

# qhasm: int64 calleesaved_x27

# qhasm: int64 calleesaved_x28

# qhasm: int64 calleesaved_x29

# qhasm: reg128 input_v0

# qhasm: reg128 input_v1

# qhasm: reg128 input_v2

# qhasm: reg128 input_v3

# qhasm: reg128 input_v4

# qhasm: reg128 input_v5

# qhasm: reg128 input_v6

# qhasm: reg128 input_v7

# qhasm: reg128 output_v0

# qhasm: reg128 calleesaved_v8

# qhasm: reg128 calleesaved_v9

# qhasm: reg128 calleesaved_v10

# qhasm: reg128 calleesaved_v11

# qhasm: reg128 calleesaved_v12

# qhasm: reg128 calleesaved_v13

# qhasm: reg128 calleesaved_v14

# qhasm: reg128 calleesaved_v15

# qhasm: int64 pointerR

# qhasm: int64 pointerA

# qhasm: int64 pointerB

# qhasm: input pointerR

# qhasm: input pointerA

# qhasm: input pointerB

# qhasm: int64 a

# qhasm: int64 b

# qhasm: int64 r

# qhasm: enter asm_add
.align 4
.global _asm_add
.global asm_add
_asm_add:
asm_add:

# qhasm: a = mem64[pointerA]
# asm 1: ldr >a=int64#2,[<pointerA=int64#2]
# asm 2: ldr >a=x1,[<pointerA=x1]
ldr x1,[x1]

# qhasm: b = mem64[pointerB]
# asm 1: ldr >b=int64#3,[<pointerB=int64#3]
# asm 2: ldr >b=x2,[<pointerB=x2]
ldr x2,[x2]

# qhasm: r = a + b 
# asm 1: add >r=int64#2,<a=int64#2,<b=int64#3
# asm 2: add >r=x1,<a=x1,<b=x2
add x1,x1,x2

# qhasm: mem64[pointerR] = r
# asm 1: str <r=int64#2,[<pointerR=int64#1]
# asm 2: str <r=x1,[<pointerR=x0]
str x1,[x0]

# qhasm: return
ret
