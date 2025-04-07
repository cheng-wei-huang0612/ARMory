#include <stdio.h>
#include <stdint.h>

//----------------------------------
// 組語實作的函式宣告 (皆為 void)
// 8-bit
extern void neon_addp_8_8b  (int8_t  *r, const int8_t  *a, const int8_t  *b);
extern void neon_addp_8_16b (int8_t  *r, const int8_t  *a, const int8_t  *b);
// 16-bit
extern void neon_addp_16_4h (int16_t *r, const int16_t *a, const int16_t *b);
extern void neon_addp_16_8h (int16_t *r, const int16_t *a, const int16_t *b);
// 32-bit
extern void neon_addp_32_2s (int32_t *r, const int32_t *a, const int32_t *b);
extern void neon_addp_32_4s (int32_t *r, const int32_t *a, const int32_t *b);
// 64-bit (128 bits => 2D)
extern void neon_addp_64_2d (int64_t *r, const int64_t *a, const int64_t *b);

//----------------------------------
// 列印向量的輔助函式 (假設你已有印出 N 個元素的函式)
#include "../utils/print_int_arrays.h"

int main(void)
{
    /*
     * 1) 8-bit, 64-bit (v0.8b, v1.8b => result.8b)
     *    8 lanes of int8_t
     */
    {
        int8_t a[16] = {1,2,3,4, -1,-2,-3,-4,0,0,0,0,0,0,0,0};
        int8_t b[16] = {10,20,30,40, 100, 120, 127, -128,0,0,0,0,0,0,0,0};
        int8_t r[16] = {0};

        neon_addp_8_8b(r, a, b);

        printf("[8-bit, 64-bit] Pairwise add:\n");
        print_int8x16(a);
        print_int8x16(b);
        printf("=> addp ->\n");
        print_int8x16(r);
        printf("\n");
    }

    /*
     * 2) 8-bit, 128-bit (v0.16b, v1.16b => result.16b)
     *    16 lanes of int8_t
     */
    {
        int8_t a[16] = {
            1,2,3,4,5,6,7,8,
            10,11,12,13,14,15,16,17
        };
        int8_t b[16] = {
            -1,-2,-3,-4,-5,-6,-7,-8,
             1,  2,  3,  4,  5,  6,  7,  8
        };
        int8_t r[16] = {0};

        neon_addp_8_16b(r, a, b);

        printf("[8-bit, 128-bit] Pairwise add:\n");
        print_int8x16(a);
        print_int8x16(b);
        printf("=> addp ->\n");
        print_int8x16(r);
        printf("\n");
    }

    /*
     * 3) 16-bit, 64-bit (v0.4h, v1.4h => result.4h)
     *    4 lanes of int16_t
     */
    {
        int16_t a[8] = {1000, 2000, -3000, -4000, 0, 0, 0, 0};
        int16_t b[8] = {1, 2, 300, 400, 0, 0, 0, 0};
        int16_t r[8] = {0};

        neon_addp_16_4h(r, a, b);

        printf("[16-bit, 64-bit] Pairwise add:\n");
        print_int16x8(a);
        print_int16x8(b);
        printf("=> addp ->\n");
        print_int16x8(r);
        printf("\n");
    }

    /*
     * 4) 16-bit, 128-bit (v0.8h, v1.8h => result.8h)
     *    8 lanes of int16_t
     */
    {
        int16_t a[8] = {0,1,2,3, 4,5,6,7};
        int16_t b[8] = {-1,-2,-3,-4, 100, 200, 999, -999};
        int16_t r[8] = {0};

        neon_addp_16_8h(r, a, b);

        printf("[16-bit, 128-bit] Pairwise add:\n");
        print_int16x8(a);
        print_int16x8(b);
        printf("=> addp ->\n");
        print_int16x8(r);
        printf("\n");
    }

    /*
     * 5) 32-bit, 64-bit (v0.2s, v1.2s => result.2s)
     *    2 lanes of int32_t
     */
    {
        int32_t a[4] = { 100000, -100000, 0, 0 };
        int32_t b[4] = { 123456,  -654321, 0, 0 };
        int32_t r[4] = {0};

        neon_addp_32_2s(r, a, b);

        printf("[32-bit, 64-bit] Pairwise add:\n");
        print_int32x4(a);
        print_int32x4(b);
        printf("=> addp ->\n");
        print_int32x4(r);
        printf("\n");
    }

    /*
     * 6) 32-bit, 128-bit (v0.4s, v1.4s => result.4s)
     *    4 lanes of int32_t
     */
    {
        int32_t a[4] = {1,2,3,4};
        int32_t b[4] = {-1,-2,-3,-4};
        int32_t r[4] = {0};

        neon_addp_32_4s(r, a, b);

        printf("[32-bit, 128-bit] Pairwise add:\n");
        print_int32x4(a);
        print_int32x4(b);
        printf("=> addp ->\n");
        print_int32x4(r);
        printf("\n");
    }

    /*
     * 7) 64-bit, 128-bit (v0.2d, v1.2d => result.2d)
     *    2 lanes of int64_t
     */
    {
        int64_t a[2] = { 123456789012345LL, -123456789012345LL };
        int64_t b[2] = { 999999999999999LL, 1LL };
        int64_t r[2] = {0,0};

        neon_addp_64_2d(r, a, b);

        printf("[64-bit, 128-bit] Pairwise add:\n");
        print_int64x2(a);
        print_int64x2(b);
        printf("=> addp ->\n");
        print_int64x2(r);
        printf("\n");
    }

    printf("All done.\n");
    return 0;
}
