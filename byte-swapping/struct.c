/*
 * Hannah Brock
 * 
 * Lab 2
 */

#include "struct.h"
#include "funcs.h"

/*
 * return a struct containing the same values as the argument struct
 * except that each field has its byte order reversed
 *
 * RESTRICTION: this function must not use arrays or pointers at all;
 * accomplish the byte swapping using shift operators
 */
struct s1 endian_swap_s1_shift (struct s1 s){
    // no packing, so swap the byte-order in each field on its own
    struct s1 new_s;
    // f0 - 8 bytes
    new_s.f0 = (s.f0 << 56)
               | ((s.f0 & 0xFF00) << 40)
               | ((s.f0 & 0xFF0000) << 24)
               | ((s.f0 & 0xFF000000) << 8)
               | ((s.f0 >> 8) & 0xFF000000)
               | ((s.f0 >> 24) & 0xFF0000)
               | ((s.f0 >> 40) & 0xFF00)
               | (s.f0 >> 56);
    // f1 - 4 bytes
    unsigned f1 = (unsigned) s.f1;
    new_s.f1 = (long) (f1 << 24 & 0xFF000000)
               | (f1 << 8 & 0x00FF0000)
               | (f1 >> 8 & 0x0000FF00)
               | (f1 >> 24 & 0x000000FF);
    // f2 - 1 byte, no swap
    new_s.f2 = s.f2;
    // f3 - 4 bytes
    unsigned f3 = (unsigned) s.f3;
    new_s.f3 = (int) (f3 << 24 & 0xFF000000)
               | (f3 << 8 & 0x00FF0000)
               | (f3 >> 8 & 0x0000FF00)
               | (f3 >> 24 & 0x000000FF);
    // f4 - 2 bytes
    unsigned f4 = (unsigned) s.f4;
    new_s.f4 = (short) (f4 << 8 & 0xFF00) | (f4 >> 8 & 0x00FF);
    // f5 - 4 bytes
    new_s.f5 = (s.f5 << 24 & 0xFF000000)
               | (s.f5 << 8 & 0x00FF0000)
               | (s.f5 >> 8 & 0x0000FF00)
               | (s.f5 >> 24 & 0x000000FF);

    return new_s;
}

/*
 * Swaps the bytes in an array. byte1 is the index of one byte
 * and byte2 is the index of the other byte to swap
 */
void swap_bytes_in_array (char * array, int byte1, int byte2){
    char temp;
    temp = array[byte1];
    array[byte1] = array[byte2];
    array[byte2] = temp;
}

/*
 * return a struct containing the same values as the argument struct
 * except that each field has its byte order reversed
 *
 * RESTRICTION: this function must not use shift operators;
 * accomplish the byte swapping using pointers and/or arrays
 */
struct s1 endian_swap_s1_ptr (struct s1 s){
    char * byte_array; // used to swap bytes
    int i;    
    struct s1 new_s = s;
    // f0 - 8 bytes
    byte_array = (char*) &new_s.f0;
    for(i=0;i<4;i++)
        swap_bytes_in_array(byte_array, i, 7-i);
    // f1 - 4 bytes
    byte_array = (char*) &new_s.f1;
    swap_bytes_in_array(byte_array,0,3);
    swap_bytes_in_array(byte_array,1,2);
    // f2 - 1 byte, no swap
    // f3 - 4 bytes
    byte_array = (char*) &new_s.f3;
    swap_bytes_in_array(byte_array,0,3);
    swap_bytes_in_array(byte_array,1,2); 
    // f4 - 2 bytes
    byte_array = (char*) &new_s.f4;
    swap_bytes_in_array(byte_array,0,1);
    // f5 - 4 bytes
    byte_array = (char*) &new_s.f5;
    swap_bytes_in_array(byte_array,0,3);
    swap_bytes_in_array(byte_array,1,2);
    return new_s;
}

/*
 * convert a standard (padded) struct into a packed struct containing
 * the same fields
 *
 * the first argument points to a struct s2_packed, the second
 * argument points to a struct s2
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
 *
 * RESTRICTION: all data movement must be through pointer/array
 * operations, no actual struct code is permitted
 */
void pack_s2 (char * s_packed, char * s){
    int i;
    // No padding until after the last short, so move all that data
    // from bytes [0-13]
    for(i=0;i<14;i++)
        s_packed[i] = s[i];
    // Now move the long long after the padding into s_packed (bytes [16-23]
    for(i=16;i<24;i++)
        s_packed[i-2] = s[i];
}

/*
 * convert a packed struct into a stanard (padded) struct containing
 * the same fields
 *
 * the first argument points to a struct s2, the second
 * argument points to a struct s2_packed
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
 *
 * RESTRICTION: all data movement must be through pointer/array
 * operations, no actual struct code is permitted
 */
void unpack_S2 (char * s, char * s_packed){
    int i;
    // No padding needed until after the last short, so move all the
    // data from bytes [0-13]
    for(i=0;i<14;i++)
        s[i] = s_packed[i];
    // Now, skip the two padding bytes and add the long long
    for(i=14;i<22;i++)
        s[i+2] = s_packed[i];
}

/*
 * Checks if any of the fields of a struct s3
 * are too wide to pack into an s3_bitfield.
 *
 * Returns -1 if any are too wide.
 * Returns 0 otherwise.
 */
int check_widths(char * s) {
    // check if f0 is too wide
    if (s[1] & 0xC0) {
        return -1;
    }
    // check if f2 is too wide
    if (!(s[3] & 0x80) && (s[3] & 0x7E)){
        return -1;
    }
    // check if f3 is too wide
    if (s[10] & 0xFE){
        return -1;
    }
    // check if f4 is too wide
    if ((s[12] & 0xFC) || s[13] || s[14] || s[15]){
        return -1;
    }
    // check if f5 is too wide
    if (s[16] & 0xC0){
        return -1;
    }
    return 0;
}

/*
 * convert a struct with full-width fields into a struct containing
 * bitfields
 *
 * the first argument points to a struct s3_bitfield, the second
 * argument points to a struct s3
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
 *
 * RETURN VALUE: if the value in any full-width field cannot be
 * represented in its corresponding bitfield, return -1; otherwise
 * return 0
 *
 * RESTRICTION: all data movement must be through pointer/array/shift
 * operations, no actual struct code is permitted
 */
int pack_s3 (char * s_bitfield, char * s){
    int i;
    // check the width of all of s's fields
    int width_check;
    width_check = check_widths(s);
    // pack the first part of f0
    s_bitfield[0] = s[0];
    s_bitfield[1] = s[1] & 0x3F;
    // pack f1
    s_bitfield[2] = s[2];
    // pack f2
    s_bitfield[3] = ((s[3] >> 6) & 0x2) | (s[3] & 0x01);
    // start packing f3
    for(i=4;i<10;i++)
        s_bitfield[i] = s[i];
    // pack last bit of f3
    s_bitfield[10] = s[10] & 0x01;
    // pack f4
    int s12 = (int) ((((unsigned) s[12]) << 1) & 0x6);
    s_bitfield[10] = s_bitfield[10] | s12;
    // pack f5
    s_bitfield[11] = s[16] & 0x3F;
    return width_check;
}

/*
 * convert a struct with bitfields into a struct containing
 * full-width fields
 *
 * the first argument points to a struct s3, the second
 * argument points to a struct s3_bitfield
 *
 * therefore, your job is to copy data referenced by the second
 * argument into space referenced by the first argument
 *
 * RESTRICTION: all data movement must be through pointer/array/shift
 * operations, no actual struct code is permitted
 */
void unpack_s3 (char * s, char * s_bitfield){
    int i;
    // get f0
    s[0] = s_bitfield[0];
    s[1] = s_bitfield[1];
    // get f1
    s[2] = s_bitfield[2];
    // get f2
    if (s_bitfield[3] & 0x2)
        s[3] = s_bitfield[3] | 0xFE;
    else
        s[3] = s_bitfield[3];
    // get f3
    for(i=4;i<10;i++)
        s[i] = s_bitfield[i];
    s[10] = s_bitfield[10] & 0x1;
    s[11] = 0x0;
    // get f4
    s[12] = (s_bitfield[10] & 0x6) >> 1;
    for(i=13;i<16;i++)
        s[i] = 0x0;
    // get f5
    s[16] = s_bitfield[11];
}
