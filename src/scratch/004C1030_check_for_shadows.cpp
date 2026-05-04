// tried the direct list-walk with exact draw_level/draw_list_num offsets; mismatch moved into the early branch layout
// tried the exact field offsets from the asm; VC5 still preferred a different prolog/branch family on the initial low-count checks
// tried decompiler-style `count<1 || draw_list==0`, ppRVar3/entry-pointer loop forms, and shared-fallback goto rewrites;
// all collapsed into worse basins (`mov si` / positive-branch-return-bool shapes, or split fallback returns).
// 2026-05-04 retry: focused manual rewrites plus an 8-variant lab narrowed the best basin to an int-guard + while(1) walker
// that matches the first 16 bytes through the second null-check, but VC5 still emits `jge + jmp` instead of the original `jl` loopback,
// and keeps the fallback/ret1 tail too near (`jle 26`, `je 1F`, `je 16`) instead of the original farther shared-tail layout.
// 2026-05-04 Boss reassignment recheck: tested direct-return nested/list-walk forms and targeted bottom-condition rewrites.
// Some variants recovered the bottom `jl` loopback, but only by regressing the early guard family (`mov ax/test ax` or very short fallback)
// or by moving the `movsx`/count compare into the wrong place; none beat the retained int-guard basin below.
// best current source is below; latest check_function is 31/72 positional diff, no custom flags kept.
// leaving in scratch after >10 total attempts because the remaining gap is branch/tail-layout drift, not a behavior mismatch.
class RGE_Sprite;

class RGE_Picture_List {
public:
    short picture_num;
    char gap_02[0x2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
};

class RGE_Sprite {
public:
    char gap_00[0x29];
    unsigned char draw_level;
    char gap_2A[0xC];
    short draw_list_num;
    RGE_Picture_List* draw_list;

    int check_for_shadows();
};

int RGE_Sprite::check_for_shadows() {
    short count;
    int limit;
    RGE_Picture_List* list;
    RGE_Sprite** sprite_ptr;
    int i;

    count = this->draw_list_num;
    if (count <= 0) {
        goto fallback;
    }
    list = this->draw_list;
    if (list == 0) {
        goto fallback;
    }
    limit = count;
    i = 0;
    if (limit <= 0) {
        goto ret0;
    }
    sprite_ptr = &list->sprite;

    while (1) {
        if ((*sprite_ptr)->draw_level == 0) {
            return 1;
        }
        i = i + 1;
        sprite_ptr = (RGE_Sprite**)((char*)sprite_ptr + 0x10);
        if (i >= count) {
            goto ret0;
        }
    }

fallback:
    if (this->draw_level != 0) {
        goto ret0;
    }
ret1:
    return 1;

ret0:
    return 0;
}
