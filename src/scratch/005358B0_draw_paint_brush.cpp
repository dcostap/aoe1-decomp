// 005358B0 RGE_View::draw_paint_brush (view.cpp:2213-2265, 296B)
// Paints a terrain brush cursor at the mouse position, with grid snapping in editor mode.
//
// Left in scratch: 265/296 bytes match (89.5%), edit diff 11.8%.
// Remaining differences are VC5 codegen choices:
// - sub esp: 0x1C vs 0x20 (4-byte stack diff shifts all offsets)
// - pick result check: `and eax,0FFh; cmp al,33h` vs `movzx ax,al; cmp ax,33h`
// - LEA operand order: `lea [ecx+eax]` vs `lea [eax+ecx]` (commutative, diff encoding)
// All logic, bounds checks (+0x8C/0x90/0x94/0x98), pick call, editor_mode (+0x1B4),
// brush_size (+0x402), grid snapping (1/3f, 1.0f), ftol calls, set_selection_area
// calls, and register save pattern (esi/ebx after pick check) verified correct.
// FLAGS: /nologo /c /O2 /Oy

struct tagPOINT { long x, y; };

struct RGE_PickInfo2 {
    long x;
    float y;
    float scr_x;
    float scr_y;
};

struct RGE_Base_Game2 {
    char _gap_00[4];
    void get_mouse_pos(tagPOINT* pt);
};

extern "C" {
    extern RGE_Base_Game2* rge_base_game;
}

struct RGE_View3 {
    char _pad_00[0x8C];
    int view_left;      // +0x8C
    int view_top;       // +0x90
    int view_right;     // +0x94
    int view_bottom;    // +0x98

    void set_selection_area(int x1, int y1, int x2, int y2);
    unsigned char pick(unsigned char mode, unsigned char param,
                       int mouse_x, int mouse_y,
                       RGE_PickInfo2* info, int flags);
    void draw_paint_brush();
};

void RGE_View3::draw_paint_brush() {
    set_selection_area(-1, -1, -1, -1);

    tagPOINT mousePos;
    rge_base_game->get_mouse_pos(&mousePos);

    if (mousePos.x < view_left || mousePos.x > view_right ||
        mousePos.y < view_top || mousePos.y > view_bottom)
        return;

    RGE_PickInfo2 pickInfo;
    int pickResult = pick(0x28, 0, mousePos.x, mousePos.y, &pickInfo, 0);

    if ((unsigned short)(unsigned char)pickResult != '3')
        return;

    short brushSize;
    if (*(int*)((char*)rge_base_game + 0x1B4) == 0x13) {
        int t1 = (int)(pickInfo.y * (1.0f / 3.0f));
        int v1 = -t1 * 3;
        pickInfo.scr_x = 1.0f - (float)v1;

        int t2 = (int)(pickInfo.scr_y * (1.0f / 3.0f));
        int v2 = -t2 * 3;
        pickInfo.scr_y = 1.0f - (float)v2;

        brushSize = 3;
    } else {
        brushSize = *(signed short*)((char*)rge_base_game + 0x402);
    }

    int cx = (int)pickInfo.scr_x;
    int cy = (int)pickInfo.scr_y;
    int half = (int)(signed short)brushSize >> 1;
    set_selection_area(cx - half, cy - half, cx + half, cy + half);
}
