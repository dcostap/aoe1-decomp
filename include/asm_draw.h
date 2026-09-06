#ifndef AOE1_ASM_DRAW_H
#define AOE1_ASM_DRAW_H

#ifdef __cplusplus
extern "C" {
#endif

void __cdecl ASMSet_Shadowing(unsigned long mask1, unsigned long value1,
                              unsigned long mask2, unsigned long value2);
void __cdecl ASMSet_Surface_Info(void* offsets, void* heads, void* tails,
                                 long min_span, long min_line,
                                 long max_span, long max_line);
void __cdecl ASMSet_Color_Xform(int color);
int __cdecl ASMGet_Color_Xform(void);
void __cdecl ASMSet_Xlate_Table(void* table);
void __cdecl ASMDraw_HLine(long x1, long x2, long y, unsigned long color);
void __cdecl ASMDraw_Sprite(void* base, long x, long y, long width, long height,
                            long data_offsets, long outline_offset, int flags);

#ifdef __cplusplus
}
#endif

#endif
