#include <stdio.h>
#include <stdint.h>

// 假設以下 extern 對應到你在 .S 檔中以 NEON ABS 指令實作的四個函式：
extern void neon_abs_8 ( int8_t  *r, const  int8_t  *a );
extern void neon_abs_16(int16_t *r, const int16_t *a );
extern void neon_abs_32(int32_t *r, const int32_t *a );
extern void neon_abs_64(int64_t *r, const int64_t *a );

// 這裡包含你自行實作的「列印向量」函式 (假設路徑與前面教學相同)：
#include "../utils/print_int_arrays.h"

int main(void)
{
    /*
      1) 8-bit 測試 (int8_t x16)
         -128 (0x80) 是最小負值，取絕對值後依舊會是 -128。
    */
    int8_t a8[16] = {
         0,    1,    -1,    127,
        -127, -50,   -128,   50,
         10,  -10,     2,     -2,
         99,  -99,   100,   -100
    };
    int8_t r8[16] = {0};

    /*
      2) 16-bit 測試 (int16_t x8)
         -32768 是 16-bit 的最小負值。
    */
    int16_t a16[8] = {
         0,   -1,   123,   -999,
         32767, -32768,  1000,  -1000
    };
    int16_t r16[8] = {0};

    /*
      3) 32-bit 測試 (int32_t x4)
         -2147483648 是 32-bit 最小負值。
    */
    int32_t a32[4] = {
         0, -1,  2147483647, -2147483648
    };
    int32_t r32[4] = {0};

    /*
      4) 64-bit 測試 (int64_t x2)
         -9223372036854775808 是 64-bit 最小負值。
         這裡只示範 2 個元素 (v0.2d)。
    */
    int64_t a64[2] = {
        -1, -9223372036854775807LL  // 可以也加 -9223372036854775808 做觀察
    };
    int64_t r64[2] = {0};

    // 呼叫 NEON ABS 函式 (在 .S 檔中以 abs 指令實作)
    neon_abs_8(r8,   a8);
    neon_abs_16(r16, a16);
    neon_abs_32(r32, a32);
    neon_abs_64(r64, a64);

    // 印出結果 (8-bit)
    printf("========== ABS 8-bit demo ==========\n");
    printf("Input (int8x16):\n");
    print_int8x16(a8);
    printf("Result (int8x16):\n");
    print_int8x16(r8);

    // 印出結果 (16-bit)
    printf("\n========== ABS 16-bit demo ==========\n");
    printf("Input (int16x8):\n");
    print_int16x8(a16);
    printf("Result (int16x8):\n");
    print_int16x8(r16);

    // 印出結果 (32-bit)
    printf("\n========== ABS 32-bit demo ==========\n");
    printf("Input (int32x4):\n");
    print_int32x4(a32);
    printf("Result (int32x4):\n");
    print_int32x4(r32);

    // 印出結果 (64-bit)
    printf("\n========== ABS 64-bit demo ==========\n");
    printf("Input (int64x2):\n");
    print_int64x2(a64);
    printf("Result (int64x2):\n");
    print_int64x2(r64);

    // 結語
    printf("\n注意：若來源為該位寬的最小負值 (例如 -128, -32768, -2147483648, -9223372036854775808)，\n"
           "    取絕對值後依舊會是同樣位元模式，等於無法表示其正值 (非飽和運算)。\n");

    return 0;
}
