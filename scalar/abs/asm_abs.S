

.align 4
.global _asm_abs
.global asm_abs
_asm_abs:
asm_abs:


ldr x1, [x1]

abs x1, x1

str x1, [x0]


ret


