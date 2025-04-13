#!/usr/bin/env python3
import sys

def main():
    # 若有帶參數，則用參數，否則預設 10000
    repeat = 10000
    if len(sys.argv) > 1:
        repeat = int(sys.argv[1])

    with open("single_cycle_with_dep.S", "w") as f:
        f.write(".global main\n")
        f.write("main:\n")
        # 用 x0 來累積，形成強烈相依鏈
        f.write("    mov x0, #0\n")

        for i in range(repeat):
            f.write("    add x0, x0, #1\n")

        f.write("    ret\n")

if __name__ == "__main__":
    main()

