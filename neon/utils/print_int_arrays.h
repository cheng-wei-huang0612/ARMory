#ifndef PRINT_ARRAYS_H
#define PRINT_ARRAYS_H

#include <stdio.h>
#include <stdint.h>

// ----------------------------------------------------------------------
// 工具函式：將 val (最高可到 64 bits) 轉成二進位字串
// bits = 8, 16, 32, or 64
// out 需要能容納 (bits + 1) 個字元 (含 '\0')
static void to_binary_str_u64(uint64_t val, int bits, char *out) {
    for (int i = bits - 1; i >= 0; i--) {
        out[bits - 1 - i] = ((val >> i) & 1) ? '1' : '0';
    }
    out[bits] = '\0';
}

//============================================================================
//=============================   int8x16   ===================================
//============================================================================

// (1) 有號 int8x16
// ---------------------------
// | entry No.| e0 | e1 | ... e15 |
// |   signed |  x |  y |    ...
// | unsigned |  x |  y |    ...
static void print_int8x16(const int8_t *v) {
    // 第 1 列：entry No. 與 e0..e15
    printf("|%10s|", "entry No.");
    for (int i = 0; i < 16; i++) {
        char label[8];
        sprintf(label, "e%d", i);
        printf("%5s|", label);
    }
    printf("\n");

    // 第 2 列：signed
    printf("|%10s|", "signed");
    for (int i = 0; i < 16; i++) {
        printf("%5d|", v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 16; i++) {
        printf("%5u|", (uint8_t)v[i]);
    }
    printf("\n\n");
}

// (2) 有號 int8x16 (with binary)
// ---------------------------
// | entry No. | signed | unsigned | binary  |
// |    e0     |     x  |       x  |  011... |
// |    e1     |     y  |       y  |  ...    |
static void print_int8x16_with_binary(const int8_t *v)
{
    // 第一列（表頭）
    printf("|%10s|%8s|%10s|%25s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    // 資料列：每個元素佔一行
    for (int i = 0; i < 16; i++) {
        char bin_str[9];
        to_binary_str_u64((uint8_t)v[i], 8, bin_str);

        char label[8];
        sprintf(label, "e%d", i);

        // 最後欄位也是 10 寬
        printf("|%10s|%8d|%10u|%25s|\n",
               label,
               v[i],              // signed
               (uint8_t)v[i],     // unsigned
               bin_str            // binary
        );
    }
    printf("\n");
}

//=== 新增 (3) 無號 uint8x16 ===
// 與 int8x16 相同，但改用 uint8_t *v 做為參數；「signed」 欄位則用 (int8_t) 來轉。
static void print_uint8x16(const uint8_t *v) {
    printf("|%10s|", "entry No.");
    for (int i = 0; i < 16; i++) {
        char label[8];
        sprintf(label, "e%d", i);
        printf("%5s|", label);
    }
    printf("\n");

    // 第 2 列：signed (把 uint8_t 轉成 int8_t)
    printf("|%10s|", "signed");
    for (int i = 0; i < 16; i++) {
        printf("%5d|", (int8_t)v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned (直接用 uint8_t)
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 16; i++) {
        printf("%5u|", v[i]);
    }
    printf("\n\n");
}

//=== 新增 (4) 無號 uint8x16 + binary ===
static void print_uint8x16_with_binary(const uint8_t *v)
{
    printf("|%10s|%8s|%10s|%25s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    for (int i = 0; i < 16; i++) {
        char bin_str[9];
        to_binary_str_u64((uint64_t)v[i], 8, bin_str);

        char label[8];
        sprintf(label, "e%d", i);

        // signed 欄位印 (int8_t)v[i]
        printf("|%10s|%8d|%10u|%25s|\n",
               label,
               (int8_t)v[i],
               v[i],
               bin_str
        );
    }
    printf("\n");
}

//============================================================================
//=============================   int16x8   ===================================
//============================================================================

static void print_int16x8(const int16_t *v) {
    // 第 1 列：entry No. 與 e0..e7
    printf("|%10s|", "entry No.");
    for (int i = 0; i < 8; i++) {
        char label[8];
        sprintf(label, "e%d", i);
        printf("%7s|", label);
    }
    printf("\n");

    // 第 2 列：signed
    printf("|%10s|", "signed");
    for (int i = 0; i < 8; i++) {
        printf("%7d|", v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 8; i++) {
        printf("%7u|", (uint16_t)v[i]);
    }
    printf("\n\n");
}

static void print_int16x8_with_binary(const int16_t *v) {
    // 表頭：4 欄
    printf("|%10s|%8s|%10s|%25s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    for (int i = 0; i < 8; i++) {
        char bin_str[17];
        to_binary_str_u64((uint16_t)v[i], 16, bin_str);

        char label[8];
        sprintf(label, "e%d", i);
        printf("|%10s|%8d|%10u|%25s|\n",
               label,
               v[i],
               (uint16_t)v[i],
               bin_str
        );
    }
    printf("\n");
}

//=== 新增 (3) 無號 uint16x8 ===
static void print_uint16x8(const uint16_t *v) {
    printf("|%10s|", "entry No.");
    for (int i = 0; i < 8; i++) {
        char label[8];
        sprintf(label, "e%d", i);
        printf("%7s|", label);
    }
    printf("\n");

    // 第 2 列：signed (把 uint16_t 轉為 int16_t)
    printf("|%10s|", "signed");
    for (int i = 0; i < 8; i++) {
        printf("%7d|", (int16_t)v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned (直接印 uint16_t)
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 8; i++) {
        printf("%7u|", v[i]);
    }
    printf("\n\n");
}

static void print_uint16x8_with_binary(const uint16_t *v) {
    printf("|%10s|%8s|%10s|%25s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    for (int i = 0; i < 8; i++) {
        char bin_str[17];
        to_binary_str_u64((uint64_t)v[i], 16, bin_str);

        char label[8];
        sprintf(label, "e%d", i);
        printf("|%10s|%8d|%10u|%25s|\n",
               label,
               (int16_t)v[i],   // signed
               v[i],           // unsigned
               bin_str
        );
    }
    printf("\n");
}

//============================================================================
//=============================   int32x4   ===================================
//============================================================================

static void print_int32x4(const int32_t *v) {
    // 第 1 列：entry No. 與 e0..e3
    printf("|%10s|", "entry No.");
    for (int i = 0; i < 4; i++) {
        char label[8];
        sprintf(label, "e%d", i);
        printf("%12s|", label);
    }
    printf("\n");

    // 第 2 列：signed
    printf("|%10s|", "signed");
    for (int i = 0; i < 4; i++) {
        printf("%12d|", v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 4; i++) {
        printf("%12u|", (uint32_t)v[i]);
    }
    printf("\n\n");
}

static void print_int32x4_with_binary(const int32_t *v) {
    // 表頭：4 欄
    printf("|%10s|%12s|%12s|%34s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    for (int i = 0; i < 4; i++) {
        char bin_str[33];
        to_binary_str_u64((uint64_t)(uint32_t)v[i], 32, bin_str);

        char label[8];
        sprintf(label, "e%d", i);
        printf("|%10s|%12d|%12u|%34s|\n",
               label,
               v[i],
               (uint32_t)v[i],
               bin_str
        );
    }
    printf("\n");
}

//=== 新增 (3) 無號 uint32x4 ===
static void print_uint32x4(const uint32_t *v) {
    // 第 1 列
    printf("|%10s|", "entry No.");
    for (int i = 0; i < 4; i++) {
        char label[8];
        sprintf(label, "e%d", i);
        printf("%12s|", label);
    }
    printf("\n");

    // 第 2 列：signed (把 uint32_t 轉為 int32_t)
    printf("|%10s|", "signed");
    for (int i = 0; i < 4; i++) {
        printf("%12d|", (int32_t)v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned (直接印 uint32_t)
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 4; i++) {
        printf("%12u|", v[i]);
    }
    printf("\n\n");
}

static void print_uint32x4_with_binary(const uint32_t *v) {
    printf("|%10s|%12s|%12s|%34s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    for (int i = 0; i < 4; i++) {
        char bin_str[33];
        to_binary_str_u64((uint64_t)v[i], 32, bin_str);

        char label[8];
        sprintf(label, "e%d", i);
        printf("|%10s|%12d|%12u|%34s|\n",
               label,
               (int32_t)v[i],  // signed
               v[i],           // unsigned
               bin_str
        );
    }
    printf("\n");
}

//============================================================================
//=============================   int64x2   ===================================
//============================================================================

static void print_int64x2(const int64_t *v) {
    // 第 1 列：entry No. 與 e0, e1
    printf("|%10s|%24s|%24s|\n", "entry No.", "e0", "e1");

    // 第 2 列：signed
    printf("|%10s|", "signed");
    for (int i = 0; i < 2; i++) {
        printf("%24lld|", (long long)v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 2; i++) {
        printf("%24llu|", (unsigned long long)v[i]);
    }
    printf("\n\n");
}

static void print_int64x2_with_binary(const int64_t *v) {
    printf("|%10s|%24s|%24s|%66s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    for (int i = 0; i < 2; i++) {
        char bin_str[65];
        to_binary_str_u64((uint64_t)v[i], 64, bin_str);

        char label[8];
        sprintf(label, "e%d", i);
        printf("|%10s|%24lld|%24llu|%66s|\n",
               label,
               (long long)v[i],
               (unsigned long long)v[i],
               bin_str
        );
    }
    printf("\n");
}

//=== 新增 (3) 無號 uint64x2 ===
static void print_uint64x2(const uint64_t *v) {
    // 第 1 列
    printf("|%10s|%24s|%24s|\n", "entry No.", "e0", "e1");

    // 第 2 列：signed (把 uint64_t 轉為 int64_t)
    printf("|%10s|", "signed");
    for (int i = 0; i < 2; i++) {
        printf("%24lld|", (long long)(int64_t)v[i]);
    }
    printf("\n");

    // 第 3 列：unsigned
    printf("|%10s|", "unsigned");
    for (int i = 0; i < 2; i++) {
        printf("%24llu|", (unsigned long long)v[i]);
    }
    printf("\n\n");
}

static void print_uint64x2_with_binary(const uint64_t *v) {
    printf("|%10s|%24s|%24s|%66s|\n",
           "entry No.", "signed", "unsigned", "binary (little-endian)");

    for (int i = 0; i < 2; i++) {
        char bin_str[65];
        to_binary_str_u64(v[i], 64, bin_str);

        char label[8];
        sprintf(label, "e%d", i);
        printf("|%10s|%24lld|%24llu|%66s|\n",
               label,
               (long long)(int64_t)v[i],    // signed
               (unsigned long long)v[i],    // unsigned
               bin_str
        );
    }
    printf("\n");
}

#endif // PRINT_ARRAYS_H

