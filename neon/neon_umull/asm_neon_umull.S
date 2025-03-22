
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

# qhasm: reg128 A

# qhasm: reg128 B

# qhasm: reg128 R

# qhasm: enter neon_umull_8
.align 4
.global _neon_umull_8
.global neon_umull_8
_neon_umull_8:
neon_umull_8:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: B = mem128[pointerB]
# asm 1: ldr >B=reg128#2%qregname,[<pointerB=int64#3]
# asm 2: ldr >B=q1,[<pointerB=x2]
ldr q1,[x2]

# qhasm: 8x R = A[0] unsigned* B[0]
# asm 1: umull >R=reg128#1.8h,<A=reg128#1.8b,<B=reg128#2.8b
# asm 2: umull >R=v0.8h,<A=v0.8b,<B=v1.8b
umull v0.8h,v0.8b,v1.8b

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_umull_16
.align 4
.global _neon_umull_16
.global neon_umull_16
_neon_umull_16:
neon_umull_16:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: B = mem128[pointerB]
# asm 1: ldr >B=reg128#2%qregname,[<pointerB=int64#3]
# asm 2: ldr >B=q1,[<pointerB=x2]
ldr q1,[x2]

# qhasm: 4x R = A[0] unsigned* B[0]
# asm 1: umull >R=reg128#1.4s,<A=reg128#1.4h,<B=reg128#2.4h
# asm 2: umull >R=v0.4s,<A=v0.4h,<B=v1.4h
umull v0.4s,v0.4h,v1.4h

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_umull_32
.align 4
.global _neon_umull_32
.global neon_umull_32
_neon_umull_32:
neon_umull_32:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: B = mem128[pointerB]
# asm 1: ldr >B=reg128#2%qregname,[<pointerB=int64#3]
# asm 2: ldr >B=q1,[<pointerB=x2]
ldr q1,[x2]

# qhasm: 2x R = A[0] unsigned* B[0]
# asm 1: umull >R=reg128#1.2d,<A=reg128#1.2s,<B=reg128#2.2s
# asm 2: umull >R=v0.2d,<A=v0.2s,<B=v1.2s
umull v0.2d,v0.2s,v1.2s

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_umull2_8
.align 4
.global _neon_umull2_8
.global neon_umull2_8
_neon_umull2_8:
neon_umull2_8:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: B = mem128[pointerB]
# asm 1: ldr >B=reg128#2%qregname,[<pointerB=int64#3]
# asm 2: ldr >B=q1,[<pointerB=x2]
ldr q1,[x2]

# qhasm: 8x R = A[1] unsigned* B[1]
# asm 1: umull2 >R=reg128#1.8h,<A=reg128#1.16b,<B=reg128#2.16b
# asm 2: umull2 >R=v0.8h,<A=v0.16b,<B=v1.16b
umull2 v0.8h,v0.16b,v1.16b

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_umull2_16
.align 4
.global _neon_umull2_16
.global neon_umull2_16
_neon_umull2_16:
neon_umull2_16:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: B = mem128[pointerB]
# asm 1: ldr >B=reg128#2%qregname,[<pointerB=int64#3]
# asm 2: ldr >B=q1,[<pointerB=x2]
ldr q1,[x2]

# qhasm: 4x R = A[1] unsigned* B[1]
# asm 1: umull2 >R=reg128#1.4s,<A=reg128#1.8h,<B=reg128#2.8h
# asm 2: umull2 >R=v0.4s,<A=v0.8h,<B=v1.8h
umull2 v0.4s,v0.8h,v1.8h

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret

# qhasm: enter neon_umull2_32
.align 4
.global _neon_umull2_32
.global neon_umull2_32
_neon_umull2_32:
neon_umull2_32:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: B = mem128[pointerB]
# asm 1: ldr >B=reg128#2%qregname,[<pointerB=int64#3]
# asm 2: ldr >B=q1,[<pointerB=x2]
ldr q1,[x2]

# qhasm: 2x R = A[1] unsigned* B[1]
# asm 1: umull2 >R=reg128#1.2d,<A=reg128#1.4s,<B=reg128#2.4s
# asm 2: umull2 >R=v0.2d,<A=v0.4s,<B=v1.4s
umull2 v0.2d,v0.4s,v1.4s

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret
