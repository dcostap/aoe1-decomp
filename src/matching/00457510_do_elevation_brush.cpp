// VA: 00457510 RGE_Map::do_elevation_brush(long,long,long,unsigned char)
// Exact MATCH. Key fix after prior parameter-reuse attempts: use natural independent min/max locals
// and a plain for(row=miny; row<=maxy; ++row) loop; VC5 then recovers the original stack homes
// and inner offset/count loop exactly.
struct MapCell { char gap[5]; unsigned char elev; char rest[18]; };
struct RGE_Map { char gap[8]; int map_width; int map_height; char gap2[0x8D7C]; MapCell** map_row_offset; unsigned char do_elevation_brush(long x,long y,long radius,unsigned char elevation); };
unsigned char RGE_Map::do_elevation_brush(long x,long y,long radius,unsigned char elevation)
{
    long minx = x - radius;
    long maxx = x + radius;
    long miny = y - radius;
    long maxy = y + radius;
    if (minx < 0) minx = 0;
    if (maxx >= this->map_width) maxx = this->map_width - 1;
    if (miny < 0) miny = 0;
    if (maxy >= this->map_height) maxy = this->map_height - 1;
    for (long row = miny; row <= maxy; ++row) {
        if (minx <= maxx) {
            unsigned char elev = (unsigned char)(elevation << 5);
            int offset = minx * 24;
            int count = maxx - minx + 1;
            do {
                unsigned char* p = (unsigned char*)this->map_row_offset[row] + offset;
                p[5] = (p[5] & 0x1f) | elev;
                offset += 24;
                count--;
            } while (count);
        }
    }
    return 1;
}
