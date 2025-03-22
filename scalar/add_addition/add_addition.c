#include<stdio.h>
#include<stdint.h>

extern void asm_add(int64_t *r, int64_t *a, int64_t *b);

int main(void){
    printf("This program introduces add instruction.\n\n");
    printf("The instruction \n \n"
           "add xa, xb, xc\n\n"
           "will add the values in xb and xc (modulo 2**64) and store the result in the register xa");


    printf("\n\n");
    printf("We will run the following script ('asm_add.S')");
    printf(".align 4\n"
           ".global _asm_add\n"
           ".global asm_add\n"
           "_asm_add:\n"
           "asm_add:\n"
           "\n"
           "# qhasm: a = mem64[pointerA]\n"
           "# asm 1: ldr >a=int64#1,[<pointerA=int64#1]\n"
           "# asm 2: ldr >a=x0,[<pointerA=x0]\n"
           "ldr x0,[x0]\n"
           "\n"
           "# qhasm: b = mem64[pointerB]\n"
           "# asm 1: ldr >b=int64#2,[<pointerB=int64#2]\n"
           "# asm 2: ldr >b=x1,[<pointerB=x1]\n"
           "ldr x1,[x1]\n"
           "\n"
           "# qhasm: r = a + b \n"
           "# asm 1: add >r=int64#1,<a=int64#1,<b=int64#2\n"
           "# asm 2: add >r=x0,<a=x0,<b=x1\n"
           "add x0,x0,x1 \n");


    int64_t a = 13; 
    int64_t b = -12;
    int64_t r; 

    asm_add(&r, &a, &b);

    printf("\na = %lld\n",a);
    printf("b = %lld\n",b);
    printf("r = %lld\n",r);
   

}
