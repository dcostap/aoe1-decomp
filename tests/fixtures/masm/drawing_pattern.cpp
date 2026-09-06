#include <stdio.h>
#include <string.h>
#include "../../../include/asm_draw.h"

extern "C" void __cdecl probe_codelet(void*, void**, unsigned char*, unsigned char*, unsigned long, unsigned long);

static const unsigned long colors[8] = {
    0, 0xFFFFFFFF, 0xABCD1234, 0x01234567,
    0x89ABCDEF, 0xFF00FF00, 0x00FF00FF, 0x80301001
};

static void short_pixels(unsigned char*& dest, unsigned long color, unsigned long count, int odd)
{
    for (unsigned long i=0; i<count; ++i)
        *dest++=(unsigned char)(color >> (((i+odd)&1)*8));
}

static void expected_fill(unsigned char* dest, unsigned long color, unsigned long count, int align)
{
    if (count<4) {
        short_pixels(dest, color, count, align&1);
        return;
    }
    unsigned long head = align ? 4-align : 0;
    if (count<8 && head==0) head=4;
    if (head==4) { memcpy(dest, &color, 4); dest+=4; }
    else short_pixels(dest, color, head, align&1);
    count-=head;
    while (count>=4) {
        memcpy(dest, &color, 4);
        dest+=4;
        count-=4;
    }
    short_pixels(dest, color, count, 0);
}

int main()
{
    unsigned char actual[2048], expected[2048];
    unsigned char* getter=(unsigned char*)ASMGet_Color_Xform;
    if (*getter!=0xA1) return 90;
    unsigned char* color_slot=(unsigned char*)*(unsigned long*)(getter+1);
    void** resume=(void**)(color_slot+TEST_RESUME_FROM_COLOR);
    void** table=(void**)((unsigned char*)ASMDraw_HLine+TEST_PATTERN_FROM_HLINE);
    unsigned long cases=0;
    for (unsigned long count=0; count<=512; ++count) {
        for (unsigned long variant=0; variant<8; ++variant) {
            for (unsigned long align=0; align<4; ++align) {
                unsigned long color=colors[variant];
                memset(actual, 0xCD, sizeof(actual));
                memcpy(expected, actual, sizeof(actual));
                unsigned char* dest=actual+16+align;
                unsigned long parity=(unsigned long)dest&3;
                expected_fill(expected+16+align, color, count, parity);
                unsigned long group=count<8 ? count : 8+(count&3);
                void* saved=*resume;
                // These are fill blocks. A null source must remain unused.
                probe_codelet(table[group*4+parity], resume, 0, dest, count, color);
                *resume=saved;
                if (memcmp(actual, expected, sizeof(actual))) {
                    printf("Pattern fill failed: count %lu, align %lu, color %08lX\n", count, parity, color);
                    return 1;
                }
                ++cases;
            }
        }
    }
    printf("Pattern fill: PASS, %lu cases\n", cases);
    return cases==16416 ? 0 : 2;
}
