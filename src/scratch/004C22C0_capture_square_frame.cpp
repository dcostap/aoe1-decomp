// VA: 004C22C0 RGE_Static_Object::capture_square_frame
// PDB source: stat_obj.cpp lines 941-997
//
// Attempt log:
// - Replaced the placeholder with a period-plausible typed reconstruction:
//   sprite-list facet lookup, frame bounds, the square capture node, and the
//   health-bar capture node.  Layout and call surfaces follow exact stat_obj
//   donors and the binary-proven offsets.
// - Baseline had exact size/frame/call-set parity; the remaining drift was in
//   frame-bound local homes, arithmetic scheduling, and the health-bar tail.
// - Confirmed the PDB short-reference get_frame ABI and the sprite output order
//   (min_x, min_y, max_x, max_y).  Pointer/reference and ordinary expression
//   variants mostly collapsed to the same VC5 codegen basin.
// - An inline x2 expression added a frame slot and was rolled back.  Spelling
//   object_state <= 2 and health_right >= x1 + 26 recovered the original branch
//   polarity; declaring/calculating y2 before x2 recovered the original local
//   LEA block and is the current natural candidate (207 strict differing bytes).
// - A 512-case lab over plausible coordinate expression/declaration orders was
//   one emitted-code group with no exact variant; remaining drift is the
//   localized VC5 arithmetic/call scheduling after get_frame, not an unresolved
//   ownership or call-set question.
// - Main-agent audit confirmed canonical static/master/active-sprite ownership
//   and retained the natural named coordinate reconstruction.
// - DIA inspection of the original PDB confirms the parameter names render_area,
//   x, and y, the four short frame outputs, and one direct int local y0; y0 is
//   the reused y-line value and the first AddGDINode setup writes back an
//   incoming parameter home.  The current source keeps that ordinary ownership.
// - This session tried inline x2/direct-coordinate forms, operand reversals,
//   split arithmetic, declaration/initialization order, and y0 scope.  Inline
//   and direct forms changed the frame to 0xc/0x10 or expanded the function;
//   the remaining natural y0 candidate is emitted-code-duplicate with the
//   prior 207-byte frontier.
// - Added the exact stat_obj.cpp donor-era <stdlib.h> context from 004C1F30;
//   strict diff improved to 158 bytes and shape to 84.55%, with the exact
//   five-call set and coordinate ownership preserved.
// - Final bounded pause: size/frame/saved-registers and all five ordered calls
//   remain exact; the first unresolved hunk is coordinate register/liveness at
//   004C230E, followed by health-bar scheduling.

#include <stdlib.h>

class TDrawArea;
class RGE_Sprite;

class DClipInfo_Node;
class DClipInfo_List {
public:
    DClipInfo_Node* AddGDINode(int param_1, int param_2,
                               short param_3, short param_4, short param_5,
                               short param_6, short param_7, short param_8,
                               short param_9, short param_10,
                               int param_11, int param_12, int param_13);
};

extern DClipInfo_List* SDI_List;
extern int SDI_Object_ID;

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3,
                      short param_4, short param_5, void* param_6,
                      TDrawArea* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3,
                             void* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3,
                             void* param_4, TDrawArea* param_5,
                             unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* param_1);
    virtual void set_frame(RGE_Sprite* param_1, short param_2);
    virtual unsigned char frame_passed(RGE_Sprite* param_1, short param_2);
    virtual unsigned char looped(RGE_Sprite* param_1);
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2);
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

    int get_frame(short& param_1, short& param_2, short& param_3,
                  short& param_4);
    void capture_square_frame(TDrawArea* param_1, short param_2, short param_3);
};

void RGE_Static_Object::capture_square_frame(TDrawArea* param_1,
                                             short param_2, short param_3)
{
    short min_x;
    short min_y;
    short max_y;
    short max_x;
    int y0;

    if (this->sprite != 0 && this->sprite_list != 0) {
        this->sprite_list->get_facetindex(this->sprite, this->facet);

        if (this->get_frame(min_x, min_y, max_x, max_y) != 0) {
            int x1 = param_2 + min_x - 1 + this->screen_x_offset;
            int y1 = param_3 + min_y - 1 + this->screen_y_offset;
            y0 = param_3 + max_y + 1 + this->screen_y_offset;
            int x2 = param_2 + max_x + 1 + this->screen_x_offset;

            SDI_List->AddGDINode(4, y0, x1, y1, x2, y0,
                                 0, 0, 0, 0, 10, 0xff, SDI_Object_ID);

            if (this->object_state <= 2) {
                int health = (int)this->hp;
                if (health < 1) {
                    health = 0;
                }

                int max_health = (int)this->master_obj->hp;
                if (max_health > 0) {
                    int health_right = (health * 25) / max_health + x1;
                    if (health_right >= x1 + 26) {
                        health_right = x1 + 25;
                    }

                    SDI_List->AddGDINode(2, y0, x1, y1 - 6, x1 + 26,
                                         y1 - 1, health_right, 0,
                                         health_right + 1, 0, 20, 0xff,
                                         SDI_Object_ID);
                }
            }
        }
    }
}
