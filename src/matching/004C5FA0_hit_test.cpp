// VA: 004C5FA0 RGE_Static_Object::hit_test
// PDB source: stat_obj.cpp lines 3726-3757
// Attempt log:
// - Initial clean reconstruction: sprite-list frame lookup, screen-relative
//   coordinates, and the square scan shown by the original control flow.
// - Split coordinate initialization and parameter-home mutation were rolled
//   back; the former was codegen-neutral and the latter worsened the basin.
// - A short frame local with conventional nested for loops reached exact-size
//   CFG parity; swapping the loop axes to outer-x/inner-y reproduced the
//   original accumulator/register topology and exact bytes.

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Sprite;

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* sprite);
};

class RGE_Sprite {
public:
    unsigned char hit_test(short x, short y, long facet, long frame);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    char gap_04[0x0C];
    RGE_Sprite* sprite;                    // +0x10
    char gap_14[0x04];
    RGE_Active_Sprite_List* sprite_list;   // +0x18
    char gap_1C[0x0C];
    short screen_x_offset;                 // +0x28
    short screen_y_offset;                 // +0x2A
    char gap_2C[0x09];
    unsigned char facet;                   // +0x35

    unsigned char hit_test(short x, short y, short x2, short y2, short range);
};
#endif

unsigned char RGE_Static_Object::hit_test(
    short x, short y, short x2, short y2, short range)
{
    if (this->sprite != 0 && this->sprite_list != 0) {
        short frame = this->sprite_list->frame(this->sprite);
        short hit_x = x2 - this->screen_x_offset - x;
        short hit_y = y2 - this->screen_y_offset - y;

        if (this->sprite->hit_test(hit_x, hit_y, this->facet, frame) != 0) {
            return 1;
        }

        if (range != 0) {
            for (short outer = -range; outer < range; ++outer) {
                for (short inner = -range; inner < range; ++inner) {
                    if (this->sprite->hit_test(
                            hit_x + outer, hit_y + inner,
                            this->facet, frame) != 0) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }

    return 0;
}
