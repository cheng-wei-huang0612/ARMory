#include <stdio.h>
#include <stdint.h>


#include "../utils/print_int_arrays.h"

extern void neon_cmeq(
    uint32_t *result,      
    const uint32_t *srcA,  
    const uint32_t *srcB  
);

int main(void){
    uint32_t A[4] = {1,-2,2,4};
    uint32_t B[4] = {1,2,3,5};
    uint32_t R[4] = {0};
    
    neon_cmeq(R, A, B);

    print_uint32x4(R);


    

}
