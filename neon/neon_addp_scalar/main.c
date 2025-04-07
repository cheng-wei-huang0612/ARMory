#include <stdio.h>
#include <stdint.h>

// 組語函式宣告 (64-bit pair)
extern void neon_addp_scalar(int64_t *result, const int64_t *src);

// 可供印出 (int64x2) 或其他長度的輔助函式
#include "../utils/print_int_arrays.h"

int main(void)
{
    /*
      1) 準備測試資料：每次放 2 個 int64_t 到陣列
         這兩個值將會被加總後 (a[0] + a[1]) 放進 result
    */
    int64_t a1[2] = {  100,  200 };
    int64_t a2[2] = { -500,  123 };
    int64_t a3[2] = { 1LL << 40,  -(1LL << 40) };
    int64_t a4[2] = { 0x7FFFFFFFFFFFFFFFLL,  1 }; // 測試 64-bit 溢位

    // 放結果
    int64_t r = 0;

    // 測試 1
    neon_addp_scalar(&r, a1);
    printf("Addp (2D) of \n");
    print_int64x2(a1);
    printf(" => result = %lld (0x%llX)\n\n", (long long)r, (unsigned long long)r);

    // 測試 2
    neon_addp_scalar(&r, a2);
    printf("Addp (2D) of \n");
    print_int64x2(a2);
    printf(" => result = %lld (0x%llX)\n\n", (long long)r, (unsigned long long)r);

    // 測試 3
    neon_addp_scalar(&r, a3);
    printf("Addp (2D) of \n");
    print_int64x2(a3);
    printf(" => result = %lld (0x%llX)\n\n", (long long)r, (unsigned long long)r);

    // 測試 4
    neon_addp_scalar(&r, a4);
    printf("Addp (2D) of \n");
    print_int64x2(a4);
    printf(" => result = %lld (0x%llX)\n\n", (long long)r, (unsigned long long)r);

    printf("Done.\n");
    return 0;
}
