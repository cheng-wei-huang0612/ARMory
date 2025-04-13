// multi_cycle_no_dep.S
.global _main
.global main
_main:
main:
    // Unroll 10 times
    mov w5, #123
    mov w6, #456
    mov w7, #789
    mov w8, #12

    // 前後輸出都不用同一個暫存器
    umull x0, w5, w6
    umull x1, w5, w7
    umull x2, w5, w8
    umull x3, w6, w7
    umull x4, w6, w8
    umull x9, w7, w8
    umull x10, w7, w5
    umull x11, w8, w5
    umull x12, w8, w6
    umull x13, w6, w7

    ret

