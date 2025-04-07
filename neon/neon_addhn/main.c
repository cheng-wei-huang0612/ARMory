#include <stdio.h>
#include <stdint.h>

// (1) 16-bit → 8-bit
extern void neon_addhn_16_to_8 (int8_t  *r, const int16_t *a, const int16_t *b);
extern void neon_addhn2_16_to_8(int8_t  *r, const int16_t *a, const int16_t *b);

// (2) 32-bit → 16-bit
extern void neon_addhn_32_to_16 (int16_t *r, const int32_t *a, const int32_t *b);
extern void neon_addhn2_32_to_16(int16_t *r, const int32_t *a, const int32_t *b);

// (3) 64-bit → 32-bit
extern void neon_addhn_64_to_32 (int32_t *r, const int64_t *a, const int64_t *b);
extern void neon_addhn2_64_to_32(int32_t *r, const int64_t *a, const int64_t *b);

// 包含你自行實作的「列印向量」函式 (假設路徑與前述範例相同)
#include "../utils/print_int_arrays.h"

int main(void)
{
    /*
      ===============================================================
       (1) 16-bit → 8-bit : ADDHN / ADDHN2
      ===============================================================
    */
    // 準備 8 個 16-bit 數
    int16_t a16[8] = {
        1000,  -1000,  20000, -20000,
         32767, -32768, 12345, -12345
    };
    int16_t b16[8] = {
         500,   -500,  30000, -10000,
         1,       2,   9999,  -9999
    };

    // ADDHN 產生的結果只有「8-bit × 8 lanes」，用 r8_addhn 存放
    int8_t  r8_addhn[16]  = {0};

    // ADDHN2 則會把結果放進目的暫存器的高半 (upper half)，
    // 因此對應到「8-bit × 16 lanes」。我們只示範存成 int8_t[16] 觀察。
    int8_t  r8_addhn2[16] = {0};

    // 執行 ADDHN 和 ADDHN2
    neon_addhn_16_to_8(r8_addhn,   a16, b16);
    neon_addhn2_16_to_8(r8_addhn2, a16, b16);

    printf("===== 16-bit -> 8-bit (ADDHN / ADDHN2) =====\n");
    printf("[Source A 16-bit]:\n");
    print_int16x8(a16);
    printf("[Source B 16-bit]:\n");
    print_int16x8(b16);

    printf("\n[ADDHN result (stored into lower half => 8 elements)]:\n");
    print_int8x16(r8_addhn);

    printf("\n[ADDHN2 result (stored into upper half => 16 elements)]:\n");
    print_int8x16(r8_addhn2);
    printf("(Observe that the lower 8 bytes of r8_addhn2 might be all zeros or unchanged,\n"
           " while the upper 8 bytes hold the new high-narrow results.)\n\n");



    /*
      ===============================================================
       (2) 32-bit → 16-bit : ADDHN / ADDHN2
      ===============================================================
    */
    // 準備 4 個 32-bit 數
    int32_t a32[4] = {
        200000,  -300000, 2147483647, -2147483648
    };
    int32_t b32[4] = {
        100000,  -100000,          1,           2
    };

    // ADDHN => 16-bit x4
    int16_t r16_addhn[8]   = {0};
    // ADDHN2 => 16-bit x8
    int16_t r16_addhn2[8]  = {0};

    neon_addhn_32_to_16(r16_addhn,   a32, b32);
    neon_addhn2_32_to_16(r16_addhn2, a32, b32);

    printf("===== 32-bit -> 16-bit (ADDHN / ADDHN2) =====\n");
    printf("[Source A 32-bit]:\n");
    print_int32x4(a32);
    printf("[Source B 32-bit]:\n");
    print_int32x4(b32);

    printf("\n[ADDHN result (16-bit x4)]:\n");
    print_int16x8(r16_addhn);

    printf("\n[ADDHN2 result (16-bit x8)]:\n");
    print_int16x8(r16_addhn2);
    printf("(Again, the lower 4 elements might be untouched or zero, and the upper 4 hold the new data.)\n\n");



    /*
      ===============================================================
       (3) 64-bit → 32-bit : ADDHN / ADDHN2
      ===============================================================
    */
    // 準備 2 個 64-bit 數
    int64_t a64[2] = {
        10000000000LL,  -10000000000LL
    };
    int64_t b64[2] = {
        9999999999LL,   -9999999999LL
    };

    // ADDHN => 32-bit x2
    int32_t r32_addhn[4]   = {0};
    // ADDHN2 => 32-bit x4
    int32_t r32_addhn2[4]  = {0};

    neon_addhn_64_to_32(r32_addhn,   a64, b64);
    neon_addhn2_64_to_32(r32_addhn2, a64, b64);

    printf("===== 64-bit -> 32-bit (ADDHN / ADDHN2) =====\n");
    printf("[Source A 64-bit]:\n");
    print_int64x2(a64);
    printf("[Source B 64-bit]:\n");
    print_int64x2(b64);

    printf("\n[ADDHN result (32-bit x2)]:\n");
    print_int32x4(r32_addhn);

    printf("\n[ADDHN2 result (32-bit x4)]:\n");
    print_int32x4(r32_addhn2);
    printf("(Lower half is old data or zero; upper half is the newly added high-narrow data.)\n\n");

    // 小結
    printf("=== Demo of ADDHN/ADDHN2 complete ===\n");
    printf("High half of each sum is preserved in the narrower element. The lower half is discarded.\n");
    return 0;
}
