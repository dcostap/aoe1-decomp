#ifndef RGE_VIEW_SHARED_CONTEXT
struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec* next;
};

void __cdecl operator_delete(void* block);

class RGE_View {
public:
    char gap_00[0x350];
    Ov_Sprite_Draw_Rec* extra_sprites;

    void reset_overlay_sprites(void);
};
#endif

void RGE_View::reset_overlay_sprites(void) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* next;

    sprite = extra_sprites;
    while (sprite != 0) {
        next = sprite->next;
        operator_delete(sprite);
        sprite = next;
    }
    extra_sprites = 0;
}
