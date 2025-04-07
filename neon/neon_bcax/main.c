#include <stdio.h>
#include <stdint.h>

// 外部函式宣告 (在 .S 檔中實作)
extern void neon_bcax_128(
    uint8_t *result,      // [x0]
    const uint8_t *srcA,  // [x1]
    const uint8_t *srcB,  // [x2]
    const uint8_t *srcC   // [x3]
);

// 假設你有印出 8-bit x16 的函式
#include "../utils/print_int_arrays.h"

int main(void)
{
    // -----------------------------
    // 測試 1: 放一些簡單的 8-bit 值
    // -----------------------------
    uint8_t A1[16] = {0xFF, 0x00, 0xAA, 0x55,  0x12, 0x34, 0x56, 0x78,
                      0x11, 0x22, 0x33, 0x44,  0x0F, 0xF0, 0xCC, 0x3C};
    uint8_t B1[16] = {0xFF, 0xFF, 0x00, 0xFF,  0x12, 0xAB, 0x56, 0x01,
                      0x11, 0x77, 0xEE, 0x12,  0x66, 0x90, 0x77, 0xCE};
    uint8_t C1[16] = {0x00, 0xFF, 0x0F, 0xF0,  0x55, 0x55, 0x55, 0x55,
                      0xAA, 0xBB, 0xCC, 0xDD,  0xEF, 0xFE, 0x11, 0x03};

    uint8_t R1[16] = {0};

    neon_bcax_128(R1, A1, B1, C1);

    printf("[BCAX demo #1]\n");
    printf("A1 (16 bytes):\n"); print_uint8x16_with_binary(A1);
    printf("B1 (16 bytes):\n"); print_uint8x16_with_binary(B1);
    printf("C1 (16 bytes):\n"); print_uint8x16_with_binary(C1);

    // 按公式 => R1 = A1 ^ (B1 & ~C1)
    // 請注意 R1 也是 16 bytes
    printf("=> R1 = A1 ^ ( B1 & ~C1 )\n");
    print_uint8x16_with_binary(R1);
    printf("\n");


    // -----------------------------
    // 測試 2: 放隨機或重複 pattern
    // -----------------------------
    uint8_t A2[16] = {
        0xDE, 0xAD, 0xBE, 0xEF,  0xDE, 0xAD, 0xBE, 0xEF,
        0xFF, 0xFF, 0x00, 0x00,  0x12, 0x34, 0x56, 0x78
    };
    uint8_t B2[16] = {
        0x01, 0x02, 0x03, 0x04,  0xFE, 0xEE, 0xDC, 0xCB,
        0xF0, 0x0F, 0xF0, 0x0F,  0xAA, 0x55, 0xBB, 0x66
    };
    uint8_t C2[16] = {
        0xAA, 0xAA, 0xBB, 0xBB,  0xCC, 0xCC, 0xCC, 0xCC,
        0x00, 0x00, 0xFF, 0xFF,  0x12, 0x12, 0xF0, 0xFF
    };

    uint8_t R2[16] = {0};

    neon_bcax_128(R2, A2, B2, C2);

    printf("[BCAX demo #2]\n");
    printf("A2 (16 bytes):\n"); print_uint8x16_with_binary(A2);
    printf("B2 (16 bytes):\n"); print_uint8x16_with_binary(B2);
    printf("C2 (16 bytes):\n"); print_uint8x16_with_binary(C2);

    printf("=> R2 = A2 ^ ( B2 & ~C2 )\n");
    print_uint8x16_with_binary(R2);

    printf("\nDone.\n");
    return 0;
}
