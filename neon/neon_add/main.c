#include <stdio.h>
#include <stdint.h>

// 假設以下 extern 對應到你在 .S 檔中實作的函式，
// 依照向量元素寬度 (8,16,32,64 bits) 寫成四種版本。
extern void neon_add_8 ( int8_t  *r, const int8_t  *a, const int8_t  *b );
extern void neon_add_16(int16_t *r, const int16_t *a, const int16_t *b );
extern void neon_add_32(int32_t *r, const int32_t *a, const int32_t *b );
extern void neon_add_64(int64_t *r, const int64_t *a, const int64_t *b );

// 這裡包含你自行實作的「列印向量」函式 (假設路徑與之前教學相同)
#include "../utils/print_int_arrays.h"

int main(void)
{
    /*
      1) 8-bit 測試 (int8_t x16)：
         放 16 個元素，包含正數、負數、大值、小值。
         注意 8-bit 加法會以 (mod 2^8) wrap-around。
         例如 127 + 1 = -128 (0x80)，-1 + -127 = 128 (0x80) 等。
    */
    int8_t a8[16] = {
        127,   1,  -1,  -128,
         10, -120,   50,   60,
         99,  -99,  100, -100,
         30,  -30,    2,   -2
    };
    int8_t b8[16] = {
         1,   2,  -2,   -1,
        -10,  120,  50,  70,
        -99,   99,  28,  100,
         30,  -30, 127, -127
    };
    int8_t r8[16] = {0};

    /*
      2) 16-bit 測試 (int16_t x8)：
         同樣包含各式正負值。
         16-bit 加法為 (mod 2^16) wrap-around。
         例如 32767 + 1 = -32768 (0x8000)。
    */
    int16_t a16[8] = {
        32767, -32768,  1000,  -1000,
          123,   -123, 30000, -30000
    };
    int16_t b16[8] = {
           1,      1,  999,   -999,
         -123,    123,  500,   -500
    };
    int16_t r16[8] = {0};

    /*
      3) 32-bit 測試 (int32_t x4)：
         32-bit 加法亦 (mod 2^32) wrap-around。
         例如 2147483647 + 1 = -2147483648。
    */
    int32_t a32[4] = {
        2147483647, -2147483648, 100000, -100000
    };
    int32_t b32[4] = {
                1,           1, 99999, -99999
    };
    int32_t r32[4] = {0};

    /*
      4) 64-bit 測試 (int64_t x2)：
         64-bit 加法為 (mod 2^64) wrap-around。
         例如 9223372036854775807 + 1 = -9223372036854775808 (超過最大正值後轉為最小負值)。
         這裡只示範 2 個元素 (v0.2d)。
    */
    int64_t a64[2] = {
        9223372036854775807LL, -9223372036854775807LL
    };
    int64_t b64[2] = {
        1LL, -1LL
    };
    int64_t r64[2] = {0};

    // 呼叫 neon_add_xx 函式
    neon_add_8(r8, a8, b8);
    neon_add_16(r16, a16, b16);
    neon_add_32(r32, a32, b32);
    neon_add_64(r64, a64, b64);

    // 印出結果 (8-bit)
    printf("======== ADD 8-bit demo (mod 2^8) ========\n");
    print_int8x16(a8);
    print_int8x16(b8);
    print_int8x16(r8);

    print_int8x16_with_binary(a8);
    print_int8x16_with_binary(b8);
    print_int8x16_with_binary(r8);

    // 印出結果 (16-bit)
    printf("\n======== ADD 16-bit demo (mod 2^16) ========\n");
    print_int16x8(a16);
    print_int16x8(b16);
    print_int16x8(r16);

    print_int16x8_with_binary(a16);
    print_int16x8_with_binary(b16);
    print_int16x8_with_binary(r16);

    // 印出結果 (32-bit)
    printf("\n======== ADD 32-bit demo (mod 2^32) ========\n");
    print_int32x4(a32);
    print_int32x4(b32);
    print_int32x4(r32);

    print_int32x4_with_binary(a32);
    print_int32x4_with_binary(b32);
    print_int32x4_with_binary(r32);

    // 印出結果 (64-bit)
    printf("\n======== ADD 64-bit demo (mod 2^64) ========\n");
    print_int64x2(a64);
    print_int64x2(b64);
    print_int64x2(r64);

    print_int64x2_with_binary(a64);
    print_int64x2_with_binary(b64);
    print_int64x2_with_binary(r64);

    printf("\n(以上各型別的加法都採用對應位寬的二補數運算，超過範圍部分會以 mod 2^N 形式溢位)\n");
    return 0;
}
