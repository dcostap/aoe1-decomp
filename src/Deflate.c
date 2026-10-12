/* Deflate: the compressor from compress.lib (Deflate.obj), used for saved
   games and scenarios.

   The library predates the game and was built with an older compiler; the
   1997 PTRIBE build has instruction-identical code and its map supplies the
   function names. VC5 cannot reproduce its code generation, so this source is
   proved by behavior: tests/fixtures/compression_library/deflate_diff.c runs
   it against the original object and compares every output byte, return code,
   and the final state buffer. */

#include <string.h>

// clang-format off
static unsigned char bl_order[19] = {
    16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2,
    14, 1, 15
};

static unsigned short len_code[256] = {
    257, 258, 259, 260, 261, 262, 263, 264, 265, 265, 266, 266,
    267, 267, 268, 268, 269, 269, 269, 269, 270, 270, 270, 270,
    271, 271, 271, 271, 272, 272, 272, 272, 273, 273, 273, 273,
    273, 273, 273, 273, 274, 274, 274, 274, 274, 274, 274, 274,
    275, 275, 275, 275, 275, 275, 275, 275, 276, 276, 276, 276,
    276, 276, 276, 276, 277, 277, 277, 277, 277, 277, 277, 277,
    277, 277, 277, 277, 277, 277, 277, 277, 278, 278, 278, 278,
    278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278, 278,
    279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279, 279,
    279, 279, 279, 279, 280, 280, 280, 280, 280, 280, 280, 280,
    280, 280, 280, 280, 280, 280, 280, 280, 281, 281, 281, 281,
    281, 281, 281, 281, 281, 281, 281, 281, 281, 281, 281, 281,
    281, 281, 281, 281, 281, 281, 281, 281, 281, 281, 281, 281,
    281, 281, 281, 281, 282, 282, 282, 282, 282, 282, 282, 282,
    282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282,
    282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282, 282,
    283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283,
    283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283, 283,
    283, 283, 283, 283, 283, 283, 283, 283, 284, 284, 284, 284,
    284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284,
    284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284, 284,
    284, 284, 284, 285
};

static unsigned char len_extra[256] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0
};

static unsigned char len_mask[256] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00
};

static unsigned char dist_code_lo[512] = {
    0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
    8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9,
    10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17
};

static unsigned char dist_extra_lo[512] = {
    0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

static unsigned char dist_mask_lo[512] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f
};

static unsigned char dist_code_hi[128] = {
    0, 0, 18, 19, 20, 20, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23,
    24, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 25,
    26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
    27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
    29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
    29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29
};

static unsigned char dist_extra_hi[128] = {
    0, 0, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
    13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13
};

static unsigned short dist_mask_hi[128] = {
    0x0000, 0x0000, 0x00ff, 0x00ff, 0x01ff, 0x01ff, 0x01ff, 0x01ff, 0x03ff, 0x03ff, 0x03ff, 0x03ff,
    0x03ff, 0x03ff, 0x03ff, 0x03ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff,
    0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x07ff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x0fff,
    0x0fff, 0x0fff, 0x0fff, 0x0fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff,
    0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff,
    0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff,
    0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff,
    0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff,
    0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff, 0x1fff
};
// clang-format on

typedef struct deflate_state {
    unsigned char window[0x9102];
    unsigned short head[0x2000];
    unsigned short prev[0x8000];
    unsigned short next[0x8000];
    unsigned char items[0x9000];
    unsigned char* item_ptr;
    int item_count;
    unsigned long flags[0x180];
    unsigned long* flag_ptr;
    int flag_bits;
    unsigned int block_start;
    unsigned int next_block_start;
    int block_size;
    int lit_freq[0x120];
    int dist_freq[0x20];
    int bl_freq[0x13];
    int lit_len[0x120];
    int dist_len[0x20];
    int bl_len[0x13];
    int lit_code[0x120];
    int dist_code[0x20];
    int bl_code[0x13];
    int all_len[0x140];
    int rle[0x140];
    int* rle_end;
    int lit_count;
    int dist_count;
    unsigned long bitbuf;
    int bitcount;
    int counting;
    unsigned int bit_total;
    unsigned int strstart;
    int lookahead;
    unsigned int limit;
    int match_length;
    unsigned int match_pos;
    int max_chain;
    int block_mode;
    int lazy;
    int final;
    int wrapped;
    unsigned int insert_pos;
    unsigned int fill_pos;
    int fill_room;
    unsigned char* in_ptr;
    int in_left;
    unsigned char* in_start;
    int in_size;
    unsigned char* out_buf;
    int out_size;
    int (*write)(unsigned char* buffer, int length);
    unsigned char* out_ptr;
    int out_room;
    unsigned long signature;
} DEFLATE_STATE;

static int max_chain;
static int code_start[33];
static unsigned short* next;
static unsigned short* prev;
static int bitcount;
static int sorted_len[0x120];
static int sorted_sym[0x120];
static int sorted_count;
static int parent[0x120];
static DEFLATE_STATE* ds;
static int counting;
static int out_room;
static unsigned long bitbuf;
static unsigned char* out_ptr;
static unsigned char* window;
static int bl_count[33];
static int match_length;
static int heap[0x121];
static unsigned short* head;
static unsigned int match_pos;

static int deflate_main(void);
static void mem_copy(unsigned char* dst, unsigned char* src, int length);
static int flush_out_buffer(void);
static int flush_bits(void);
static int put_bits(int value, int length);
static void delete_data(unsigned int pos);
static void hash_data(unsigned int pos, unsigned int length);
static int flush_flag_buf(void);
static int code_token_buf(int last);
static int code_block(void);
static void init_static_block(void);
static void int_set(int* dst, int value, int count);
static void huff_sort_code_sizes(int count, int* lengths);
static void huff_make_codes(int count, int* lengths, int max_length, int* codes);
static int send_static_block(void);
static void init_dynamic_block(void);
static void huff_code_sizes(int count, int* freq, int* lengths);
static void huff_down_heap(int* heap, int* freq, int size, int k);
static void huff_fix_code_sizes(int max_length);
static void init_compress_code_sizes(void);
static void int_move(int* dst, int* src, int count);
static int* repeat_last(int* out, int length, int count);
static int* repeat_zero(int* out, int count);
static int send_dynamic_block(void);
static int compress_code_sizes(void);
static int send_raw_block(void);
static int dict_search_main(unsigned int pos);
static int dict_search(void);
static int dict_search_lazy(void);
static void find_match(unsigned int pos);
static int empty_flag_buf(void);
static int dict_search_greedy(void);
static int dict_search_flash(void);
static int dict_search_eof(void);
static int dict_fill(void);
static void mem_set(unsigned char* dst, unsigned char value, unsigned int count);
static void deflate_main_init(void);

#define PUT_BYTE(b) \
    while (--out_room < 0) { \
        out_room++; \
        if (flush_out_buffer()) \
            return 1; \
    } \
    *out_ptr++ = (unsigned char)(b)

#define OUTPUT_LITERAL() \
    *ds->item_ptr = window[ds->strstart]; \
    ds->strstart++; \
    ds->item_ptr++; \
    ds->lookahead--; \
    ds->block_size++; \
    *ds->flag_ptr <<= 1; \
    ds->flag_bits--; \
    if (ds->flag_bits == 0 && empty_flag_buf()) \
        return 1

int deflate_data(DEFLATE_STATE* state, unsigned char* input, int length, int last) {
    int result;

    ds = state;
    if (state == 0 || state->signature != 0x12345678)
        return 2;
    ds->in_start = input;
    ds->in_size = length;
    ds->in_ptr = ds->in_start;
    ds->in_left = ds->in_size;
    ds->final = last;
    window = ds->window;
    head = ds->head;
    prev = ds->prev;
    next = ds->next;
    max_chain = ds->max_chain;
    match_length = ds->match_length;
    match_pos = ds->match_pos;
    bitbuf = ds->bitbuf;
    bitcount = ds->bitcount;
    counting = ds->counting;
    out_ptr = ds->out_ptr;
    out_room = ds->out_room;
    result = deflate_main();
    ds->match_length = match_length;
    ds->match_pos = match_pos;
    ds->bitbuf = bitbuf;
    ds->bitcount = bitcount;
    ds->counting = counting;
    ds->out_ptr = out_ptr;
    ds->out_room = out_room;
    return result;
}

static int deflate_main(void) {
    for (;;) {
        if (dict_fill() && ds->final == 0)
            return 0;
        if (ds->wrapped != 0)
            delete_data(ds->insert_pos);
        hash_data(ds->insert_pos, ds->lookahead);
        if (ds->insert_pos == 0)
            mem_copy(ds->window + 0x8000, ds->window, 0x1102);
        if (dict_search_main(ds->insert_pos))
            return 1;
        ds->insert_pos += 0x1000;
        if (ds->insert_pos == 0x8000) {
            ds->insert_pos = 0;
            ds->wrapped = 1;
        }
        if (ds->final != 0 && ds->in_left == 0)
            break;
        ds->lookahead = 0;
    }
    if (dict_search_eof())
        return 1;
    if (flush_flag_buf())
        return 1;
    if (flush_bits())
        return 1;
    if (flush_out_buffer())
        return 1;
    ds->signature = 0xABCD1234;
    return 1;
}

static void mem_copy(unsigned char* dst, unsigned char* src, int length) {
    unsigned int blocks;

    if (length >= 16) {
        blocks = (unsigned int) length >> 4;
        length -= blocks << 4;
        do {
            ((unsigned long*) dst)[0] = ((unsigned long*) src)[0];
            ((unsigned long*) dst)[1] = ((unsigned long*) src)[1];
            ((unsigned long*) dst)[2] = ((unsigned long*) src)[2];
            ((unsigned long*) dst)[3] = ((unsigned long*) src)[3];
            dst += 16;
            src += 16;
        } while (--blocks);
    }
    while (length) {
        *dst++ = *src++;
        length--;
    }
}

static int flush_out_buffer(void) {
    if (ds->write(ds->out_buf, ds->out_size - out_room))
        return 1;
    out_ptr = ds->out_buf;
    out_room = ds->out_size;
    return 0;
}

static int flush_bits(void) {
    if (put_bits(0, 7))
        return 1;
    bitcount = 0;
    return 0;
}

static int put_bits(int value, int length) {
    if (counting) {
        ds->bit_total += length;
        return 0;
    }
    bitbuf |= value << bitcount;
    bitcount += length;
    if (bitcount < 8)
        return 0;
    if (bitcount >= 16) {
        if ((out_room -= 2) >= 0) {
            *(unsigned short*) out_ptr = (unsigned short) bitbuf;
            out_ptr += 2;
            bitbuf >>= 16;
            bitcount -= 16;
            return 0;
        }
        out_room += 2;
        PUT_BYTE(bitbuf);
        PUT_BYTE(bitbuf >> 8);
        bitbuf >>= 16;
        bitcount -= 16;
        return 0;
    }
    if (--out_room >= 0) {
        *out_ptr++ = (unsigned char) bitbuf;
        bitbuf >>= 8;
        bitcount -= 8;
        return 0;
    }
    out_room++;
    PUT_BYTE(bitbuf);
    bitbuf >>= 8;
    bitcount -= 8;
    return 0;
}

static void delete_data(unsigned int pos) {
    unsigned int i;
    unsigned int link;

    for (i = pos; i < pos + 0x1000; i++) {
        link = next[i];
        if (link & 0x8000) {
            if (link != 0xFFFF)
                head[link & 0x7FFF] = 0xFFFF;
        } else {
            prev[link] = 0xFFFF;
        }
    }
}

static void hash_data(unsigned int pos, unsigned int length) {
    unsigned int i;
    unsigned int hash;
    int start;

    start = length - 2;
    if (start <= 0)
        start = 0;
    for (i = start; i < length; i++)
        prev[pos + i] = next[pos + i] = 0xFFFF;
    if ((int) length > 2) {
        hash = (window[pos] << 5) ^ window[pos + 1];
        for (i = pos; i < pos + length - 2; i++) {
            hash = ((hash & 0xFF) << 5) ^ window[i + 2];
            next[i] = (unsigned short) (hash | 0x8000);
            prev[i] = head[hash];
            if (prev[i] != 0xFFFF)
                next[prev[i]] = (unsigned short) i;
            head[hash] = (unsigned short) i;
        }
    }
}

static int flush_flag_buf(void) {
    if (ds->flag_bits != 32) {
        ds->item_count += 32 - ds->flag_bits;
        while (ds->flag_bits) {
            *ds->flag_ptr <<= 1;
            ds->flag_bits--;
        }
        ds->flag_ptr++;
        ds->flag_bits = 32;
    }
    return code_token_buf(1);
}

static int code_token_buf(int last) {
    unsigned int dynamic_bits;
    unsigned int stored_bits;
    unsigned int pad;

    ds->next_block_start = ds->strstart;
    if (ds->item_count != 0) {
        if (put_bits(0, 1))
            return 1;
        if (ds->block_mode == 0) {
            init_static_block();
            if (send_static_block())
                return 1;
            if (code_block())
                return 1;
        } else if (ds->block_mode == 1) {
            init_dynamic_block();
            if (send_dynamic_block())
                return 1;
            if (code_block())
                return 1;
        } else if (ds->item_count < 0x80) {
            counting = 1;
            ds->bit_total = 0;
            init_static_block();
            if (send_static_block())
                return 1;
            if (code_block())
                return 1;
            dynamic_bits = ds->bit_total;
            ds->bit_total = 0;
            init_dynamic_block();
            if (send_dynamic_block())
                return 1;
            if (code_block())
                return 1;
            counting = 0;
            stored_bits = ds->block_size * 8 + 34;
            pad = (bitcount + 2) & 7;
            if (pad)
                stored_bits = stored_bits - pad + 8;
            if (stored_bits < dynamic_bits && stored_bits < ds->bit_total) {
                if (send_raw_block())
                    return 1;
            } else if (dynamic_bits < ds->bit_total) {
                init_static_block();
                if (send_static_block())
                    return 1;
                if (code_block())
                    return 1;
            } else {
                if (send_dynamic_block())
                    return 1;
                if (code_block())
                    return 1;
            }
        } else if (ds->block_size < 0x3999) {
            counting = 1;
            ds->bit_total = 0;
            init_dynamic_block();
            if (send_dynamic_block())
                return 1;
            if (code_block())
                return 1;
            counting = 0;
            stored_bits = ds->block_size * 8 + 34;
            pad = (bitcount + 2) & 7;
            if (pad)
                stored_bits = stored_bits - pad + 8;
            if (stored_bits < ds->bit_total) {
                if (send_raw_block())
                    return 1;
            } else {
                if (send_dynamic_block())
                    return 1;
                if (code_block())
                    return 1;
            }
        } else {
            init_dynamic_block();
            if (send_dynamic_block())
                return 1;
            if (code_block())
                return 1;
        }
    }
    ds->flag_ptr = ds->flags;
    ds->flag_bits = 32;
    ds->item_ptr = ds->items;
    ds->item_count = 0;
    ds->block_size = 0;
    ds->block_start = ds->next_block_start;
    if (last) {
        if (put_bits(1, 1))
            return 1;
        init_static_block();
        if (send_static_block())
            return 1;
        if (code_block())
            return 1;
    }
    return 0;
}

static int code_block(void) {
    unsigned long* flag_ptr;
    unsigned long flags;
    unsigned char* item;
    int remaining;
    int bits;
    unsigned int length;
    unsigned int dist;
    unsigned int high;
    int code;

    bits = 0;
    flag_ptr = ds->flags;
    item = ds->items;
    remaining = ds->item_count;
    while (remaining > 0) {
        if (bits == 0) {
            bits = 32;
            flags = *flag_ptr++;
        }
        if (flags & 0x80000000) {
            length = *item;
            dist = *(unsigned short*) (item + 1);
            code = len_code[length];
            if (put_bits(ds->lit_code[code], ds->lit_len[code]))
                return 1;
            if (put_bits(len_mask[length] & length, len_extra[length]))
                return 1;
            if (dist - 1 < 0x200) {
                code = dist_code_lo[dist - 1];
                if (put_bits(ds->dist_code[code], ds->dist_len[code]))
                    return 1;
                if (put_bits(dist_mask_lo[dist - 1] & (dist - 1), dist_extra_lo[dist - 1]))
                    return 1;
            } else {
                high = (dist - 1) >> 8;
                code = dist_code_hi[high];
                if (put_bits(ds->dist_code[code], ds->dist_len[code]))
                    return 1;
                if (put_bits(dist_mask_hi[high] & (dist - 1), dist_extra_hi[high]))
                    return 1;
            }
            item += 3;
        } else {
            code = *item++;
            if (put_bits(ds->lit_code[code], ds->lit_len[code]))
                return 1;
        }
        flags <<= 1;
        bits--;
        remaining--;
    }
    return put_bits(ds->lit_code[256], ds->lit_len[256]) != 0;
}

static void init_static_block(void) {
    int_set(ds->lit_len, 8, 144);
    int_set(ds->lit_len + 144, 9, 112);
    int_set(ds->lit_len + 256, 7, 24);
    int_set(ds->lit_len + 280, 8, 8);
    huff_sort_code_sizes(0x120, ds->lit_len);
    huff_make_codes(0x120, ds->lit_len, 15, ds->lit_code);
    int_set(ds->dist_len, 5, 32);
    huff_sort_code_sizes(0x20, ds->dist_len);
    huff_make_codes(0x20, ds->dist_len, 15, ds->dist_code);
}

static void int_set(int* dst, int value, int count) {
    while (count) {
        *dst++ = value;
        count--;
    }
}

static void huff_sort_code_sizes(int count, int* lengths) {
    int i;
    int total;

    sorted_count = 0;
    int_set(bl_count, 0, 33);
    for (i = 0; i < count; i++)
        bl_count[lengths[i]]++;
    total = 0;
    for (i = 1; i < 33; i++) {
        code_start[i] = total;
        total += bl_count[i];
    }
    for (i = 0; i < count; i++) {
        if (lengths[i] != 0) {
            sorted_count++;
            sorted_sym[code_start[lengths[i]]++] = i;
        }
    }
}

static void huff_make_codes(int count, int* lengths, int max_length, int* codes) {
    int i;
    int j;
    int n;
    int code;
    unsigned int value;
    unsigned int reversed;

    if (sorted_count == 0)
        return;
    int_set(codes, 0, count);
    n = 0;
    for (i = 1; i <= max_length; i++) {
        if (bl_count[i] > 0) {
            int_set(sorted_len + n, i, bl_count[i]);
            n += bl_count[i];
        }
    }
    code = 0;
    code_start[1] = 0;
    for (i = 2; i <= max_length; i++) {
        code = (code + bl_count[i - 1]) * 2;
        code_start[i] = code;
    }
    for (i = 0; i < sorted_count; i++)
        lengths[sorted_sym[i]] = sorted_len[i];
    for (i = 0; i < count; i++) {
        if (lengths[i] != 0) {
            value = code_start[lengths[i]]++;
            reversed = 0;
            for (j = lengths[i]; j > 0; j--) {
                reversed = (reversed << 1) | (value & 1);
                value >>= 1;
            }
            codes[i] = reversed;
        }
    }
}

static int send_static_block(void) {
    return put_bits(1, 2) != 0;
}

static void init_dynamic_block(void) {
    unsigned long* flag_ptr;
    unsigned long flags;
    unsigned char* item;
    int bits;
    int remaining;
    unsigned int length;

    item = ds->items;
    bits = 0;
    flag_ptr = ds->flags;
    int_set(ds->lit_freq, 0, 0x120);
    int_set(ds->dist_freq, 0, 0x20);
    remaining = ds->item_count;
    while (remaining > 0) {
        if (bits == 0) {
            flags = *flag_ptr++;
            bits = 32;
        }
        if (flags & 0x80000000) {
            length = *(unsigned short*) (item + 1);
            ds->lit_freq[len_code[*item]]++;
            if (length - 1 < 0x200) {
                item += 3;
                ds->dist_freq[dist_code_lo[length - 1]]++;
            } else {
                item += 3;
                ds->dist_freq[dist_code_hi[(length - 1) >> 8]]++;
            }
        } else {
            ds->lit_freq[*item++]++;
        }
        flags <<= 1;
        bits--;
        remaining--;
    }
    ds->lit_freq[256]++;
    huff_code_sizes(0x120, ds->lit_freq, ds->lit_len);
    huff_sort_code_sizes(0x120, ds->lit_len);
    huff_fix_code_sizes(15);
    huff_make_codes(0x120, ds->lit_len, 15, ds->lit_code);
    huff_code_sizes(0x20, ds->dist_freq, ds->dist_len);
    huff_sort_code_sizes(0x20, ds->dist_len);
    huff_fix_code_sizes(15);
    huff_make_codes(0x20, ds->dist_len, 15, ds->dist_code);
    init_compress_code_sizes();
}

static void huff_code_sizes(int count, int* freq, int* lengths) {
    int i;
    int size;
    int least;
    int node;
    int* entry;

    if (count > 0) {
        int_set(parent, -1, count);
        int_set(lengths, 0, count);
    }
    size = 1;
    for (i = 0; i < count; i++) {
        if (freq[i] != 0)
            heap[size++] = i;
    }
    size--;
    if (size < 2) {
        if (size != 0)
            lengths[heap[1]] = 1;
        return;
    }
    for (i = size / 2; i > 0; i--)
        huff_down_heap(heap, freq, size, i);
    do {
        least = heap[1];
        heap[1] = heap[size];
        size--;
        huff_down_heap(heap, freq, size, 1);
        node = heap[1];
        freq[node] += freq[least];
        huff_down_heap(heap, freq, size, 1);
        do {
            lengths[node]++;
            entry = &parent[node];
            node = *entry;
        } while (node != -1);
        *entry = least;
        do {
            lengths[least]++;
            least = parent[least];
        } while (least != -1);
    } while (size != 1);
}

static void huff_down_heap(int* heap, int* freq, int size, int k) {
    int v;
    int j;

    v = heap[k];
    j = k * 2;
    while (j <= size) {
        if (j < size
            && (freq[heap[j + 1]] < freq[heap[j]] || (freq[heap[j + 1]] == freq[heap[j]] && heap[j + 1] > heap[j])))
            j++;
        if (freq[v] < freq[heap[j]] || (freq[heap[j]] == freq[v] && heap[j] < v))
            break;
        heap[k] = heap[j];
        k = j;
        j *= 2;
    }
    heap[k] = v;
}

static void huff_fix_code_sizes(int max_length) {
    int i;
    int total;
    int* count;

    if (sorted_count < 2)
        return;
    for (count = &bl_count[max_length + 1]; count < &bl_count[33]; count++)
        bl_count[max_length] += *count;
    total = 0;
    for (i = max_length; i > 0; i--)
        total += bl_count[i] << (max_length - i);
    if (total == 1 << max_length)
        return;
    total -= 1 << max_length;
    do {
        bl_count[max_length]--;
        for (i = max_length - 1; i > 0; i--) {
            if (bl_count[i] != 0) {
                bl_count[i]--;
                bl_count[i + 1] += 2;
                break;
            }
        }
    } while (--total);
}

static void init_compress_code_sizes(void) {
    int* in;
    int* out;
    int remaining;
    int length;
    int previous;
    int zeros;
    int repeats;

    previous = 0xFF;
    zeros = 0;
    repeats = 0;
    int_set(ds->bl_freq, 0, 0x13);
    for (ds->lit_count = 0x11D; ds->lit_count >= 0; ds->lit_count--) {
        if (ds->lit_len[ds->lit_count] != 0)
            break;
    }
    ds->lit_count++;
    if (ds->lit_count < 0x102)
        ds->lit_count = 0x101;
    for (ds->dist_count = 0x1D; ds->dist_count >= 0; ds->dist_count--) {
        if (ds->dist_len[ds->dist_count] != 0)
            break;
    }
    ds->dist_count++;
    if (ds->dist_count < 2)
        ds->dist_count = 1;
    int_move(ds->all_len, ds->lit_len, ds->lit_count);
    int_move(ds->all_len + ds->lit_count, ds->dist_len, ds->dist_count);
    out = ds->rle;
    in = ds->all_len;
    for (remaining = ds->lit_count + ds->dist_count; remaining > 0; remaining--) {
        length = *in;
        if (length == 0) {
            if (repeats != 0) {
                out = repeat_last(out, previous, repeats);
                repeats = 0;
            }
            if (++zeros == 0x8A) {
                out = repeat_zero(out, 0x8A);
                zeros = 0;
            }
        } else {
            if (zeros != 0) {
                out = repeat_zero(out, zeros);
                zeros = 0;
            }
            if (previous == length) {
                if (++repeats == 6) {
                    out = repeat_last(out, previous, 6);
                    repeats = 0;
                }
            } else {
                if (repeats != 0) {
                    out = repeat_last(out, previous, repeats);
                    repeats = 0;
                }
                ds->bl_freq[length]++;
                *out++ = length;
            }
        }
        previous = length;
        in++;
    }
    if (repeats != 0)
        out = repeat_last(out, length, repeats);
    else if (zeros != 0)
        out = repeat_zero(out, zeros);
    ds->rle_end = out;
    huff_code_sizes(0x13, ds->bl_freq, ds->bl_len);
    huff_sort_code_sizes(0x13, ds->bl_len);
    huff_fix_code_sizes(7);
    huff_make_codes(0x13, ds->bl_len, 7, ds->bl_code);
}

static void int_move(int* dst, int* src, int count) {
    while (count) {
        *dst++ = *src++;
        count--;
    }
}

static int* repeat_last(int* out, int length, int count) {
    if (count > 2) {
        ds->bl_freq[16]++;
        out[0] = 16;
        out[1] = count - 3;
        return out + 2;
    }
    ds->bl_freq[length] += count;
    while (count) {
        count--;
        *out++ = length;
    }
    return out;
}

static int* repeat_zero(int* out, int count) {
    if (count > 2) {
        if (count < 11) {
            ds->bl_freq[17]++;
            out[0] = 17;
            out[1] = count - 3;
            return out + 2;
        }
        ds->bl_freq[18]++;
        out[0] = 18;
        out[1] = count - 11;
        return out + 2;
    }
    ds->bl_freq[0] += count;
    while (count) {
        count--;
        *out++ = 0;
    }
    return out;
}

static int send_dynamic_block(void) {
    if (put_bits(2, 2))
        return 1;
    return compress_code_sizes() != 0;
}

static int compress_code_sizes(void) {
    int count;
    int i;
    int code;
    int* p;

    if (put_bits(ds->lit_count - 257, 5))
        return 1;
    if (put_bits(ds->dist_count - 1, 5))
        return 1;
    for (count = 18; count >= 0; count--) {
        if (ds->bl_len[bl_order[count]] != 0)
            break;
    }
    count++;
    if (count < 5)
        count = 4;
    if (put_bits(count - 4, 4))
        return 1;
    for (i = 0; i < count; i++) {
        if (put_bits(ds->bl_len[bl_order[i]], 3))
            return 1;
    }
    for (p = ds->rle; p < ds->rle_end;) {
        code = *p++;
        if (put_bits(ds->bl_code[code], ds->bl_len[code]))
            return 1;
        if (code == 16) {
            if (put_bits(*p++, 2))
                return 1;
        } else if (code == 17) {
            if (put_bits(*p++, 3))
                return 1;
        } else if (code == 18) {
            if (put_bits(*p++, 7))
                return 1;
        }
    }
    return 0;
}

static int send_raw_block(void) {
    unsigned int pos;
    int remaining;

    if (put_bits(0, 2))
        return 1;
    if (flush_bits())
        return 1;
    PUT_BYTE(ds->block_size);
    PUT_BYTE(ds->block_size >> 8);
    PUT_BYTE(~ds->block_size);
    PUT_BYTE(~ds->block_size >> 8);
    pos = ds->block_start;
    for (remaining = ds->block_size; remaining > 0; remaining--) {
        PUT_BYTE(window[pos]);
        pos = (pos + 1) & 0x7FFF;
    }
    return 0;
}

static int dict_search_main(unsigned int pos) {
    unsigned int added;

    added = (pos - ds->strstart) & 0x7FFF;
    ds->lookahead += added;
    ds->limit = ds->strstart + added + 0xEFD;
    return dict_search();
}

static int dict_search(void) {
    if (ds->lazy != 0) {
        if (max_chain > 3)
            return dict_search_greedy();
        return dict_search_flash();
    }
    return dict_search_lazy();
}

static int dict_search_lazy(void) {
    int length;
    unsigned int pos;
    int next_length;
    unsigned int next_pos;
    unsigned int dist;

    while (ds->lookahead != 0 && ds->strstart < ds->limit) {
        if (prev[ds->strstart & 0x7FFF] == 0xFFFF) {
            OUTPUT_LITERAL();
        } else {
            match_length = 2;
            find_match(ds->strstart);
            length = match_length;
            pos = match_pos;
            if (match_length == 2) {
                OUTPUT_LITERAL();
            } else {
                while (length < 0x80) {
                    next_pos = ds->strstart + 1;
                    if (prev[next_pos & 0x7FFF] == 0xFFFF)
                        break;
                    find_match(next_pos);
                    next_length = match_length;
                    if (ds->lookahead - 1 < match_length)
                        match_length = ds->lookahead - 1;
                    next_length = match_length;
                    if (match_length <= length)
                        break;
                    OUTPUT_LITERAL();
                    length = next_length;
                    pos = match_pos;
                }
                if (ds->lookahead < length && (length = ds->lookahead) < 3) {
                    OUTPUT_LITERAL();
                } else {
                    dist = (ds->strstart - pos) & 0x7FFF;
                    if (length == 3 && dist > 0x3FFF) {
                        OUTPUT_LITERAL();
                    } else {
                        *ds->item_ptr = (unsigned char) (length - 3);
                        ds->item_ptr++;
                        *(unsigned short*) ds->item_ptr = (unsigned short) dist;
                        ds->item_ptr += 2;
                        ds->strstart += length;
                        ds->lookahead -= length;
                        ds->block_size += length;
                        *ds->flag_ptr = (*ds->flag_ptr << 1) | 1;
                        ds->flag_bits--;
                        if (ds->flag_bits == 0 && empty_flag_buf())
                            return 1;
                    }
                }
            }
        }
    }
    ds->strstart &= 0x7FFF;
    return 0;
}

#define NEXT_CANDIDATE()     chain--;     candidate = prev[candidate];     if (candidate == 0xFFFF)         return;     if (*(unsigned short *)(end + candidate) == last)         goto compare

static void find_match(unsigned int pos) {
    unsigned short* scan;
    unsigned short* match;
    unsigned short* start;
    unsigned char* end;
    unsigned short last;
    unsigned int candidate;
    int chain;
    int words;
    int length;

    candidate = pos & 0x7FFF;
    start = (unsigned short*) (window + pos);
    last = *(unsigned short*) (window + pos + match_length - 1);
    end = window + match_length - 1;
    chain = max_chain;
    while (chain > 0) {
        /* The chain budget is checked once per four links. */
        NEXT_CANDIDATE();
        NEXT_CANDIDATE();
        NEXT_CANDIDATE();
        NEXT_CANDIDATE();
        continue;
    compare:
        if (*(unsigned short*) (window + candidate) != *start)
            continue;
        scan = start;
        match = (unsigned short*) (window + candidate);
        words = 32;
        do {
            if (*++match != *++scan)
                break;
            if (*++match != *++scan)
                break;
            if (*++match != *++scan)
                break;
            if (*++match != *++scan)
                break;
        } while (--words > 0);
        if (words == 0) {
            match_pos = candidate;
            match_length = 0x102;
            return;
        }
        length = (((unsigned char*) scan - (unsigned char*) start) & ~1)
                 + (*(unsigned char*) match == *(unsigned char*) scan);
        if (length > match_length) {
            last = *(unsigned short*) (window + pos + length - 1);
            end = window + length - 1;
            match_length = length;
            match_pos = candidate;
        }
    }
}

static int empty_flag_buf(void) {
    ds->flag_ptr++;
    ds->flag_bits = 32;
    ds->item_count += 32;
    if (ds->item_count == 0x3000)
        return code_token_buf(0);
    return 0;
}

static int dict_search_greedy(void) {
    unsigned int dist;

    while (ds->lookahead != 0 && ds->strstart < ds->limit) {
        if (prev[ds->strstart & 0x7FFF] == 0xFFFF) {
            OUTPUT_LITERAL();
        } else {
            match_length = 2;
            find_match(ds->strstart);
            if (match_length == 2) {
                OUTPUT_LITERAL();
            } else if (ds->lookahead < match_length && (match_length = ds->lookahead) < 3) {
                OUTPUT_LITERAL();
            } else {
                dist = (ds->strstart - match_pos) & 0x7FFF;
                if (match_length == 3 && dist > 0x3FFF) {
                    OUTPUT_LITERAL();
                } else {
                    *ds->item_ptr = (unsigned char) (match_length - 3);
                    ds->item_ptr++;
                    *(unsigned short*) ds->item_ptr = (unsigned short) dist;
                    ds->item_ptr += 2;
                    ds->strstart += match_length;
                    ds->lookahead -= match_length;
                    ds->block_size += match_length;
                    *ds->flag_ptr = (*ds->flag_ptr << 1) | 1;
                    ds->flag_bits--;
                    if (ds->flag_bits == 0 && empty_flag_buf())
                        return 1;
                }
            }
        }
    }
    ds->strstart &= 0x7FFF;
    return 0;
}

static int dict_search_flash(void) {
    unsigned short* scan;
    unsigned short* match;
    unsigned short first;
    unsigned int dist;

    while (ds->lookahead != 0 && ds->strstart < ds->limit) {
        match_pos = prev[ds->strstart & 0x7FFF];
        if (match_pos == 0xFFFF) {
            OUTPUT_LITERAL();
        } else {
            first = *(unsigned short*) (window + ds->strstart);
            if (*(unsigned short*) (window + match_pos) == first) {
                scan = (unsigned short*) (window + ds->strstart);
                match = (unsigned short*) (window + match_pos);
                match_length = 32;
                do {
                    if (*++scan != *++match)
                        break;
                    if (*++scan != *++match)
                        break;
                    if (*++scan != *++match)
                        break;
                    if (*++scan != *++match)
                        break;
                } while (--match_length > 0);
                if (match_length == 0)
                    match_length = 0x102;
                else
                    match_length = (((unsigned char*) match - window - match_pos) & ~1)
                                   + (*(unsigned char*) scan == *(unsigned char*) match);
                if (ds->lookahead < match_length && (match_length = ds->lookahead) < 3) {
                    OUTPUT_LITERAL();
                } else {
                    dist = (ds->strstart - match_pos) & 0x7FFF;
                    if (match_length == 3 && dist > 0x3FFF) {
                        OUTPUT_LITERAL();
                    } else {
                        *ds->item_ptr = (unsigned char) (match_length - 3);
                        ds->item_ptr++;
                        *(unsigned short*) ds->item_ptr = (unsigned short) dist;
                        ds->item_ptr += 2;
                        ds->strstart += match_length;
                        ds->lookahead -= match_length;
                        ds->block_size += match_length;
                        *ds->flag_ptr = (*ds->flag_ptr << 1) | 1;
                        ds->flag_bits--;
                        if (ds->flag_bits == 0 && empty_flag_buf())
                            return 1;
                    }
                }
            } else {
                *ds->item_ptr = (unsigned char) first;
                ds->strstart++;
                ds->item_ptr++;
                ds->lookahead--;
                ds->block_size++;
                *ds->flag_ptr <<= 1;
                ds->flag_bits--;
                if (ds->flag_bits == 0 && empty_flag_buf())
                    return 1;
            }
        }
    }
    ds->strstart &= 0x7FFF;
    return 0;
}

static int dict_search_eof(void) {
    ds->limit = 0xFFFF;
    return dict_search();
}

static int dict_fill(void) {
    int length;

    length = ds->in_left;
    if (ds->fill_room <= ds->in_left)
        length = ds->fill_room;
    mem_copy(window + ds->fill_pos, ds->in_ptr, length);
    ds->in_ptr += length;
    ds->in_left -= length;
    ds->fill_pos = (ds->fill_pos + length) & 0x7FFF;
    ds->fill_room -= length;
    ds->lookahead += length;
    if (ds->fill_room != 0) {
        if (ds->final != 0)
            mem_set(window + ds->fill_pos, 0, ds->fill_room);
        return 1;
    }
    ds->fill_room = 0x1000;
    return 0;
}

static void mem_set(unsigned char* dst, unsigned char value, unsigned int count) {
    if (count)
        memset(dst, value, count);
}

void deflate_deinit(DEFLATE_STATE* state) {
    ds = state;
    state->signature = 0xABCD1234;
}

int deflate_init(
    DEFLATE_STATE* state, int level, int block_mode, int lazy, unsigned char* output, int output_size,
    int (*write)(unsigned char* buffer, int length)
) {
    ds = state;
    if (level <= 1)
        level = 1;
    if (level >= 1500)
        level = 1500;
    state->max_chain = level;
    ds->block_mode = block_mode;
    ds->lazy = lazy;
    ds->out_buf = output;
    ds->out_size = output_size;
    ds->out_ptr = ds->out_buf;
    ds->out_room = ds->out_size;
    ds->write = write;
    ds->fill_room = 0x1000;
    deflate_main_init();
    ds->signature = 0x12345678;
    return 0;
}

static void deflate_main_init(void) {
    int i;

    for (i = 0; i < 0x8000; i++) {
        ds->next[i] = 0xFFFF;
        ds->prev[i] = 0xFFFF;
    }
    for (i = 0; i < 0x2000; i++)
        ds->head[i] = 0xFFFF;
    ds->flag_ptr = ds->flags;
    ds->flag_bits = 32;
    ds->item_ptr = ds->items;
}

int deflate_buf_size(void) {
    return sizeof(DEFLATE_STATE);
}
