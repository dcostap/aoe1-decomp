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
    short tile_x = (short)x;
    short tile_y = (short)y;
    float x_offset = x - (float)tile_x + this->radius_x;
    float y_offset = y - (float)tile_y + this->radius_y;
    int tile_half_width = world->map->tile_half_width;
    int tile_half_height = world->map->tile_half_height;

    x1 = (short)((x_offset + y_offset) * tile_half_width);
    y1 = (short)((y_offset - 0.5f - x_offset) * tile_half_height);
    x2 = (short)((x_offset + y_offset - 2.0f * this->radius_x) *
                 tile_half_width);
    y2 = (short)((y_offset - 0.5f - x_offset +
                  2.0f * this->radius_x) * tile_half_height);
    x3 = (short)((x_offset + y_offset - 2.0f * this->radius_x -
                  2.0f * this->radius_y) * tile_half_width);
    y3 = (short)((y_offset - 0.5f - x_offset +
                  2.0f * this->radius_x - 2.0f * this->radius_y) *
                 tile_half_height);
    x4 = (short)((x_offset + y_offset - 2.0f * this->radius_y) *
                 tile_half_width);
    y4 = (short)((y_offset - 0.5f - x_offset -
                  2.0f * this->radius_y) *
                 tile_half_height);
    return 1;
}
