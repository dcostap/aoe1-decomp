// VA: 004C3B30 RGE_Static_Object::draw_frame
// PDB source: stat_obj.cpp lines 1624-1676
// Baseline reconstruction: frame bounds and health-bar drawing follow the
// neighboring capture_square_frame source and the proven object/master layout.
// Attempt log:
// - typed baseline recovered the original 313-byte size, 0x8 frame, saved
//   registers, CFG, and all seven ordered calls;
// - corrected hp to +0x30 and used the proven get_facetindex/get_frame and
//   DrawRect/FillRect surfaces; this restored the complete structural call set;
// - coordinate declaration/order, receiver-local, and top-level-local probes
//   were codegen duplicates or worse and were rolled back;
// - remaining drift is a broad VC5 arithmetic/register and stack-home basin
//   beginning at the lower-left coordinate calculation (219 positional bytes,
//   66.96% instruction-shape similarity). Left in scratch after the bounded
//   ten-hypothesis pass.

class TDrawArea {
public:
    void DrawRect(long x1, long y1, long x2, long y2, unsigned char color);
    void FillRect(long x1, long y1, long x2, long y2, unsigned char color);
};

class RGE_Sprite;

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* sprite);
    virtual void update(float param_1, float param_2);
    virtual void draw(short facet, short x, short y, short shadow_x,
                      short shadow_y, void* color_table, TDrawArea* area);
    virtual void normal_draw(short facet, short x, short y,
                             void* color_table, TDrawArea* area);
    virtual void shadow_draw(short facet, short x, short y,
                             void* color_table, TDrawArea* area,
                             unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* sprite);
    virtual void set_frame(RGE_Sprite* sprite, short frame_number);
    virtual unsigned char frame_passed(RGE_Sprite* sprite, short frame_number);
    virtual unsigned char looped(RGE_Sprite* sprite);
    virtual short get_facetindex(RGE_Sprite* sprite, short facet);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x22];
    short hp;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Static_Object* master_obj;
    void* owner;
    RGE_Sprite* sprite;
    void* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    void* tile;
    char gap_20[0x8];
    short screen_x_offset;
    short screen_y_offset;
    char gap_2c[0x4];
    float hp;
    char gap_34;
    unsigned char facet;
    char gap_36[0x12];
    unsigned char object_state;

    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y);
    void draw_frame(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::draw_frame(TDrawArea* area, short x, short y)
{
    short min_x;
    short min_y;
    short max_y;
    short max_x;

    if (this->sprite != 0 && this->sprite_list != 0) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);

        if (this->get_frame(min_x, min_y, max_x, max_y) != 0) {
            int x1 = x + min_x + this->screen_x_offset - 1;
            int y1 = y + min_y + this->screen_y_offset - 1;

            area->DrawRect(x1, y1,
                           x + max_x + this->screen_x_offset + 1,
                           y + max_y + this->screen_y_offset + 1, 0xff);

            if (this->object_state <= 2) {
                int health = (int)this->hp;
                if (health < 1) {
                    health = 0;
                }

                int max_health = (int)this->master_obj->hp;
                if (max_health > 0) {
                    area->DrawRect(x1, y1 - 6, x1 + 26, y1 - 1, 0xff);
                    area->FillRect(x1 + 1, y1 - 5, x1 + 24, y1 - 3, 0x55);
                    area->FillRect(x1 + 1, y1 - 5,
                                   (health * 25) / max_health + x1,
                                   y1 - 2, 0x25);
                }
            }
        }
    }
}
