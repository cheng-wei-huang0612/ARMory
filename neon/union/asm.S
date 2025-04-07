
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

# qhasm: reg128 A

# qhasm: reg128 B

# qhasm: reg128 C

# qhasm: reg128 D

# qhasm: int64 a

# qhasm: int64 b

# qhasm: int64 c

# qhasm: int64 d

# qhasm: int64 e

# qhasm: enter test
.align 4
.global _test
.global test
_test:
test:

# qhasm: a = 1
# asm 1: mov >a=int64#1, #1
# asm 2: mov >a=x0, #1
mov x0, #1

# qhasm: b = c + d
# asm 1: add >b=int64#4,<c=int64#2,<d=int64#3
# asm 2: add >b=x3,<c=x1,<d=x2
add x3,x1,x2

# qhasm: b = c + e
# asm 1: add >b=int64#6,<c=int64#2,<e=int64#5
# asm 2: add >b=x5,<c=x1,<e=x4
add x5,x1,x4

# qhasm: b = b + d
# asm 1: add >b=int64#6,<b=int64#6,<d=int64#3
# asm 2: add >b=x5,<b=x5,<d=x2
add x5,x5,x2

# qhasm: b = c + d
# asm 1: add >b=int64#7,<c=int64#2,<d=int64#3
# asm 2: add >b=x6,<c=x1,<d=x2
add x6,x1,x2

# qhasm: b = e + d
# asm 1: add >b=int64#8,<e=int64#5,<d=int64#3
# asm 2: add >b=x7,<e=x4,<d=x2
add x7,x4,x2

# qhasm: b = c + d
# asm 1: add >b=int64#3,<c=int64#2,<d=int64#3
# asm 2: add >b=x2,<c=x1,<d=x2
add x2,x1,x2

# qhasm: b = c + e
# asm 1: add >b=int64#2,<c=int64#2,<e=int64#5
# asm 2: add >b=x1,<c=x1,<e=x4
add x1,x1,x4

# qhasm: return
ret
