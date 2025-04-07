#include <stdio.h>
#include <stdint.h>

//---------------
// extern 函式宣告：
extern void neon_addv_8_8b  (int8_t  *result, const int8_t  *src);
extern void neon_addv_8_16b (int8_t  *result, const int8_t  *src);
extern void neon_addv_16_4h (int16_t *result, const int16_t *src);
extern void neon_addv_16_8h (int16_t *result, const int16_t *src);
extern void neon_addv_32_4s (int32_t *result, const int32_t *src);

// 輔助印出函式 (假設已有)
#include "../utils/print_int_arrays.h"

int main(void)
{
    /*
     * (1) 8-bit, 64-bit : ADDV Bd, Vn.8B
     *     8 個 int8_t 相加
     */
    {
        int8_t data[16] = {1,2,3,5, -1,-2,-3,-4,0,0,0,0,0,0,0,0};
        int8_t sum8 = 0;
        neon_addv_8_8b(&sum8, data);
        printf("[8-bit x8] addv result: src = \n");
        print_int8x16(data);
        printf(" => sum = %d (0x%02X)\n\n", sum8, (unsigned char)sum8);
    }

    /*
     * (2) 8-bit, 128-bit : ADDV Bd, Vn.16B
     *     16 個 int8_t 相加
     */
    {
        int8_t data[16] = {
            1,2,3,4,5,6,7,8,
            -1,-2,-3,-4,-5,-6,-7,-8
        };
        int8_t sum8 = 0;
        neon_addv_8_16b(&sum8, data);
        printf("[8-bit x16] addv result: src = \n");
        print_int8x16(data);
        printf(" => sum = %d (0x%02X)\n\n", sum8, (unsigned char)sum8);
    }

    /*
     * (3) 16-bit, 64-bit : ADDV Hd, Vn.4H
     *     4 個 int16_t 相加
     */
    {
        int16_t data[8] = {100, 200, -300, 400,0,0,0,0};
        int16_t sum16 = 0;
        neon_addv_16_4h(&sum16, data);
        printf("[16-bit x4] addv result: src = \n");
        print_int16x8(data);
        printf(" => sum = %d (0x%04X)\n\n", sum16, (unsigned short)sum16);
    }

    /*
     * (4) 16-bit, 128-bit : ADDV Hd, Vn.8H
     *     8 個 int16_t 相加
     */
    {
        int16_t data[8] = {10,20,30,40, -1,-2,-3,-4};
        int16_t sum16 = 0;
        neon_addv_16_8h(&sum16, data);
        printf("[16-bit x8] addv result: src = \n");
        print_int16x8(data);
        printf(" => sum = %d (0x%04X)\n\n", sum16, (unsigned short)sum16);
    }

    /*
     * (5) 32-bit, 128-bit : ADDV Sd, Vn.4S
     *     4 個 int32_t 相加
     */
    {
        int32_t data[4] = {
            100000, -100000,  2000000000, -2000000000
        };
        int32_t sum32 = 0;
        neon_addv_32_4s(&sum32, data);
        printf("[32-bit x4] addv result: src = \n");
        print_int32x4(data);
        printf(" => sum = %d (0x%08X)\n\n", sum32, (unsigned)sum32);
    }

    printf("ADDV demo complete.\n");
    return 0;
}
