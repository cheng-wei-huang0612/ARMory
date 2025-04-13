#!/usr/bin/env python3
import sys

def main():
    # 若有帶參數，則用參數，否則預設 10000
    repeat = 10000
    if len(sys.argv) > 1:
        repeat = int(sys.argv[1])

    with open("single_cycle_no_dep.S", "w") as f:
        f.write(".global main\n")
        f.write("main:\n")
        # 先準備暫存器數值
        f.write("    mov x0, #100\n")
        f.write("    mov x1, #200\n")

        # 生成多次無資料相依的 ADD
        for i in range(repeat):
            f.write("    add x2, x0, x1\n")

        f.write("    ret\n")

if __name__ == "__main__":
    main()

