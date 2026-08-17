// VA: 00454690 RGE_Master_Static_Object::alignment_box (337B)
// PDB source: m_s_obj.cpp, lines 1092-1122
// Attempt log:
// - Replaced the placeholder with a typed reconstruction from the original
//   packet and the draw_object_outline donor.  The method computes four
//   isometric box corners from the fractional tile position and the object's
//   two radius fields.  It writes eight short references and returns 1.
// - Short tile-half locals produced the closest structural basin (322-byte
//   diff, 48.57% shape) and restored saved EDI, but grew the body by 3 bytes.
// - Reusing x/y parameter homes was a codegen duplicate.
// - Explicit double y-base and +1.0 expression probes moved the x87 block but
//   grew the body.  They were diagnostic only; the clean semantic source is
//   restored below.
// - A single tx plus reused y home was worse (335-byte diff).  The remaining
//   blocker is the original 0xC local frame and EDI allocation.
// - The interrupted explicit-double first-y probe stayed at 314 bytes and
//   only changed x87 scheduling.  Removed it; retain the natural typed
//   +1.0/short-dimension reconstruction.  DAT_00570638 is -1.0, and the
//   original map loads are signed word loads.
// - Reordered the x-offset assignment before y conversion; VC5 emitted the
//   same code, so the clean source shape is unchanged.
// - Named a repeated double y-base to model the observed qword temporary;
//   it grew the body by 17 bytes and was rolled back.
// - Tried typed parenthesized repeated-add radii across all corner expressions;
//   strict diff improved to 282 bytes but shape fell to 45.37% and the source
//   was 334 bytes, so the clean reconstruction was restored.
// - Binary x87 reuse supports mutating the x/y offsets between corner pairs;
//   the next probe tests that natural sequential source shape.
// - Resumed pass: the natural source builds 341 bytes versus the original
//   337, with exact frame, saved registers, and ordered __ftol calls. The
//   first mismatch is the final x-radius update at +0x117.
// - Tested repeated-add, operand-order, explicit/direct-expression, helper,
//   cached-local, and prior-mutation spellings. They either duplicate the
//   341-byte basin or worsen frame and x87 scheduling. A negative-product
//   spelling reached 340 bytes but had worse shape and was diagnostic only.
// - The final positive x-radius update with a parenthesized member sum
//   (`radius_x + radius_x`) recovers the target fld/fadd sequence. The full
//   source now emits the original 337 bytes exactly.

class RGE_Map {
public:
    char gap_00[0x8D9A];
    short tile_half_height;             // +0x8D9A
    short tile_half_width;              // +0x8D9C
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;                        // +0x28
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;                      // +0x30
    float radius_y;                      // +0x34

    unsigned char alignment_box(
        RGE_Game_World* world, float x, float y,
        short& x1, short& y1, short& x2, short& y2,
        short& x3, short& y3, short& x4, short& y4);
};

unsigned char RGE_Master_Static_Object::alignment_box(
    RGE_Game_World* world, float x, float y,
    short& x1, short& y1, short& x2, short& y2,
    short& x3, short& y3, short& x4, short& y4)
{
    short tile_x;
    short tile_y;
    float x_offset;
    float y_offset;
    tile_x = (short)x;
    tile_y = (short)y;
    x_offset = x - (float)tile_x + this->radius_x;
    y_offset = y - (float)tile_y + this->radius_y;
    short tile_half_width = world->map->tile_half_width;
    short tile_half_height = world->map->tile_half_height;

    x1 = (short)((x_offset + y_offset) * tile_half_width);
    y1 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    x_offset -= 2.0f * this->radius_x;
    x2 = (short)((x_offset + y_offset) * tile_half_width);
    y2 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    y_offset -= 2.0f * this->radius_y;
    x3 = (short)((x_offset + y_offset) * tile_half_width);
    y3 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    x_offset += (this->radius_x + this->radius_x);
    x4 = (short)((x_offset + y_offset) * tile_half_width);
    y4 = (short)((y_offset + 1.0 - x_offset) * tile_half_height);
    return 1;
}
