#!/usr/bin/env python3
import sys

def main():
    # 若有帶參數，則用參數，否則預設 10000
    repeat = 10000
    if len(sys.argv) > 1:
        repeat = int(sys.argv[1])

    with open("multi_cycle_with_dep.S", "w") as f:
        f.write(".global main\n")
        f.write("main:\n")
        # 令 w5, w6 為乘法來源，x0 連續被覆蓋，形成依賴
        f.write("    mov w5, #123\n")
        f.write("    mov w6, #456\n")
        f.write("    mov x0, #1\n")  
        # 先給 x0 初值，以下把 x0 不斷替換成新結果

        for i in range(repeat):
            # umull x0, w0, w5 => x0(64 bits) = (lower 32 bits of x0) * w5
            # 這裡每次都依賴上一次 x0 的結果
            f.write("    umull x0, w0, w5\n")

        f.write("    ret\n")

if __name__ == "__main__":
    main()

