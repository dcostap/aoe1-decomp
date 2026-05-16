// 0044ED20 InfMap::connectionsIncluding
// Attempt log:
// initial direct low-level reconstruction from packet: validate bounds, scan rectangle, count neighboring connections.
// first build compiles but rebuilt .text is 656 vs original/configured 713, so check_function stops before compare.
// source models the initial bounds checks, start_count result, rectangle scan over row pointers, neighbor direction loop, parity/all_dirs filters, and mode-based edge penalties, but it is a broad behavioral scaffold.
// remaining mismatch is likely the exact 8-direction switch topology, row-pointer arithmetic, and odd/even direction gating; current source is too compact and wrong-shaped compared to original's large hand-unrolled switch/jumptable structure.
// left in scratch: not accepted_drift-safe because object size/topology is far from original and behavior details of several edge cases are speculative.

struct Point { int x; int y; };

class InfMap {
public:
    char gap0[4];
    int width;
    int height;
    int origin_x;
    int row_base;
    void** rows;
    char gap1c[4];
    int start_count;

    int connectionsIncluding(Point* a, Point* b, unsigned char base, unsigned char want, int mode1, int mode2, int all_dirs);
};

static int parity(int x) { return x & 1; }

int InfMap::connectionsIncluding(Point* a, Point* b, unsigned char base, unsigned char want, int mode1, int mode2, int all_dirs)
{
    int ax = a->x;
    if (ax < 0) return 0;
    int ay = a->y;
    if (ay < 0) return 0;
    int w = this->width;
    if (ax >= w) return 0;
    int h = this->height;
    if (ay >= h) return 0;
    int bx = b->x;
    if (bx < 0) return 0;
    int by = b->y;
    if (by < 0) return 0;
    if (bx >= w) return 0;
    if (by >= h) return 0;
    if (ax > bx) return this->start_count;
    if (ay > by) return this->start_count;

    int result = this->start_count;
    int y = ay;
    do {
        int rowoff = y * 4;
        int x = ax;
        do {
            unsigned char v = *((unsigned char*)this->rows[y - this->row_base] + (x - this->origin_x));
            if ((int)v + (int)base >= (int)want) {
                if (v >= want) {
                    int nx = ax;
                    int ny = ay;
                    for (int dir = 0; dir < 8; dir++) {
                        switch (dir) {
                        case 0: nx = x - 1; ny = y - 1; break;
                        case 1: nx = x;     ny = y - 1; break;
                        case 2: nx = x + 1; ny = y - 1; break;
                        case 3: nx = x - 1; ny = y;     break;
                        case 4: nx = x + 1; ny = y;     break;
                        case 5: nx = x - 1; ny = y + 1; break;
                        case 6: nx = x;     ny = y + 1; break;
                        case 7: nx = x + 1; ny = y + 1; break;
                        }
                        if (!all_dirs && ((dir < 0 ? -dir : dir) & 1) == 0) continue;
                        if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                            unsigned char nv = *((unsigned char*)this->rows[ny - this->row_base] + (nx - this->origin_x));
                            if (nv >= want) result += 2;
                        } else {
                            if (mode1 == 1 && ((dir < 0 ? -dir : dir) & 1) == 1) result--;
                            else if (mode2 == 1 && ((dir < 0 ? -dir : dir) & 1) == 0) result--;
                        }
                    }
                } else {
                    result--;
                }
            }
            x++;
        } while (x <= bx);
        y++;
    } while (y <= by);
    return result;
}
