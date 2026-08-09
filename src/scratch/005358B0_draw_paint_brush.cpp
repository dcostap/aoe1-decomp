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
// - Session layout probe: a typed storage union overlays the dead mouse point.y
//   home with the pick record's x field, and passes the binary-proven
//   RGE_Pick_Info-at-y view to pick.  Adding the observed trailing local footprint
//   recovered the 0x20 frame and reduced the result to 2 SIB-order bytes.
//   Reversed/negative addition spellings were duplicates; retain natural + terms.
// - Main-agent audit expressed the proven point/pick overlap as a directly
//   addressable union member, removing the residual pointer-alias cast.
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

struct Paint_Brush_Pick_Overlay {
    long point_x;
    long point_y;
    RGE_Pick_Info pick_info;
};

union Paint_Brush_Storage {
    tagPOINT point;
    Paint_Brush_Pick_Overlay pick;
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
    Paint_Brush_Storage storage;

    set_selection_area(-1, -1, -1, -1);

    rge_base_game->get_mouse_pos(&storage.point);

    if (storage.point.x < view_left || storage.point.x > view_right ||
        storage.point.y < view_top || storage.point.y > view_bottom)
        return;

    unsigned short pickResult = (unsigned char)pick(
        0x28, 0, storage.point.x, storage.point.y,
        &storage.pick.pick_info, 0);

    if (pickResult != '3')
        return;

    short brushSize;
    if (rge_base_game->game_mode == 0x13) {
        int t1 = (int)(storage.pick.pick_info.x * (1.0f / 3.0f));
        int v1 = -t1 * 3;
        storage.pick.pick_info.x = 1.0f - (float)v1;

        int t2 = (int)(storage.pick.pick_info.y * (1.0f / 3.0f));
        int v2 = -t2 * 3;
        storage.pick.pick_info.y = 1.0f - (float)v2;

        brushSize = 3;
    } else {
        brushSize = rge_base_game->brush_size;
    }

    int cx = (int)storage.pick.pick_info.x;
    int cy = (int)storage.pick.pick_info.y;
    int half = (int)(signed short)brushSize >> 1;
    set_selection_area(cx - half, cy - half, cx + half, cy + half);
}
