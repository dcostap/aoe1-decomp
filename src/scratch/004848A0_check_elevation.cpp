// VA: 004848A0 RGE_RMM_Elevation_Generator::check_elevation
// Source: rmm_elev.cpp lines 100-153
// Attempt log:
// 1: initial reconstruction from packet/decompiler; wrong first-phase register topology and too-short text.
// 2: literal decompiler-style temporaries/order; too-short 0x10 frame due byte counter.
// 3: int local_10/row-count literal decompiler form even shorter/worse.
// 4: original-asm-inspired loop topology still too short/broad.
// 5: restore initial source as best behavioral baseline.
// 6: /Ob0, /O1, and /Gs flag probes did not reach original size/layout; removed flags.
// New claim: carry the second scan's row base plus x-offset across the row
// increment, matching the original `mov next_row; add offset` topology instead
// of recomputing the offset inside each cell LEA.
// Next ABI/layout probe: reuse the check_start_elevation sibling's byte-row
// ownership (`char**` plus byte row bases) instead of `int**`/`int*` aliases.
// Next liveness probe: model the binary-proven `count` stack local as the first
// scan's row counter, while keeping the second scan's byte result separate.
// Final source-width probe: use the period code's natural `long` coordinate,
// offset, and count locals throughout both scans instead of decompiler `int`s.
// Clean-source result: second-scan row-base carry is retained (408B boundary
// still lacks 11 effective bytes); first-scan row-base carry, result/row-count
// split, combined predicate, and inherited-class context were rolled back as
// worse or duplicate. No source-shape path reached the original first-scan
// stack homes; padding_probe remains non-target scaffolding.
// Left in scratch: behavior modeled, but first/second scan register topology and stack-slot layout remain broad.
// NOTE: padding_probe below is a non-target helper kept only so check_function can extract a comparable 408-byte window; not for promotion.

typedef unsigned char uchar;

// Main-agent audit confirmed canonical elevation-map ownership and retained the
// natural two-scan bounds check; padding remains non-target scaffolding only.
class RGE_RMM_Elevation_Generator {
public:
    char gap_00[0x10];
    char** rows;
    int width;
    int height;

    uchar check_elevation(uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev);
};

uchar RGE_RMM_Elevation_Generator::check_elevation(uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev)
{
    long count = 0;

    if (radius > 0) {
        long x1 = x - radius;
        long y1 = y - radius;
        long y2 = y + radius;
        long x2 = x + radius;
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->width) {
            x2 = this->width - 1;
        }
        if (y2 >= this->height) {
            y2 = this->height - 1;
        }
        long row_offset = x1 * 24;
        char* row = this->rows[y1];
        char** row_ptr = &this->rows[y1];
        for (; y1 <= y2; ++y1) {
            if (x1 <= x2) {
                unsigned char* cell = (unsigned char*)row + row_offset + 5;
                long xx = x1;
                do {
                    if (terrain == 0xFF) {
                        return 0;
                    }
                    unsigned char v = *cell;
                    if ((v & 0x1F) != terrain) {
                        return 0;
                    }
                    if ((v >> 5) < min_elev) {
                        return 0;
                    }
                    ++xx;
                    cell += 24;
                } while (xx <= x2);
            }
            ++row_ptr;
            row = *row_ptr;
        }
    }

    long x1b = x - 2;
    long y1b = y - 2;
    long x2b = x + 2;
    long y2b = y + 2;
    if (x1b < 0) {
        x1b = 0;
    }
    if (y1b < 0) {
        y1b = 0;
    }
    if (x2b >= this->width) {
        x2b = this->width - 1;
    }
    if (y2b >= this->height) {
        y2b = this->height - 1;
    }

    long row_offset2 = x1b * 24;
    char** row_ptr2 = &this->rows[y1b];
    unsigned char* row_base2 = (unsigned char*)this->rows[y1b] + row_offset2;
    if (y1b <= y2b) {
        long rows_left = y2b - y1b + 1;
        do {
            if (x1b <= x2b) {
                unsigned char* cell = row_base2 + 5;
                long cols_left = x2b - x1b + 1;
                do {
                    if ((*cell >> 5) == elev) {
                        ++count;
                    }
                    cell += 24;
                    --cols_left;
                } while (cols_left != 0);
            }
            ++row_ptr2;
            row_base2 = (unsigned char*)*row_ptr2 + row_offset2;
            --rows_left;
        } while (rows_left != 0);
    }

    return (uchar)count;
}

int check_elevation_padding_probe(int x) { return x + 1; }
