// attempt 1: transparency span extraction from Dib.cpp decomp/asm

void GetDibDim(void* dib, long* w, long* h, long* anyTrans);
void* malloc(unsigned int);
void free(void*);

struct TRANSENTRY { long allTrans; long solid; long first; long last; };
struct TRANSINFO { long anyTrans; char gap_04[0x10]; TRANSENTRY* entries; };
struct BITMAPINFO256 { long size; long orientation; };

int DibCheckTrans(BITMAPINFO256* dib, TRANSINFO* info, unsigned char* bits) {
    long w, h, anyTrans;
    long orien;
    GetDibDim(dib, &w, &h, &anyTrans);
    orien = dib->orientation;
    info->entries = (TRANSENTRY*)malloc(anyTrans * 16);
    if (info->entries == 0) {
        return 1;
    }
    long tw = 0;
    long y = 0;
    if (anyTrans > 0) {
        long off = 0;
        do {
            long row;
            int allTrans = 1;
            long first = w;
            if (orien == 1) row = w * y;
            else row = (anyTrans - y - 1) * w;
            unsigned char* scan = bits + row;
            long x = 0;
            if (w > 0) {
                do {
                    if (scan[x] != 0) {
                        if (allTrans) {
                            allTrans = 0;
                            first = x;
                        }
                    } else {
                        if (!tw) tw = 1;
                    }
                    ++x;
                } while (x < w);
            }
            long last = first;
            if (!allTrans) {
                x = first + 1;
                while (x < w) {
                    if (scan[x] != 0) last = x;
                    ++x;
                }
            }
            int solid = 1;
            if (!allTrans) {
                x = first;
                while (x <= last) {
                    if (scan[x] == 0) { solid = 0; break; }
                    ++x;
                }
            }
            info->entries[y].allTrans = allTrans;
            info->entries[y].solid = solid;
            info->entries[y].first = first;
            info->entries[y].last = last;
            ++y;
        } while (y < anyTrans);
    }
    info->anyTrans = tw;
    if (!tw) free(info->entries);
    return tw;
}
