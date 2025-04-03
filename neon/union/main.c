#include <stdio.h>
#include <stdint.h>
#include <arm_neon.h>


typedef union {
    uint8x16_t  u8;
    int8x16_t   s8;
    uint16x8_t  u16;
    int16x8_t   s16;
    uint32x4_t  u32;
    int32x4_t   s32;
    float32x4_t f32;
    uint64x2_t  u64;
} neon_reg_t;


void print_u64x2(neon_reg_t vec) {
    uint64_t values[2];
    vst1q_u64(values, vec.u64);  
    printf("[ %llu, %llu ]\n",
           values[0], values[1]);
}

void print_vec(neon_reg_t *data) {
    // 直接將 neon_reg_t 當作 byte array 存取
    uint8_t *bytes = (uint8_t*)data;

    // Neon 暫存器是 128 bits = 16 bytes
    for (int byte_idx = 0; byte_idx < 16; byte_idx++) {
        uint8_t current_byte = bytes[byte_idx];

        // 每個 byte 從 bit 0（LSB）到 bit 7（MSB）印出
        for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
            // 取出目前的 bit
            uint8_t bit = (current_byte >> bit_idx) & 1;

            // 印出來
            printf("%u", bit);
        }

        // 用空格隔開每個 byte，方便閱讀
        printf(" ");
    }
    printf("\n");
}


int main() {
    printf("hello\n");

    neon_reg_t data;
    data.u32 = (uint32x4_t){1,0,2,0};

    print_u64x2(data);
    // [ 1, 2 ]

    data.u32 = (uint32x4_t){0,1,0,2};

    print_u64x2(data);
    // [ 4294967296, 4294967296x2 ] = [ 1 << 32, 1 << 32 ]
    print_vec(&data);

    data.u8 = (uint8x16_t){0xAA, 0x55, 0xAA, 0x55,
        0xAA, 0x55, 0xAA, 0x55,
        0xAA, 0x55, 0xAA, 0x55,
        0xAA, 0x55, 0xAA, 0x55};

    print_vec(&data);


}