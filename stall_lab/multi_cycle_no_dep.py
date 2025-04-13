#!/usr/bin/env python3
import sys

def main():
    # 若有帶參數，則用參數，否則預設 10000
    repeat = 10000
    if len(sys.argv) > 1:
        repeat = int(sys.argv[1])

    with open("multi_cycle_no_dep.S", "w") as f:
        f.write(".global main\n")
        f.write("main:\n")
        # w5, w6 設定為某些值，並在迴圈中使用 x2 (不相依鏈)
        f.write("    mov w5, #123\n")
        f.write("    mov w6, #456\n")

        for i in range(repeat):
            # 每次都使用同樣的來源 w5, w6，但存到 x2
            f.write("    umull x2, w5, w6\n")

        f.write("    ret\n")

if __name__ == "__main__":
    main()

