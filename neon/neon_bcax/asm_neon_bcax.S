
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

# qhasm: int64 pointerC

# qhasm: input pointerR

# qhasm: input pointerA

# qhasm: input pointerB

# qhasm: input pointerC

# qhasm: reg128 R

# qhasm: reg128 A

# qhasm: reg128 B

# qhasm: reg128 C

# qhasm: enter neon_bcax_128
.align 4
.global _neon_bcax_128
.global neon_bcax_128
_neon_bcax_128:
neon_bcax_128:

# qhasm: A = mem128[pointerA]
# asm 1: ldr >A=reg128#1%qregname,[<pointerA=int64#2]
# asm 2: ldr >A=q0,[<pointerA=x1]
ldr q0,[x1]

# qhasm: B = mem128[pointerB]
# asm 1: ldr >B=reg128#2%qregname,[<pointerB=int64#3]
# asm 2: ldr >B=q1,[<pointerB=x2]
ldr q1,[x2]

# qhasm: C = mem128[pointerC]
# asm 1: ldr >C=reg128#3%qregname,[<pointerC=int64#4]
# asm 2: ldr >C=q2,[<pointerC=x3]
ldr q2,[x3]

# qhasm: R = A ^ (B & ~C)
# asm 1: bcax >R=reg128#1.16b, <A=reg128#1.16b, <B=reg128#2.16b, <C=reg128#3.16b
# asm 2: bcax >R=v0.16b, <A=v0.16b, <B=v1.16b, <C=v2.16b
bcax v0.16b, v0.16b, v1.16b, v2.16b

# qhasm: mem128[pointerR] = R
# asm 1: str <R=reg128#1%qregname,[<pointerR=int64#1]
# asm 2: str <R=q0,[<pointerR=x0]
str q0,[x0]

# qhasm: return
ret
