
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

# qhasm: input pointerR

# qhasm: input pointerA

# qhasm: reg128 A

# qhasm: reg128 R

# qhasm: enter neon_addv_8_8b
.align 4
.global _neon_addv_8_8b
.global neon_addv_8_8b
_neon_addv_8_8b:
neon_addv_8_8b:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: 8x R = sum(A[0/2])
# asm 1: addv >R=reg128#1%bregname,<A=reg128#1.8b
# asm 2: addv >R=b0,<A=v0.8b
addv b0,v0.8b

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_addv_8_16b
.align 4
.global _neon_addv_8_16b
.global neon_addv_8_16b
_neon_addv_8_16b:
neon_addv_8_16b:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: 16x R = sum(A)
# asm 1: addv >R=reg128#1%bregname,<A=reg128#1.16b
# asm 2: addv >R=b0,<A=v0.16b
addv b0,v0.16b

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_addv_16_4h
.align 4
.global _neon_addv_16_4h
.global neon_addv_16_4h
_neon_addv_16_4h:
neon_addv_16_4h:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: 4x R = sum(A[0/2])
# asm 1: addv >R=reg128#1%hregname,<A=reg128#1.4h
# asm 2: addv >R=h0,<A=v0.4h
addv h0,v0.4h

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_addv_16_8h
.align 4
.global _neon_addv_16_8h
.global neon_addv_16_8h
_neon_addv_16_8h:
neon_addv_16_8h:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: 8x R = sum(A)
# asm 1: addv >R=reg128#1%hregname,<A=reg128#1.8h
# asm 2: addv >R=h0,<A=v0.8h
addv h0,v0.8h

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_addv_32_4s
.align 4
.global _neon_addv_32_4s
.global neon_addv_32_4s
_neon_addv_32_4s:
neon_addv_32_4s:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: 4x R = sum(A)
# asm 1: addv >R=reg128#1%sregname,<A=reg128#1.4s
# asm 2: addv >R=s0,<A=v0.4s
addv s0,v0.4s

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret
