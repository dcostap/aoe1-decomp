class TShape;

struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec* next;
    Ov_Sprite_Draw_Rec* prev;
    TShape* theShape;
    int thefacet;
    int world_x;
    int world_y;
    int flags;
    int drawLevel;
    int displayfunction;
    unsigned long LastDrawTime;
    unsigned long DrawTimeInterval;
    unsigned char* colortable;
};

void* __cdecl operator_new(unsigned int size);

class RGE_View {
public:
    char gap_00[0x350];
    Ov_Sprite_Draw_Rec* extra_sprites;

    void add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y, int flags, int draw_level, unsigned char* color_table, int displayfunction, unsigned long draw_time_interval);
};

void RGE_View::add_overlay_sprite(TShape* shape, int facet, int world_x, int world_y, int flags, int draw_level, unsigned char* color_table, int displayfunction, unsigned long draw_time_interval) {
    Ov_Sprite_Draw_Rec* sprite;
    Ov_Sprite_Draw_Rec* head;

    sprite = (Ov_Sprite_Draw_Rec*)operator_new(0x30);
    if (sprite != 0) {
        head = extra_sprites;
        sprite->prev = 0;
        sprite->next = head;
        if (head != 0) {
            head->prev = sprite;
        }
        extra_sprites = sprite;
        sprite->theShape = shape;
        sprite->thefacet = facet;
        sprite->world_x = world_x;
        sprite->world_y = world_y;
        sprite->flags = flags;
        sprite->drawLevel = draw_level;
        sprite->colortable = color_table;
        sprite->displayfunction = displayfunction;
        sprite->DrawTimeInterval = draw_time_interval;
        sprite->LastDrawTime = 0;
    }
}
