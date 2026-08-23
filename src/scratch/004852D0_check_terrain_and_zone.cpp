// VA: 004852D0 RGE_RMM_Land_Generator::check_terrain_and_zone
// rmm_land.cpp lines 57-140
// Attempt log:
// - The PDB gives target, land_num, x, y, count, x0/x1, y1, cx0/cx1,
//   cy0/cy1, octogon_y0/octogon_y1, and zone. Both octogon locals use -0x18.
// - The original calls __ftol, clamps octogon to two, and stores both derived
//   row bounds. The scan never reads them. It tests only x/y +/-2.
// - ORIGINAL BUG: the octogon bounds have no effect. Adding either bound to
//   the scan changes the count and does not match the executable behavior.
// - In the authentic rmm_land prefix, PDB declaration order matched bytes
//   through +0x44. Natural unused octogon locals still made VC5 remove __ftol.
// - Diagnostic tautologies retained the x87 call and both stores. They were
//   rejected because they are not plausible source and did not match.
// - Blocker: recover the natural source or ambient context that retains both
//   unused octogon stores without adding scan comparisons or fake volatility.
// - Fresh probes: reassigning the bounds, using a local array, and overwriting
//   loop bounds all duplicate the clean output and still remove __ftol.
// - A natural impossible-order guard retains __ftol but adds one CFG edge and
//   returns, so it is rejected. Self-cancelled counter or result expressions
//   still remove __ftol. Redundant octogon row guards retain it but add compares
//   and a larger frame. These forms are not retained.

#include "../../include/rmm_land_context.h"

uchar RGE_RMM_Land_Generator::check_terrain_and_zone(uchar target, uchar land_num, long x, long y)
{
    long count = 0;
    long area = this->info.land[land_num].area;
    long x0 = x - area;
    long x1 = x + area;
    long y1 = y + area;
    long y0 = y - area;
    long octogon = (long)((double)area * dbl_571ED0);
    long cx0 = x - 2;
    long cy0 = y - 2;
    long cx1 = x + 2;
    long cy1 = y + 2;
    uchar zone = this->info.land[land_num].zone;
    uchar** rows = this->search_map_rows;

    if ((int)rows[y][x] != this->info.land_num) {
        return 0;
    }

    if (octogon < 2) {
        octogon = 2;
    }
    long octogon_y0 = y - octogon;
    long octogon_y1 = y + octogon;

    long yy = y0;
    long xx;
    if (yy > y1) {
        return (uchar)count;
    }

    do {
        if (yy < 0) {
            if (yy > cy0) {
                count += 5;
            }
        } else if (yy >= this->map_height) {
            if (yy < cy1) {
                count += 5;
            }
        } else {
            xx = x0;
            if (xx <= x1) {
                do {
                    if (xx < 0) {
                        if (xx > cx0) {
                            count++;
                        }
                    } else if (xx >= this->map_width) {
                        if (xx < cx1) {
                            count++;
                        }
                    } else {
                        if (rows[yy][xx] == zone) {
                            if (yy >= cy0 && yy <= cy1 && xx >= cx0 && xx <= cx1) {
                                count++;
                            }
                        } else if ((int)rows[yy][xx] < this->info.land_num) {
                            return 0;
                        }
                    }
                    xx++;
                } while (xx <= x1);
            }
        }
        yy++;
    } while (yy <= y1);

    return (uchar)count;
}
