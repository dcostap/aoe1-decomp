// VA: 004852D0 RGE_RMM_Land_Generator::check_terrain_and_zone
// rmm_land.cpp lines 57-140
// Attempt log:
// 1: natural/raw-offset source from packet/decompiler: 416 B (configured 417), close prologue/calls but frame 0x20 not original 0x1c and x/y registers swapped.
// 2: swapped long parameter order: still 416 B and did not fix row-index/register roles.
// 3: removing unused-looking radius bounds locals shortened to 368 B, worse; rolled back.
// 4: volatile dummy frame-forcing on shortened source had no useful effect.
// tried flags /O2 no-/Oy, /Ox same; /O1 much too short.
// left in scratch: behavior modeled, but remaining mismatch is broad stack-frame/register allocation and x/y role scheduling; not accepted_drift-safe.

typedef unsigned char uchar;

class RGE_RMM_Land_Generator {
public:
    uchar check_terrain_and_zone(uchar land_id, uchar unused, long x, long y);
};

extern double dbl_571ED0;

uchar RGE_RMM_Land_Generator::check_terrain_and_zone(uchar land_id, uchar unused, long x, long y)
{
    int count = 0;
    char* self = (char*)this;
    int land_index = (int)(unsigned char)land_id;
    char* land = self + land_index * 52;
    int area = *(int*)(land + 0x44);
    int x1 = x - area;
    int y0 = y - area;
    int x2 = x + area;
    int y2 = y + area;
    int cx1 = x - 2;
    int cy1 = y - 2;
    int cx2 = x + 2;
    int cy2 = y + 2;
    int radius = (int)((double)area * dbl_571ED0);
    unsigned char zone = *(unsigned char*)(land + 0x48);
    unsigned char terrain;
    int yy;
    int xx;
    int* rows;

    rows = *(int**)(self + 0x24);
    terrain = *(unsigned char*)(rows[y] + x);
    if ((int)terrain != *(int*)(self + 0x144C)) {
        return 0;
    }

    if (radius < 2) radius = 2;
    y0 = y - radius;
    y2 = y + radius;

    yy = y - area;
    if (yy > y + area) {
        return (uchar)count;
    }

    do {
        if (yy < 0) {
            if (yy > cy1) count += 5;
        } else if (yy >= *(int*)(self + 0x18)) {
            if (yy < cy2) count += 5;
        } else {
            xx = x1;
            if (xx <= x2) {
                do {
                    if (xx < 0) {
                        if (xx > cx1) count++;
                    } else if (xx >= *(int*)(self + 0x14)) {
                        if (xx < cx2) count++;
                    } else {
                        unsigned char t = *(unsigned char*)(rows[yy] + xx);
                        if (t == zone) {
                            if (yy >= y0 && yy <= y2 && xx >= cx1 && xx <= cx2) {
                                count++;
                            }
                        } else if ((int)t < *(int*)(self + 0x144C)) {
                            return 0;
                        }
                    }
                    xx++;
                } while (xx <= x2);
            }
        }
        yy++;
    } while (yy <= y + area);

    return (uchar)count;
}
