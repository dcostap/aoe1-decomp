// 004381D0 RGE_Diamond_Map::draw_clipped_horz_line
// Source: diam_map.cpp lines 1192-1200. 123 bytes. __thiscall, ret 14h.
//
// Attempt log:
// - probe 1: basic implementation → 75% diff (wrong arg order + reg alloc)
// - probe 2: separate clipped_p1/result locals → 33% diff
// - probe 3: inline expressions → still 33% diff
// - probe 4: fix DrawHorzLine arg order (p1 not p3) + result_x → 11.4% diff
// Remaining: 14 byte-level diffs, ALL register allocation (ESI vs EDI for
// the line pointer). Original: ESI=line, EDI=pnl_x. Rebuilt: EDI=line, ESI=clipped_left.
// VC5 register heuristic. Cannot be forced from C++. Left in scratch.

#ifndef DIAM_MAP_CONTEXT_H
class TDrawArea;
#endif
class TPanel;

#ifndef DIAM_MAP_CONTEXT_H
class TDrawArea {
public:
    char gap_00[0x3C];
    void* DrawSurface;
    void DrawHorzLine(long p1, long p2, long p3, unsigned char p4);
};

class TPanel {
public:
    virtual ~TPanel();
    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Map_Image_Line {
public:
    short gap_00;
    short start_x;
    short line_len;
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Diamond_Map : public TPanel {
public:
    void draw_clipped_horz_line(
        short p1, short p2, short p3,
        unsigned char p4, RGE_Map_Image_Line* line
    );
};
#endif

void RGE_Diamond_Map::draw_clipped_horz_line(
    short p1, short p2, short p3,
    unsigned char p4, RGE_Map_Image_Line* line
) {
    long clipped_left = this->pnl_x + line->start_x;

    if (p1 < clipped_left) {
        p1 = (short)(this->pnl_x + line->start_x);
    }

    short result_x = p3;
    if ((long)(p1 + p3 - 1) >= clipped_left + line->line_len) {
        result_x = (short)(this->pnl_x - p1 + line->line_len + line->start_x);
    }

    this->render_area->DrawHorzLine(
        (long)p1, (long)p2, (long)result_x, p4
    );
}
