// VA 0045A030 RGE_Map::get_border_type
// map.cpp:2845-3012
// Attempt log:
// 1: Direct natural reconstruction from packet: neighbor terrain sampling, check_for_border calls, terrain-border lookup and edge code selection.
// 2: Modeled map layout facts used by asm: width +8, height +0xC, row table +0x8D8C, tile stride 24, terrain byte at +5 masked by 0x1F, output byte at +6.
// 3: Modeled eight neighbor samples in original order (left/right/top/bottom/corners by row +/-1 and offset +/-24), including boundary fallback to current terrain.
// 4: Added eight check_for_border(current,&neighbor) calls in the original order.
// 5: Added all-same-neighbor early zero-out path.
// 6: Added border lookup as raw table at this+0x14A + current*408, neighbor index*2, matching original address math better than an oversized C array.
// 7: Added border validity checks: 0xFFFF, negative, >=16, and terrain-enabled byte at this+0x338C + border*1440.
// 8: Added special word [edx+0x392A] == 1 case by composing low border nibble with bitmask of four cardinal neighbors.
// 9: Added normal edge selection ordering for 1,2,3,4,9,10,11,12,5,6,7,8 and final zero-out fallback.
// 10: Default /O2 /Oy compiles but is size-short: configured 1115 exceeds rebuilt .text 848. Source is behaviorally broad but too high-level/optimized relative to original stack-slot-heavy VC5 shape.
// 11: Probed /Od: exact size 1115 but broad wrong basin from offset 0 (91.7489% positional); removed flag.
// 12: Probed /O2 /Oy /Og-: exact size 1115 but same broad wrong basin from offset 0; removed flag.
// 13: Tried removing helper terrain_at and inlining row[offset] loads; default shrank further (944 -> 848), confirming original likely needs source-shaped stack-slot/parameter reuse rather than helper abstraction.
// GIVEUP: left in scratch. No accepted_drift because default build is size-short and exact-size diagnostic flags are broad from offset 0.

class RGE_Map {
public:
    char gap00[8];
    int width;   // +8
    int height;  // +C
    char gap10[0x8D8C-0x10];
    unsigned char** rows; // +8D8C

    void check_for_border(unsigned char current, unsigned char* other);
    void get_border_type(short x, short y);
};


void RGE_Map::get_border_type(short x, short y)
{
    unsigned char top_lft;
    unsigned char ter_lft;
    unsigned char ter_rgt;
    unsigned char ter_bot;
    unsigned char tile;
    unsigned char ter_bot_lft;
    unsigned char ter_bot_rgt;
    int yMax;
    int xMax;
    int xi;
    unsigned char ter_top;

    if (x < 0 || x >= this->width || y < 0 || y >= this->height) {
        return;
    }

    unsigned char** rows = this->rows;
    xi = x;
    int off = xi * 24;
    unsigned char* cur = rows[y] + off;
    top_lft = cur[5] & 0x1f;

    if (y > 0) ter_lft = rows[y - 1][off + 5] & 0x1f; else ter_lft = top_lft;
    yMax = this->height - 1;
    if (y < yMax) tile = rows[y + 1][off + 5] & 0x1f; else tile = top_lft;
    if (x > 0) ter_rgt = rows[y][off - 19] & 0x1f; else ter_rgt = top_lft;
    xMax = this->width - 1;
    if (xi < xMax) ter_bot = rows[y][off + 29] & 0x1f; else ter_bot = top_lft;
    if (y > 0 && x > 0) ter_bot_lft = rows[y - 1][off - 19] & 0x1f; else ter_bot_lft = top_lft;
    if (y > 0 && xi < xMax) ter_top = rows[y - 1][off + 29] & 0x1f; else ter_top = top_lft;
    if (y < yMax && x > 0) ter_bot_rgt = rows[y + 1][off - 19] & 0x1f; else ter_bot_rgt = top_lft;
    if (y < yMax && xi < xMax) xi = rows[y + 1][off + 29] & 0x1f; else xi = top_lft;

    unsigned char current = top_lft;
    check_for_border(current, &ter_lft);
    check_for_border(current, &tile);
    check_for_border(current, &ter_rgt);
    check_for_border(current, &ter_bot);
    check_for_border(current, &ter_bot_lft);
    check_for_border(current, &ter_top);
    check_for_border(current, &ter_bot_rgt);
    check_for_border(current, (unsigned char*)&xi);

    unsigned char al = ter_lft;
    if (al == top_lft && tile == top_lft && ter_rgt == top_lft && ter_bot == top_lft &&
        ter_bot_lft == top_lft && ter_top == top_lft && ter_bot_rgt == top_lft && (unsigned char)xi == top_lft) {
        cur[6] = 0;
        return;
    }

    short* table = (short*)((char*)this + 0x14A + current * 408);
    unsigned short border = table[al];
    if (border == 0xffff || (short)border < 0 || border >= 16 || !*((unsigned char*)this + 0x338C + ((int)(short)border) * 1440)) {
        cur[6] = 0;
        return;
    }

    unsigned char edge;
    if (table[ter_lft] == (short)border && table[ter_rgt] == (short)border) {
        edge = 1;
    } else if (table[ter_lft] == (short)border && table[ter_bot] == (short)border) {
        edge = 2;
    } else if (table[tile] == (short)border && table[ter_rgt] == (short)border) {
        edge = 3;
    } else if (table[tile] == (short)border && table[ter_bot] == (short)border) {
        edge = 4;
    } else if (table[ter_lft] == (short)border) {
        edge = 9;
    } else if (table[tile] == (short)border) {
        edge = 10;
    } else if (table[ter_rgt] == (short)border) {
        edge = 11;
    } else if (table[ter_bot] == (short)border) {
        edge = 12;
    } else if (table[ter_bot_lft] == (short)border) {
        edge = 5;
    } else if (table[ter_top] == (short)border) {
        edge = 6;
    } else if (table[ter_bot_rgt] == (short)border) {
        edge = 7;
    } else if (table[(unsigned char)xi] == (short)border) {
        edge = 8;
    } else {
        cur[6] = 0;
        return;
    }
    cur[6] = (unsigned char)((border & 0xf) | (edge << 4));
}
