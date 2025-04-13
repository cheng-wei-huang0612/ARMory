// single_cycle_with_dep.S
.global _main
_main:
    mov x0, #0

    // Unroll 10 times
    // 每個 add 都使用 x0 (前面結果)
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10
    add x0, x0, #10

    ret

