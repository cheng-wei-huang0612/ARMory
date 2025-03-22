#include <stdio.h>
#include <stdint.h>

#include "../utils/print_int_arrays.h"
/*
  這些 extern 宣告對應到你稍後會在 .S 檔裡實作的函式。
  例如:
    neon_umull_8  : 以 UMULL 指令，針對 uint8_t 陣列做無號乘法，結果放進 uint16_t 陣列
    neon_umull_16 : 以 UMULL 指令，針對 uint16_t 陣列做無號乘法，結果放進 uint32_t 陣列
    neon_umull_32 : 以 UMULL 指令，針對 uint32_t 陣列做無號乘法，結果放進 uint64_t 陣列
*/
extern void neon_umull_8 (uint16_t *r, const uint8_t *a, const uint8_t *b);
extern void neon_umull2_8 (uint16_t *r, const uint8_t *a, const uint8_t *b);
extern void neon_umull_16(uint32_t *r, const uint16_t *a, const uint16_t *b);
extern void neon_umull2_16(uint32_t *r, const uint16_t *a, const uint16_t *b);
extern void neon_umull_32(uint64_t *r, const uint32_t *a, const uint32_t *b);
extern void neon_umull2_32(uint64_t *r, const uint32_t *a, const uint32_t *b);




int main(void) {
    /*
      1) 8-bit → 16-bit (UMULL)
         這裡使用 16 個 8-bit 數值，對應乘出 16 個 16-bit 結果。
    */
    uint8_t a8[16] = {
        1,  2,  10,  255,  100,  128,   0,  50,
        8,  9,  12,   20,    3,    4,   6,  25
    };
    uint8_t b8[16] = {
        2,  3,  10,  255,   50,  200,  10,  25,
        8,  9,  12,   20,   40,   10,   5,   4
    };
    uint16_t umull_result16[8] = { 0 };
    uint16_t umull2_result16[8] = { 0 };

    /*
      2) 16-bit → 32-bit (UMULL)
         這裡使用 8 個 16-bit 數值。
    */
    uint16_t a16[8] = {
        1000,  50000,  65535, 12345,
        10,    999,    32768, 1
    };
    uint16_t b16[8] = {
        2,     2,      100,   20000,
        300,   60000,  2,      65535
    };
    uint32_t umull_result32[4] = { 0 };
    uint32_t umull2_result32[4] = { 0 };

    /*
      3) 32-bit → 64-bit (UMULL)
         這裡使用 4 個 32-bit 數值。
    */
    uint32_t a32[4] = {
        1000000000U,  4000000000U,  1234567890U,  2147483647U
    };
    uint32_t b32[4] = {
        2U,           10U,          3000U,        12345U
    };
    uint64_t umull_result64[2] = { 0 };
    uint64_t umull2_result64[2] = { 0 };

    /*
      分別呼叫三個 extern 函式，對應 UMULL 8->16, 16->32, 32->64
      你將在 .S 檔中以 NEON 指令 (UMULL 或 UMULL2) 來實作這些函式。
    */
    neon_umull_8(umull_result16, a8, b8);
    neon_umull_16(umull_result32, a16, b16);
    neon_umull_32(umull_result64, a32, b32);

    neon_umull2_8(umull2_result16, a8, b8);
    neon_umull2_16(umull2_result32, a16, b16);
    neon_umull2_32(umull2_result64, a32, b32);


    printf("\n--- UMULL demo: 8-bit => 16-bit ---\n");
    print_uint8x16(a8);
    print_uint8x16(b8);
    print_uint16x8(umull_result16);

    print_uint8x16_with_binary(a8);
    print_uint8x16_with_binary(b8);
    print_uint16x8_with_binary(umull_result16);

    printf("\nAssertion (python check):\n");
    for (int i = 0; i < 8; i++) {
        printf("python: ((%u * %u) - %u) %% (2**16) == 0\n",
               (unsigned)a8[i], (unsigned)b8[i], (unsigned)umull_result16[i]);
    }
    printf("copy and paste to python repl to verify the results.\n\n");

    printf("\n--- UMULL2 demo: 8-bit => 16-bit ---\n");
    print_uint8x16(a8);
    print_uint8x16(b8);
    print_uint16x8(umull2_result16);

    print_uint8x16_with_binary(a8);
    print_uint8x16_with_binary(b8);
    print_uint16x8_with_binary(umull2_result16);

    printf("\nAssertion (python check):\n");
    for (int i = 0; i < 8; i++) {
        printf("python: ((%u * %u) - %u) %% (2**16) == 0\n",
               (unsigned)a8[8+i], (unsigned)b8[8+i], (unsigned)umull2_result16[i]);
    }
    printf("copy and paste to python repl to verify the results.\n\n");



    printf("--- UMULL demo: 16-bit => 32-bit ---\n");
    print_uint16x8(a16);
    print_uint16x8(b16);
    print_uint32x4(umull_result32);

    print_uint16x8_with_binary(a16);
    print_uint16x8_with_binary(b16);
    print_uint32x4_with_binary(umull_result32);
    printf("\nAssertion (python check):\n");
    for (int i = 0; i < 4; i++) {
        printf("python: ((%u * %u) - %u) %% (2**32) == 0\n",
               (unsigned)a16[i], (unsigned)b16[i], (unsigned)umull_result32[i]);
    }
    printf("copy and paste to python repl to verify the results.\n\n");

    printf("--- UMULL2 demo: 16-bit => 32-bit ---\n");
    print_uint16x8(a16);
    print_uint16x8(b16);
    print_uint32x4(umull2_result32);

    print_uint16x8_with_binary(a16);
    print_uint16x8_with_binary(b16);
    print_uint32x4_with_binary(umull2_result32);
    printf("\nAssertion (python check):\n");
    for (int i = 0; i < 4; i++) {
        printf("python: ((%u * %u) - %u) %% (2**32) == 0\n",
               (unsigned)a16[4+i], (unsigned)b16[4+i], (unsigned)umull2_result32[i]);
    }
    printf("copy and paste to python repl to verify the results.\n\n");


    printf("--- UMULL demo: 32-bit => 64-bit ---\n");
    print_uint32x4(a32);
    print_uint32x4(b32);
    print_uint64x2(umull_result64);

    print_uint32x4_with_binary(a32);
    print_uint32x4_with_binary(b32);
    print_uint64x2_with_binary(umull_result64);
    printf("\nAssertion (python check):\n");
    for (int i = 0; i < 2; i++) {
        printf("python: ((%llu * %llu) - %llu) %% (2**64) == 0\n",
               (unsigned long long)a32[i], (unsigned long long)b32[i], (unsigned long long)umull_result64[i]);
    }
    printf("copy and paste to python repl to verify the results.\n\n");

    printf("--- UMULL2 demo: 32-bit => 64-bit ---\n");
    print_uint32x4(a32);
    print_uint32x4(b32);
    print_uint64x2(umull2_result64);

    print_uint32x4_with_binary(a32);
    print_uint32x4_with_binary(b32);
    print_uint64x2_with_binary(umull2_result64);
    printf("\nAssertion (python check):\n");
    for (int i = 0; i < 2; i++) {
        printf("python: ((%llu * %llu) - %llu) %% (2**64) == 0\n",
               (unsigned long long)a32[2+i], (unsigned long long)b32[2+i], (unsigned long long)umull2_result64[i]);
    }
    printf("copy and paste to python repl to verify the results.\n\n");

    return 0;
}

