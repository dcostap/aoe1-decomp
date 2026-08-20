// VA 0053DEB0 RGE_Main_View::handle_keys
// vw_main.cpp:258-423
// Attempt log:
// 1: Natural source from packet/decompiler, local type surfaces and Win32 imports.
// 2: First natural /O2 build compiled but was 928 bytes vs original 964; broad behavior represented but too short for configured size.
// 3: Fixed foreground-window surface: original compares GetForegroundWindow() to `[this+20]+4`, so modeled host pointer at +0x20 with HWND at +0x04 instead of HWND directly at +0x20.
// 4: After host fix natural build was still short (944 bytes), indicating remaining source/codegen missing bulk rather than just offsets.
// 5: Added a volatile diagnostic pad block only to recover exact 964-byte size for comparison; it causes first mismatch at offset 2 and is intentionally documented as sizing/probe scaffolding, not a match path.
// 6: Probed /Ob0: no size/codegen improvement over default. Probed /Og- and /Od: both gave exact size but very broad 91.7012% positional diff from offset 0; flags removed.
// 7: Implemented pause/prog_mode/foreground/active early failure path and key_scrolling reset on failure.
// 8: Implemented selected-object movement mode for game_mode 0x12 using arrow key state bytes, object +0x38/+0x3c coordinates, prog_info +0x8d8 movement scalar, and virtual +0x34 move call.
// 9: Implemented map scrolling fallback: horz/vert short locals, debug_timeGetTime, key_scrolling/last_key_scroll_time, divisor quantization to 0/0.5/whole, max-distance clamp, set_view_loc calls, and repaint of main/map views.
// 10: Remaining blocker is broad stack/local/FPU topology mismatch. Original uses FPO `sub esp,118h` with keys at esp+28, horz/vert at esp+10/+14 and qword fild temp at +18; current C either compiles too short or needs artificial pad that shifts prologue and early layout.
// 11: No accepted_drift proposal: diff is broad and current exact-size build contains diagnostic volatile padding, while natural builds are size-short.
// 12: Clean-source reset removed the diagnostic pad; keep the typed key and scroll model as the baseline before import or guard probes.
// 13: Binary-backed import correction: Win32 foreground and keyboard-state calls use the period DLL-import surface, matching the two original indirect call sites.
// 14: Import correction aligned all 13 ordered calls and removed the target-count gap; remaining drift is frame/local topology and early block layout, not key-call identity.
// 15: A positive active-view block with the sibling scroll routine's short-circuit guard moved the first structural mismatch to the keyboard local and reduced the positional diff to 447 bytes.
// 16: The natural 256-byte direct keyboard buffer keeps source ownership clear but leaves the VC5 frame four bytes short; over-allocation and pointer-offset variants were diagnostic only and rolled back.
// 17: Explicit elapsed-time locals were optimized to the same x87 form; the remaining structural lead is VC5 local-home allocation, not call or behavior topology.
// 18: The proven unsigned key-scroll interval changes the frame to 0x114, emits the original qword/fidiv stack topology, and improves the diff to 446.
// 19: A named key-state pointer at keys+4 aligns all four keyboard tests and the API home; with a diagnostic 260-byte buffer it reaches diff 437 and 71.64% exact-block coverage.
// 20: The 260-byte buffer is allocation scaffolding, not canonical source; the normalized 256-byte alias source remains diff 438 with frame 0x114.
// 21: The remaining structural lead is a four-byte local-home shift: current shorts are at esp+14/+18 while the original uses esp+10/+14; all calls and key accesses align.
// 22: The original decompiler lists DAT_00577900/04/08.  Threshold externs
//     DAT_00577904/08 reduced the natural source to 964 bytes and diff 127,
//     with all 13 ordered calls and exact size.  Adding DAT_00577900 was neutral.
// 23: Canonical RGE class and TDrawArea ownership, typed selected-object fields,
//     direct key-array indexing, declaration-order changes, and ABI width changes
//     were codegen-neutral or worse.  Keep the canonical typed ownership.
// 24: A diagnostic 260-byte key array restored frame 0x118 and improved diff 124
//     with 71.64% exact-block coverage, but contradicts the proven 256-byte array.
//     It was rolled back.  The remaining blocker is the natural local-home shift.
// 25: Inline truncation, double/register accumulator, widened directions, direct
//     quotient forms, and local scope variants did not beat the threshold source.
// GIVEUP: left in scratch for future source-shape/stack-local topology work.
// BLOCKER: The executable frame is 0x118, while the natural 256-byte keyboard
// state array produces 0x114. A 260-byte array reaches the target frame but
// contradicts the proved GetKeyboardState buffer ownership. Do not pad it.

typedef unsigned char uchar;
typedef void* HWND;
extern "C" __declspec(dllimport) HWND __stdcall GetForegroundWindow(void);
extern "C" __declspec(dllimport) int __stdcall GetKeyboardState(uchar* keys);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    void* prog_info;
    char gap_10[0x1A0];
    int prog_mode;
    int game_mode;
    int get_paused();
};
extern RGE_Base_Game* rge_base_game;
extern const float DAT_00577900;
extern const float DAT_00577904;
extern const float DAT_00577908;

struct RGE_Prog_Info {
    char gap_00[0x8D0];
    unsigned long key_scroll_time_divisor;
    float key_scroll_max_dist;
    float key_scroll_object_move;
};

class RGE_Static_Object;

class RGE_Player {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void repaint(int);
    char gap_04[0x110];
    float view_x;
    float view_y;
    char gap_11C[0x14];
    RGE_Static_Object* selected_obj;
    void set_view_loc(float x, float y);
};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30();
    virtual float move_to(float x, float y, int zero);
    char gap_04[0x34];
    float x;
    float y;
};

class TDrawArea {
public:
    char gap[4];
    HWND Wnd;
};

class RGE_Main_View {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void repaint(int);
    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0x54];
    int active;
    char gap_7C[0x84];
    RGE_Player* player;
    char gap_104[0x25C];
    RGE_Main_View* map_view;
    char gap_364[0x10];
    unsigned long last_key_scroll_time;
    int key_scrolling;

    int handle_keys();
};

int RGE_Main_View::handle_keys()
{
    uchar keys[256];
    short horz_scroll;
    short vert_scroll;
    float scroll_dist2;
    int changed;
    RGE_Prog_Info* info;
    unsigned long now;
    unsigned long elapsed;

    if (rge_base_game->get_paused() == 0 &&
        (rge_base_game->prog_mode == 4 || rge_base_game->prog_mode == 6 ||
         rge_base_game->prog_mode == 7 || rge_base_game->prog_mode == 5) &&
        GetForegroundWindow() == this->render_area->Wnd && this->active != 0) {
        changed = 0;
        GetKeyboardState(keys + 4);
        horz_scroll = 0;
        vert_scroll = 0;

        info = (RGE_Prog_Info*)rge_base_game->prog_info;

    if (rge_base_game->game_mode == 0x12 && this->player != 0 && this->player->selected_obj != 0) {
        RGE_Static_Object* obj = this->player->selected_obj;
        if (keys[0x2A] > 1) {
            obj->move_to(obj->x + info->key_scroll_object_move, obj->y - info->key_scroll_object_move, 0);
            changed = 1;
        }
        if (keys[0x2C] > 1) {
            RGE_Static_Object* obj2 = this->player->selected_obj;
            obj2->move_to(obj->x - info->key_scroll_object_move, obj->y + info->key_scroll_object_move, 0);
            changed = 1;
        }
        if (keys[0x29] > 1) {
            RGE_Static_Object* obj2 = this->player->selected_obj;
            obj2->move_to(obj->x - info->key_scroll_object_move, obj->y - info->key_scroll_object_move, 0);
            changed = 1;
        }
        if (keys[0x2B] > 1) {
            RGE_Static_Object* obj2 = this->player->selected_obj;
            obj2->move_to(obj->x + info->key_scroll_object_move, obj->y + info->key_scroll_object_move, 0);
            changed = 1;
        }
    } else if (this->player != 0) {
        if (keys[0x29] > 1)
            horz_scroll = -1;
        else if (keys[0x2B] > 1)
            horz_scroll = 1;

        if (keys[0x2A] > 1)
            vert_scroll = -1;
        else if (keys[0x2C] > 1)
            vert_scroll = 1;

        if (horz_scroll != 0 || vert_scroll != 0) {
            now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x153);
            if (this->key_scrolling == 0) {
                scroll_dist2 = DAT_00577900;
                this->key_scrolling = 1;
            } else {
                elapsed = now - this->last_key_scroll_time;
                scroll_dist2 = (float)elapsed / info->key_scroll_time_divisor;
                long whole = (long)scroll_dist2;
                scroll_dist2 -= whole;
                if (scroll_dist2 < DAT_00577904) {
                    scroll_dist2 = 0.0f;
                    scroll_dist2 += (float)whole;
                } else {
                    scroll_dist2 = DAT_00577904;
                    scroll_dist2 += (float)whole;
                }
            }
            if (scroll_dist2 > info->key_scroll_max_dist)
                scroll_dist2 = info->key_scroll_max_dist;
            if (scroll_dist2 > DAT_00577908) {
                float scroll_dist = scroll_dist2 + scroll_dist2;
                if (horz_scroll == -1) {
                    this->player->set_view_loc(this->player->view_x - scroll_dist2, this->player->view_y - scroll_dist2);
                } else if (horz_scroll == 1) {
                    this->player->set_view_loc(this->player->view_x + scroll_dist2, this->player->view_y + scroll_dist2);
                }
                if (vert_scroll == -1) {
                    this->player->set_view_loc(this->player->view_x + scroll_dist, this->player->view_y - scroll_dist);
                } else if (vert_scroll == 1) {
                    this->player->set_view_loc(this->player->view_x - scroll_dist, this->player->view_y + scroll_dist);
                }
                this->last_key_scroll_time = now;
                changed = 1;
            }
        }
    }

    if (horz_scroll == 0 && vert_scroll == 0)
        this->key_scrolling = 0;
    if (changed) {
        this->repaint(1);
        if (this->map_view != 0)
            this->map_view->repaint(1);
    }
    return changed;
    }

fail:
    this->key_scrolling = 0;
    return 0;
}
