#include <stdio.h>
#include <stdint.h>

// 這裡包含你自行實作的印出向量函式。
// （假設路徑和之前相同，若不同請自行調整）
#include "../utils/print_int_arrays.h"

/*
  這裡宣告在 .S 檔裡用 NEON zip 指令實作的函式：
    neon_zip_8  : 使用 ZIP1 指令針對 8-bit (16 個元素) 做交錯合併
    neon_zip2_8 : 使用 ZIP2 指令針對 8-bit (16 個元素) 做交錯合併
    neon_zip_16 : 使用 ZIP1 指令針對 16-bit (8 個元素)  做交錯合併
    neon_zip2_16: 使用 ZIP2 指令針對 16-bit (8 個元素)  做交錯合併
    neon_zip_32 : 使用 ZIP1 指令針對 32-bit (4 個元素)  做交錯合併
    neon_zip2_32: 使用 ZIP2 指令針對 32-bit (4 個元素)  做交錯合併
*/
extern void neon_zip1_8 (uint8_t *r, const uint8_t *a, const uint8_t *b);
extern void neon_zip2_8(uint8_t *r, const uint8_t *a, const uint8_t *b);

extern void neon_zip1_16 (uint16_t *r, const uint16_t *a, const uint16_t *b);
extern void neon_zip2_16(uint16_t *r, const uint16_t *a, const uint16_t *b);

extern void neon_zip1_32 (uint32_t *r, const uint32_t *a, const uint32_t *b);
extern void neon_zip2_32(uint32_t *r, const uint32_t *a, const uint32_t *b);


int main(void) {

    /*
      1) 8-bit 測試: a8, b8 分別有 16 個 8-bit 數，
         ZIP1/ZIP2 後依序交錯合併，結果仍是 16 個 8-bit。
         - zip1: 取「低一半」的交錯
         - zip2: 取「高一半」的交錯
    */
    uint8_t a8[16] = {
        0,   1,   2,   3, 100, 101, 102, 103,
        10, 11,  12,  13, 200, 201, 202, 203
    };
    uint8_t b8[16] = {
        50,  51,  52,  53, 250, 251, 252, 253,
        60,  61,  62,  63, 210, 211, 212, 213
    };
    uint8_t r8_zip1[16] = {0};
    uint8_t r8_zip2[16] = {0};

    // 呼叫 neon_zip_xxx
    neon_zip1_8(r8_zip1, a8, b8);
    neon_zip2_8(r8_zip2, a8, b8);

    printf("\n========== 8-bit ZIP demo ==========\n");
    printf("Input A (8-bit x16):\n");
    print_uint8x16(a8);
    printf("Input B (8-bit x16):\n");
    print_uint8x16(b8);

    printf("\n-- zip1 result (8-bit x16) --\n");
    print_uint8x16(r8_zip1);
    printf("-- zip2 result (8-bit x16) --\n");
    print_uint8x16(r8_zip2);

    /*
      2) 16-bit 測試: 各 8 個 16-bit 數，
         結果依序交錯，輸出仍為 8 個 16-bit
    */
    uint16_t a16[8] = {
        0, 1, 2, 3,
        65530, 65531, 65532, 65533
    };
    uint16_t b16[8] = {
        100, 101, 102, 103,
        60000, 60001, 60002, 60003
    };
    uint16_t r16_zip1[8] = {0};
    uint16_t r16_zip2[8] = {0};

    neon_zip1_16(r16_zip1, a16, b16);
    neon_zip2_16(r16_zip2, a16, b16);

    printf("\n========== 16-bit ZIP demo ==========\n");
    printf("Input A (16-bit x8):\n");
    print_uint16x8(a16);
    printf("Input B (16-bit x8):\n");
    print_uint16x8(b16);

    printf("\n-- zip1 result (16-bit x8) --\n");
    print_uint16x8(r16_zip1);
    printf("-- zip2 result (16-bit x8) --\n");
    print_uint16x8(r16_zip2);

    /*
      3) 32-bit 測試: 各 4 個 32-bit 數，
         結果依序交錯，輸出仍為 4 個 32-bit
    */
    uint32_t a32[4] = {
        0x00000001, 0xAAAAAAAA, 0x7FFFFFFF, 0xFEDCBA98
    };
    uint32_t b32[4] = {
        0x12345678, 0xFFFFFFFF, 0x01234567, 0x89ABCDEF
    };
    uint32_t r32_zip1[4] = {0};
    uint32_t r32_zip2[4] = {0};

    neon_zip1_32(r32_zip1, a32, b32);
    neon_zip2_32(r32_zip2, a32, b32);

    printf("\n========== 32-bit ZIP demo ==========\n");
    printf("Input A (32-bit x4):\n");
    print_uint32x4(a32);
    printf("Input B (32-bit x4):\n");
    print_uint32x4(b32);

    printf("\n-- zip1 result (32-bit x4) --\n");
    print_uint32x4(r32_zip1);
    printf("-- zip2 result (32-bit x4) --\n");
    print_uint32x4(r32_zip2);

    printf("\nDone.\n");
    return 0;
}
