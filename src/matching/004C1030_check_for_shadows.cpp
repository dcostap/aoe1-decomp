// exact basin: keep the int-guard prelude, then use a `while (1)` walker whose bottom test is
// spelled as `if (i < count) continue; return 0;` and route the hit path through `goto ret1`.
// That preserves the original early dx/esi guard family while also recovering the `jl` loopback
// and the farther shared fallback/ret1 tail.

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
    if (count <= 0) goto fallback;
    list = this->draw_list;
    if (list == 0) goto fallback;
    limit = count;
    i = 0;
    if (limit <= 0) goto ret0;
    sprite_ptr = &list->sprite;

    while (1) {
        if ((*sprite_ptr)->draw_level == 0) goto ret1;
        i = i + 1;
        sprite_ptr = (RGE_Sprite**)((char*)sprite_ptr + 0x10);
        if (i < count) continue;
        return 0;
    }

fallback:
    if (this->draw_level == 0) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
