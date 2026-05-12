// VA: 00486180 RGE_RMM_Object_Generator::set_search_area
// PDB: rmm_obj.cpp lines 206-226 (134 bytes, 56 asm lines)
// Default flags. No inline asm/hacks.

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x14];
    long width;
    long height;
    char gap_1C[0x08];
    unsigned char** rows;

    void set_search_area(long x, long y, long radius, unsigned char fill);
};

void RGE_RMM_Object_Generator::set_search_area(long x, long y, long radius, unsigned char fill)
{
    long sx = x - radius;
    long sy = y - radius;
    long end_x = x + radius;
    long end_y = radius + y;

    if (sx < 0) sx = 0;
    if (sy < 0) sy = 0;
    if (end_x >= this->width) end_x = this->width - 1;
    if (end_y >= this->height) end_y = this->height - 1;

    long y_cur = sy;
    if (y_cur <= end_y) {
        do {
            if (sx <= end_x) {
                long cx = sx;
                do {
                    ++cx;
                    this->rows[y_cur][cx - 1] = fill;
                } while (cx <= end_x);
            }
            ++y_cur;
        } while (y_cur <= end_y);
    }
}
