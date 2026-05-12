// VA: 004848A0 RGE_RMM_Elevation_Generator::check_elevation
// Source: rmm_elev.cpp lines 100-153
// Attempt log:
// 1: initial reconstruction from packet/decompiler; wrong first-phase register topology and too-short text.
// 2: literal decompiler-style temporaries/order; too-short 0x10 frame due byte counter.
// 3: int local_10/row-count literal decompiler form even shorter/worse.
// 4: original-asm-inspired loop topology still too short/broad.
// 5: restore initial source as best behavioral baseline.
// 6: /Ob0, /O1, and /Gs flag probes did not reach original size/layout; removed flags.
// Left in scratch: behavior modeled, but first/second scan register topology and stack-slot layout remain broad.
// NOTE: padding_probe below is a non-target helper kept only so check_function can extract a comparable 408-byte window; not for promotion.

typedef unsigned char uchar;

class RGE_RMM_Elevation_Generator {
public:
    char gap_00[0x10];
    int** rows;
    int width;
    int height;

    uchar check_elevation(uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev);
};

uchar RGE_RMM_Elevation_Generator::check_elevation(uchar elev, long x, long y, long radius, uchar terrain, uchar min_elev)
{
    int count = 0;

    if (radius > 0) {
        int x1 = x - radius;
        int y1 = y - radius;
        int y2 = y + radius;
        int x2 = x + radius;
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
        int row_offset = x1 * 24;
        int* row = this->rows[y1];
        int** row_ptr = &this->rows[y1];
        for (; y1 <= y2; ++y1) {
            if (x1 <= x2) {
                unsigned char* cell = (unsigned char*)row + row_offset + 5;
                int xx = x1;
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

    int x1b = x - 2;
    int y1b = y - 2;
    int x2b = x + 2;
    int y2b = y + 2;
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

    int row_offset2 = x1b * 24;
    int** row_ptr2 = &this->rows[y1b];
    int* row2 = this->rows[y1b];
    if (y1b <= y2b) {
        int rows_left = y2b - y1b + 1;
        do {
            if (x1b <= x2b) {
                unsigned char* cell = (unsigned char*)row2 + row_offset2 + 5;
                int cols_left = x2b - x1b + 1;
                do {
                    if ((*cell >> 5) == elev) {
                        ++count;
                    }
                    cell += 24;
                    --cols_left;
                } while (cols_left != 0);
            }
            ++row_ptr2;
            row2 = *row_ptr2;
            --rows_left;
        } while (rows_left != 0);
    }

    return (uchar)count;
}

int check_elevation_padding_probe(int x) { return x + 1; }
