// 005358B0 RGE_View::draw_paint_brush (view.cpp:2213-2265, 296B)
// Paints a terrain brush cursor at the mouse position, with grid snapping in editor mode.
// Attempt log:
// - baseline: natural mouse/pick records had a 0x1C frame and 176 strict diff bytes.
// - layout: restored the proven 20-byte RGE_Pick_Info; its offset-0x8 word is
//   also consumed/stored as a float by the original, so retain that narrow union overlay.
// - ABI: an unsigned-short pick result reproduces the original movzx ax,al and reduced
//   the mismatch to 8 bytes; named game_mode/brush_size fields are codegen-equivalent.
// - behavior/liveness probes: point.y address, local scope/order, and point.x temp reuse
//   did not improve the 8-byte result; the point.y cast and point.x reuse were rolled back.
// - left in scratch: 8 strict bytes, all localized to six FPU stack displacements and
//   two equivalent LEA SIB encodings; calls, frame, CFG, and behavior topology align.
// - Main-agent audit replaced numbered decompiler types with canonical polymorphic
//   game/view ownership; the binary-proven pick-record union remains explicit.
// FLAGS: /nologo /c /O2 /Oy

struct tagPOINT { long x, y; };

struct RGE_Pick_Info {
    float x;
    float y;
    union {
        struct {
            short scr_x;
            short scr_y;
        } screen;
        float screen_value;
    };
    void* object;
    void* tile;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x1B0];
    int game_mode;
    char _gap_1B8[0x24A];
    short brush_size;
    void get_mouse_pos(tagPOINT* pt);
};

extern RGE_Base_Game* rge_base_game;

class RGE_View {
public:
    virtual ~RGE_View();
    char gap_04[0x88];
    int view_left;      // +0x8C
    int view_top;       // +0x90
    int view_right;     // +0x94
    int view_bottom;    // +0x98

    void set_selection_area(int x1, int y1, int x2, int y2);
    unsigned char pick(unsigned char mode, unsigned char param,
                       int mouse_x, int mouse_y,
                       RGE_Pick_Info* info, int flags);
    void draw_paint_brush();
};

void RGE_View::draw_paint_brush() {
    tagPOINT mousePos;
    RGE_Pick_Info pickInfo;

    set_selection_area(-1, -1, -1, -1);

    rge_base_game->get_mouse_pos(&mousePos);

    if (mousePos.x < view_left || mousePos.x > view_right ||
        mousePos.y < view_top || mousePos.y > view_bottom)
        return;

    unsigned short pickResult = (unsigned char)pick(0x28, 0, mousePos.x, mousePos.y, &pickInfo, 0);

    if (pickResult != '3')
        return;

    short brushSize;
    if (rge_base_game->game_mode == 0x13) {
        int t1 = (int)(pickInfo.y * (1.0f / 3.0f));
        int v1 = -t1 * 3;
        pickInfo.y = 1.0f - (float)v1;

        int t2 = (int)(pickInfo.screen_value * (1.0f / 3.0f));
        int v2 = -t2 * 3;
        pickInfo.screen_value = 1.0f - (float)v2;

        brushSize = 3;
    } else {
        brushSize = rge_base_game->brush_size;
    }

    int cx = (int)pickInfo.y;
    int cy = (int)pickInfo.screen_value;
    int half = (int)(signed short)brushSize >> 1;
    set_selection_area(cx - half, cy - half, cx + half, cy + half);
}
