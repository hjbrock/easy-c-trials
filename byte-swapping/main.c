/*
 * Hannah Brock
 * 
 * Lab 2
 */

#include <stdio.h>
#include <assert.h>

#include "struct.h"
#include "funcs.h"

void s1_1();
void s1_2();
void s1_3();
void s1_4();
void s1_5();
void s2_1();
void s2_2();
void s2_3();
void s2_4();
void s2_5();
void s3_1();
void s3_2();
void s3_3();
void s3_4();
void s3_5();
void test_endian_swap_s1();
void test_s2();
void test_s3();

int main (void)
{
    test_endian_swap_s1();
    test_s2();
    test_s3();
    return 0;
}

/*
 * Tests endian_swap_s1_ code.
 */
void test_endian_swap_s1() {
    s1_1();
    s1_2();
    s1_3();
    s1_4();
    s1_5();
}

/*
 * Tests s2 code.
 */
void test_s2() {
    s2_1();
    s2_2();
    s2_3();
    s2_4();
    s2_5();
}

/*
 * Tests s3 code.
 */
void test_s3(){
    s3_1();
    s3_2();
    s3_3();
    s3_4();
    s3_5();
}

/*
 * Makes sure endian_swap_s1_ptr and endian_swap_s1_shift
 * return the same result
 */
void s1_1() {
    struct s1 s;
    struct s1 s_ptr;
    struct s1 s_shift;
    
    s.f0 = 0xABCDEFAB12345678ULL;
    s.f1 = 0xABCD1234;
    s.f2 = 0xBA;
    s.f3 = 0x0ABD1234;
    s.f4 = 0x12AB;
    s.f5 = 0x12345678;

    s_ptr = endian_swap_s1_ptr(s);
    s_shift = endian_swap_s1_shift(s);
   
    assert(s_shift.f0 == s_ptr.f0);
    assert(s_shift.f1 == s_ptr.f1);
    assert(s_shift.f2 == s_ptr.f2);
    assert(s_shift.f3 == s_ptr.f3);
    assert(s_shift.f4 == s_ptr.f4);
    assert(s_shift.f5 == s_ptr.f5);
}

/*
 * Make sure endian_swap_s1_shift is its own inverse
 */
void s1_2(){
    struct s1 s;
    struct s1 s_shift;
    
    s.f0 = 0xABCDEFAB12345678ULL;
    s.f1 = 0xABCD1234;
    s.f2 = 0xBA;
    s.f3 = 0x0ABD1234;
    s.f4 = 0x12AB;
    s.f5 = 0x12345678;

    s_shift = endian_swap_s1_shift(s);
    s_shift = endian_swap_s1_shift(s_shift);
    assert(s_shift.f0 == s.f0);
    assert(s_shift.f1 == s.f1);
    assert(s_shift.f2 == s.f2);
    assert(s_shift.f3 == s.f3);
    assert(s_shift.f4 == s.f4);
    assert(s_shift.f5 == s.f5);
}

/*
 * Make sure endian_swap_s1_ptr is its own inverse
 */
void s1_3(){
    struct s1 s;
    struct s1 s_ptr;
    
    s.f0 = 0xABCDEFAB12345678ULL;
    s.f1 = 0xABCD1234;
    s.f2 = 0xBA;
    s.f3 = 0x0ABD1234;
    s.f4 = 0x12AB;
    s.f5 = 0x12345678;

    s_ptr = endian_swap_s1_ptr(s);
    s_ptr = endian_swap_s1_ptr(s_ptr);

    assert(s_ptr.f0 == s.f0);
    assert(s_ptr.f1 == s.f1);
    assert(s_ptr.f2 == s.f2);
    assert(s_ptr.f3 == s.f3);
    assert(s_ptr.f4 == s.f4);
    assert(s_ptr.f5 == s.f5);
}

/*
 * Make sure endian_swap_s1_ptr is endian_swap_s1_shift's inverse
 */
void s1_4(){
    struct s1 s;
    struct s1 s_ptr;
    struct s1 s_shift;
    
    s.f0 = 0xABCDEFAB12345678ULL;
    s.f1 = 0xABCD1234;
    s.f2 = 0xBA;
    s.f3 = 0x0ABD1234;
    s.f4 = 0x12AB;
    s.f5 = 0x12345678;

    s_shift = endian_swap_s1_shift(s);
    s_ptr = endian_swap_s1_ptr(s_shift);
    
    assert(s.f0 == s_ptr.f0);
    assert(s.f1 == s_ptr.f1);
    assert(s.f2 == s_ptr.f2);
    assert(s.f3 == s_ptr.f3);
    assert(s.f4 == s_ptr.f4);
    assert(s.f5 == s_ptr.f5);
}

/*
 * Make sure endian_swap_s1_shift is endian_swap_s1_ptr's inverse
 */
void s1_5(){
    struct s1 s;
    struct s1 s_ptr;
    struct s1 s_shift;
    
    s.f0 = 0xABCDEFAB12345678ULL;
    s.f1 = 0xABCD1234;
    s.f2 = 0xBA;
    s.f3 = 0x0ABD1234;
    s.f4 = 0x12AB;
    s.f5 = 0x12345678;

    s_ptr = endian_swap_s1_ptr(s);
    s_shift = endian_swap_s1_shift(s_ptr);
    
    assert(s_shift.f0 == s.f0);
    assert(s_shift.f1 == s.f1);
    assert(s_shift.f2 == s.f2);
    assert(s_shift.f3 == s.f3);
    assert(s_shift.f4 == s.f4);
    assert(s_shift.f5 == s.f5);
}

/*
 * Make sure packing and unpacking an s2 results in the same struct
 */
void s2_1(){
    struct s2 s = {0x1234ABCDU, 0x1234, 0xABCD, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2_packed s_packed;
    struct s2 s_unpacked;

    char * ptr_to_packed = (char *) &s_packed;
    char * ptr_to_orig = (char *) &s;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    pack_s2(ptr_to_packed, ptr_to_orig);
    unpack_S2(ptr_to_unpacked, ptr_to_packed);

    assert(s_unpacked.f0 == s.f0);
    assert(s_unpacked.f1 == s.f1);
    assert(s_unpacked.f2 == s.f2);
    assert(s_unpacked.f3 == s.f3);
    assert(s_unpacked.f4 == s.f4);
    assert(s_unpacked.f5 == s.f5);
}

/*
 * Make sure unpacking and packing an s2_packed results in the same struct
 */
void s2_2(){
    struct s2_packed s = {0x1234ABCDU, 0x1234, 0xABCD, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2_packed s_packed;
    struct s2 s_unpacked;

    char * ptr_to_packed = (char *) &s_packed;
    char * ptr_to_orig = (char *) &s;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    unpack_S2(ptr_to_unpacked, ptr_to_orig);
    pack_s2(ptr_to_packed, ptr_to_unpacked);

    assert(s_packed.f0 == s.f0);
    assert(s_packed.f1 == s.f1);
    assert(s_packed.f2 == s.f2);
    assert(s_packed.f3 == s.f3);
    assert(s_packed.f4 == s.f4);
    assert(s_packed.f5 == s.f5);
}

/*
 * Make sure packing an s2 results in the same struct as an s2_packed
 * with the same values
 */
void s2_3(){
    struct s2_packed s = {0x1234ABCDU, 0x1234, 0xABCD, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2 s_unpacked = {0x1234ABCDU, 0x1234, 0xABCD, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2_packed s_packed;

    char * ptr_to_packed = (char *) &s_packed;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    pack_s2(ptr_to_packed, ptr_to_unpacked);

    assert(s_packed.f0 == s.f0);
    assert(s_packed.f1 == s.f1);
    assert(s_packed.f2 == s.f2);
    assert(s_packed.f3 == s.f3);
    assert(s_packed.f4 == s.f4);
    assert(s_packed.f5 == s.f5);
}

/*
 * Make sure unpacking an s2_packed results in the same struct as an s2
 * with the same values
 */
void s2_4(){
    struct s2_packed s_packed = {0x1234ABCDU, 0x1234, 0xABCD, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2 s = {0x1234ABCDU, 0x1234, 0xABCD, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2 s_unpacked;

    char * ptr_to_packed = (char *) &s_packed;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    unpack_S2(ptr_to_unpacked, ptr_to_packed);

    assert(s_unpacked.f0 == s.f0);
    assert(s_unpacked.f1 == s.f1);
    assert(s_unpacked.f2 == s.f2);
    assert(s_unpacked.f3 == s.f3);
    assert(s_unpacked.f4 == s.f4);
    assert(s_unpacked.f5 == s.f5);
}

/*
 * Make sure packing or unpacking leaves the same values
 */
void s2_5(){
    struct s2_packed s_packed = {0x1234AB00U, 0x0034, 0x0000, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2 s = {0x1234AB00U, 0x0034, 0x0000, 0x12345678, 0x0001, 0xABCDEF1234567890LL};
    struct s2 s_unpacked;
    struct s2_packed s_new_packed;

    char * ptr_to_orig_unpacked = (char *) &s;
    char * ptr_to_orig_packed = (char *) &s_packed;
    char * ptr_to_packed = (char *) &s_new_packed;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    unpack_S2(ptr_to_unpacked, ptr_to_orig_packed);
    pack_s2(ptr_to_packed, ptr_to_orig_unpacked);

    assert(s_new_packed.f0 == s.f0);
    assert(s_new_packed.f1 == s.f1);
    assert(s_new_packed.f2 == s.f2);
    assert(s_new_packed.f3 == s.f3);
    assert(s_new_packed.f4 == s.f4);
    assert(s_new_packed.f5 == s.f5);

    assert(s_packed.f0 == s_unpacked.f0);
    assert(s_packed.f1 == s_unpacked.f1);
    assert(s_packed.f2 == s_unpacked.f2);
    assert(s_packed.f3 == s_unpacked.f3);
    assert(s_packed.f4 == s_unpacked.f4);
    assert(s_packed.f5 == s_unpacked.f5);
}

/*
 * Make sure packing an s3 results in a correct s3_bitfield.
 * Use values that fit in the bitfields
 */
void s3_1(){
    struct s3 s = {0x1234, 'a', -1, 0x0001456789ABCDEULL, 0x00000003U, 0x1};
    struct s3_bitfield s_bit = {0x1234, 'a', -1, 0x0001456789ABCDEULL, 0x00000003U, 0x1};
    struct s3_bitfield s_packed;

    char * ptr_to_orig = (char *) &s;
    char * ptr_to_packed = (char *) &s_packed;

    int result = pack_s3(ptr_to_packed, ptr_to_orig);

    assert(result == 0);
    assert(s_bit.f0 == s_packed.f0);
    assert(s_bit.f1 == s_packed.f1);
    assert(s_bit.f2 == s_packed.f2);
    assert(s_bit.f3 == s_packed.f3);
    assert(s_bit.f4 == s_packed.f4);
    assert(s_bit.f5 == s_packed.f5);
}

/*
 * Make sure packing an s3 with fields that are too big gives -1.
 */
void s3_2(){
    struct s3 s = {0xFFFF, 0xFF, 0xFF, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFU, 0xFF};
    struct s3_bitfield s_packed;

    char * ptr_to_orig = (char *) &s;
    char * ptr_to_packed = (char *) &s_packed;

    int result = pack_s3(ptr_to_packed, ptr_to_orig);

    assert(result == -1);
}

/*
 * Make sure packing then unpacking gives same struct.
 */
void s3_3(){
    struct s3 s = {0x1234, 'a', -1, 0x0001456789ABCDEULL, 0x00000003U, 0x1};
    struct s3_bitfield s_packed;
    struct s3 s_unpacked;

    char * ptr_to_orig = (char *) &s;
    char * ptr_to_packed = (char *) &s_packed;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    int result = pack_s3(ptr_to_packed, ptr_to_orig);
    unpack_s3(ptr_to_unpacked, ptr_to_packed);

    assert(result == 0);
    assert(s.f0 == s_unpacked.f0);
    assert(s.f1 == s_unpacked.f1);
    assert(s.f2 == s_unpacked.f2);
    assert(s.f3 == s_unpacked.f3);
    assert(s.f4 == s_unpacked.f4);
    assert(s.f5 == s_unpacked.f5);
}

/*
 * Make sure unpacking then packing gives same struct
 */
void s3_4(){
    struct s3_bitfield s = {0x1234, 'a', -1, 0x0001456789ABCDEULL, 0x00000003U, 0x1};
    struct s3_bitfield s_packed;
    struct s3 s_unpacked;

    char * ptr_to_orig = (char *) &s;
    char * ptr_to_packed = (char *) &s_packed;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    unpack_s3(ptr_to_unpacked, ptr_to_orig);
    int result = pack_s3(ptr_to_packed, ptr_to_unpacked);

    assert(result == 0);
    assert(s.f0 == s_packed.f0);
    assert(s.f1 == s_packed.f1);
    assert(s.f2 == s_packed.f2);
    assert(s.f3 == s_packed.f3);
    assert(s.f4 == s_packed.f4);
    assert(s.f5 == s_packed.f5);
}

/*
 * Make sure unpacking gives correct answers
 */
void s3_5(){
    struct s3_bitfield s = {0x1234, 'a', -1, 0x0001456789ABCDEULL, 0x00000003U, 0x1};
    struct s3 s_unpacked;

    char * ptr_to_orig = (char *) &s;
    char * ptr_to_unpacked = (char *) &s_unpacked;

    unpack_s3(ptr_to_unpacked, ptr_to_orig);

    assert(s.f0 == s_unpacked.f0);
    assert(s.f1 == s_unpacked.f1);
    assert(s.f2 == s_unpacked.f2);
    assert(s.f3 == s_unpacked.f3);
    assert(s.f4 == s_unpacked.f4);
    assert(s.f5 == s_unpacked.f5);
}
