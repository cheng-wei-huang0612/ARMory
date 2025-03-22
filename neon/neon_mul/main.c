#include <stdio.h>
#include <stdint.h>

// 這是原本的 Assembly 函式宣告，維持不變
extern void neon_mul_8(int8_t *r, const int8_t *a, const int8_t *b);
extern void neon_mul_16(int16_t *r, const int16_t *a, const int16_t *b);
extern void neon_mul_32(int32_t *r, const int32_t *a, const int32_t *b);

// 包含我們的「列印向量」函式
#include "../utils/print_int_arrays.h"


int main(void) {
    // Prepare input data for 8-bit vectors (16 elements)
    int8_t a8[16] = {  1,   2, 100, -50, 120,   7, -128, 127,
                       3,   4,   5,   6,  12, -30,  100,  -1 };
    int8_t b8[16] = {  2,  -2,   2,   3,   2, -10,    2,   2,
                      -3,  -4,   5,   6,  12,  30,  100,  -1 };
    int8_t r8[16] = {  0 };

    // Prepare input data for 16-bit vectors (8 elements)
    int16_t a16[8] = { 1000, -2000, 30000, -30000, 100, -100, 32767, -32768 };
    int16_t b16[8] = {    2,     3,     4,      5, 300, -300,     2,      2 };
    int16_t r16[8] = {    0 };

    // Prepare input data for 32-bit vectors (4 elements)
    int32_t a32[4] = { 100000, -100000, 2000000000, -2000000000 };
    int32_t b32[4] = {       2,       3,          2,           3 };
    int32_t r32[4] = {       0 };

    // 執行 NEON 整數乘法（mod 2^n 進行遮罩/溢位）
    neon_mul_8(r8, a8, b8);
    neon_mul_16(r16, a16, b16);
    neon_mul_32(r32, a32, b32);

    printf("NEON vector multiply with different integer sizes (mod 2^n wrap-around):\n\n");

    // 以表格方式印出三組結果
    printf("-------- 8-bit results --------\n");
    print_int8x16(a8);
    print_int8x16(b8);
    print_int8x16(r8);

    print_int8x16_with_binary(a8);
    print_int8x16_with_binary(b8);
    print_int8x16_with_binary(r8);
    printf("------- 16-bit results --------\n");
    print_int16x8(a16);
    print_int16x8(b16);
    print_int16x8(r16);

    print_int16x8_with_binary(a16);
    print_int16x8_with_binary(b16);
    print_int16x8_with_binary(r16);
    printf("------- 32-bit results --------\n");
    print_int32x4(a32);
    print_int32x4(b32);
    print_int32x4(r32);

    print_int32x4_with_binary(a32);
    print_int32x4_with_binary(b32);
    print_int32x4_with_binary(r32);

    return 0;
}

