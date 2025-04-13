// multi_cycle_with_dep.S
.global _main
.global main
_main:
main:
    mov w5, #123
    mov w6, #456

    // Unroll 10 times
    // 這裡每次都使用 x0 (上一次結果) 作為下一次的輸入
    // 先把 x0 init = 0
    mov x0, #0

    // 1) x0 = w5 * w6
    umull x0, w5, w6

    // 2) w0 = 低32 bits (x0本身)
    //   再乘 w6 => 形成強烈依賴
    umull x0, w0, w6

    // 再加幾次 unroll
    umull x0, w0, w5
    umull x0, w0, w6
    umull x0, w0, w5
    umull x0, w0, w6
    umull x0, w0, w5
    umull x0, w0, w6
    umull x0, w0, w5
    umull x0, w0, w6

    ret

