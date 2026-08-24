#ifndef RGE_VIEW_SHARED_CONTEXT
struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec* next;
    Ov_Sprite_Draw_Rec* prev;
    char gap_08[0x18];
    int displayfunction;
};

void __cdecl operator_delete(void* block);

class RGE_View {
public:
    char gap_00[0x350];
    Ov_Sprite_Draw_Rec* extra_sprites;

    void reset_cyclic_overlay_sprites(void);
};
#endif

void RGE_View::reset_cyclic_overlay_sprites(void) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* next;

    sprite = extra_sprites;
    while (sprite != 0) {
        if (sprite->displayfunction == 1) {
            if (sprite->prev != 0) {
                sprite->prev->next = sprite->next;
            }
            if (sprite->next != 0) {
                sprite->next->prev = sprite->prev;
            }
            if (sprite->prev == 0) {
                extra_sprites = sprite->next;
            }
            next = sprite->next;
            operator_delete(sprite);
            sprite = next;
        } else {
            sprite = sprite->next;
        }
    }
}
