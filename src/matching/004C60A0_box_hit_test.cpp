// 004C60A0 RGE_Static_Object::box_hit_test(short, short, short, short, short, short)
// PDB: stat_obj.cpp:3761-3801, 402 bytes
// __thiscall, unsigned char, ret 18h
// FLAGS: default
//
// Attempt log:
// - Baseline kept the old nested-vtable stub and decompiler-shaped geometry;
//   it was 410 bytes with 68.26% instruction-shape similarity.
// - Restored the same-TU Active_Sprite_List virtual surface used by the exact
//   capture/draw donors.  get_facetindex(RGE_Sprite*, short) now emits the
//   original movzx/push/push/call sequence at 004C60BF.
// - Restored the polymorphic static-object surface and the reference get_frame
//   ABI.  The reference spelling is period-plausible and agrees with the
//   004C5880 PDB symbol and exact same-TU donors.
// - Corrected ownership/behavior: the first two inputs are screen offsets, the
//   last four are rectangle bounds, and the four corners/edge tests follow the
//   executable predicate order.  Parameter-left comparisons plus nested
//   positive edge checks raised shape similarity to 84.30% and exact-block
//   coverage to 82.28%.
// - Grouping x expressions before y expressions worsened the emitted basin;
//   restored the ordinary v1/v2/v3/v4 assignment order.  Separate declarations
//   and assignments were emitted-code duplicates.
// - Final bounded state: 424 rebuilt bytes versus 402, 328 strict differing
//   bytes, both calls aligned, frame 0x10 and saved registers exact.  Remaining
//   drift begins in the four derived-coordinate load/register schedule and
//   shifts the late branch targets; no call-set or ownership uncertainty remains.
// - Fresh retry: direct in-place updates of the four frame outputs restored
//   the original coordinate register schedule and reduced the diff to 125 bytes.
// - Fresh retry: parameter-left interior bounds matched the original compare
//   operands and reduced the diff to 123 bytes.
// - Fresh retry: each edge test as one boolean expression reproduced the
//   shared hit-return tails.  The natural typed source is an exact 402-byte match.

#include <stdlib.h>

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Sprite;

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3,
                      short param_4, short param_5, void* param_6,
                      void* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3,
                             void* param_4, void* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3,
                             void* param_4, void* param_5,
                             unsigned char param_6);
    virtual unsigned char is_animating(RGE_Sprite* param_1);
    virtual void set_frame(RGE_Sprite* param_1, short param_2);
    virtual unsigned char frame_passed(RGE_Sprite* param_1, short param_2);
    virtual unsigned char looped(RGE_Sprite* param_1);
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2);
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    char gap_04[0x0C];
    RGE_Sprite* sprite;
    char gap_14[0x04];
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x0C];
    short screen_x_offset;    // +0x28
    short screen_y_offset;    // +0x2A
    char gap_2C[0x09];
    unsigned char facet;      // +0x35

    int get_frame(short& min_x, short& min_y, short& max_x, short& max_y);
    unsigned char box_hit_test(short param_1, short param_2, short param_3, short param_4, short param_5, short param_6);
};
#endif

unsigned char RGE_Static_Object::box_hit_test(short param_1, short param_2, short param_3, short param_4, short param_5, short param_6) {
    if (this->sprite == 0) return 0;
    if (this->sprite_list == 0) return 0;

    this->sprite_list->get_facetindex(this->sprite, this->facet);

    short min_x;
    short min_y;
    short max_y;
    short max_x;
    if (this->get_frame(min_x, min_y, max_x, max_y) == 0) return 0;

    min_x = min_x + param_1 + this->screen_x_offset;
    min_y = min_y + param_2 + this->screen_y_offset;
    max_x = max_x + param_1 + this->screen_x_offset;
    max_y = max_y + param_2 + this->screen_y_offset;

    if (min_x >= param_3 && min_x <= param_5 && min_y >= param_4 && min_y <= param_6) return 1;
    if (max_x >= param_3 && max_x <= param_5 && max_y >= param_4 && max_y <= param_6) return 1;
    if (param_3 >= min_x && param_3 <= max_x && param_4 >= min_y && param_4 <= max_y) return 1;
    if (param_5 >= min_x && param_5 <= max_x && param_6 >= min_y && param_6 <= max_y) return 1;
    if (param_3 < min_x && param_5 > max_x &&
        ((param_4 > min_y && param_4 < max_y) ||
         (param_6 > min_y && param_6 < max_y))) return 1;
    if (param_4 < min_y && param_6 > max_y &&
        ((param_3 > min_x && param_3 < max_x) ||
         (param_5 > min_x && param_5 < max_x))) return 1;

    return 0;
}
