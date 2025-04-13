// single_cycle_no_dep.S
.global _main
.global main
_main:
main:
    // Unroll 10 times (示範)
    // 每個指令都無資料相依
    mov x0, #100     // 不斷初始化 x0, x1
    mov x1, #200

    add x2, x0, x1
    add x3, x0, x1
    add x4, x0, x1
    add x5, x0, x1
    add x6, x0, x1
    add x7, x0, x1
    add x8, x0, x1
    add x9, x0, x1
    add x10, x0, x1
    add x11, x0, x1

    ret

