// VA 0053E340 RGE_Main_View::mouse_left_down_action
// vw_main.cpp:461-630
// Attempt log:
// 1: Broad natural reconstruction from packet/decompiler, preserving main switch cases and call surfaces.
// 2: Modeled BaseGame paused/mode/submode gates, color_log entry/exit, switch on submode, and default capture_mouse path.
// 3: Implemented case 18 pick/select path with pick1 type 0x29, unselect/select_one_object, frame bounds, ClientToScreen/ScreenToClient, and command_action(4).
// 4: Implemented case 1 terrain/object placement path with pick1 type 0x28, fixup_pick_info, selected type lookup, object-list vf24, and player/view command dispatch.
// 5: Implemented command cases 9/10/19 and 2/3/17/21 with optional unselect/capture and command_action 9/3.
// 6: Implemented case 15 object-pick path: reject class 0x22, sprite/active draw-level selection, player switch, selected type/object/state, mouse mode, frame conversion, and command_action.
// 7: Initial PickInfo size was too large and BaseGame field offsets were wrong, producing sub esp,2C and mode offset +0x19C.
// 8: Reduced PickInfo to 16 bytes and fixed BaseGame padding so default frame is original sub esp,24 and mode/submode offsets +0x1B0/+0x1B4.
// 9: Default /O2 /Oy exact-size build compares but is broad: 904 bytes / 79.3679% positional, first mismatch offset 22. First drift is early-return layout: rebuilt emits inline paused/mode failure returns while original branches to shared false epilogue at the end.
// 10: Probed /O2 /Oy /Ob0: identical broad mismatch; removed flag.
// 11: Probed /Od: exact size but wrong basin from offset 0 (81.7384% positional); removed flag.
// 12: Probed /O2 /Oy /Og-: exact size but wrong basin from offset 0 (81.7384% positional); removed flag.
// GIVEUP: left in scratch. Main blockers are broad switch/source topology and early false-epilogue layout; no accepted_drift because mismatch is broad.

extern void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern int __stdcall ClientToScreen(void*, void*);
extern int __stdcall ScreenToClient(void*, void*);

struct POINT { int x; int y; };
struct PickInfo { int y; int tile; int scr_x; int scr_y; };
struct UnitType { char gap[0x10]; short type; char gap12[2]; short cls; };
struct Player { char gap[0x4A]; short civ; };
struct SpriteList { unsigned char get_lowest_draw_level(); };
struct Sprite { unsigned char get_lowest_draw_level(); };
struct StaticObj {
    void* vtbl; int id; UnitType* type; Player* player; int resource; Sprite* sprite; SpriteList* active; char gap1C[0x48-0x1C]; unsigned char state;
    void get_frame(short*, short*, short*, short*);
};
struct ObjectList { virtual void v0(); char gap[0x20]; virtual void vf24(short*, short*, void*, int); };
struct PlayerObj {
    void* vtbl; char gap4[0x20]; ObjectList** objects; char gap28[0x108]; void* fog;
    void unselect_object(); int select_one_object(StaticObj*, int);
    void vfB0(int idx, int sx, int sy, int zero);
};
struct ViewSub { void* vtbl; char gap04[0x40-4]; ObjectList** lists; void vfB0(int idx, int sx, int sy, int zero); };
struct BaseGame {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC();
    virtual void set_mouse_mode(int, int); virtual void set_player(short);
    char gap04[0x1B0-4]; int mode; int submode; char gap1B8[0x3FC-0x1B8]; short selectedType;
    int get_paused(); PlayerObj* get_player();
};
extern BaseGame* rge_base_game;

class RGE_Main_View {
public:
    void* vtbl; char gap04[0x20-4]; void** hwndPair; char gap24[0xFC-0x24]; void* viewObj; PlayerObj* player; char gap104[0x174-0x104]; StaticObj* selected; char gap178[0x37C-0x178]; PlayerObj* clickedPlayer;
    long mouse_left_down_action(long x, long y, short a, short b);
    unsigned char pick1(unsigned char, int, long, long, PickInfo*, void*, int);
    void fixup_pick_info(PickInfo*);
    void capture_mouse();
    void set_capture(int);
    void command_action(int, long, long, long, long);
};

long RGE_Main_View::mouse_left_down_action(long x, long y, short a, short b)
{
    short min_x, min_y, max_y, max_x;
    POINT pt;
    PickInfo pick;

    if (rge_base_game->get_paused()) return 0;
    int mode = rge_base_game->mode;
    if (!(mode == 4 || mode == 6 || mode == 7 || mode == 5)) return 0;
    int sub = rge_base_game->submode;
    color_log(0x4c, 0xba, 1);

    switch (sub) {
    case 18:
        if (pick1(0x29, 0, x, y, &pick, this->player->fog, 1) == 0x34) {
            this->player->unselect_object();
            this->player->select_one_object((StaticObj*)pick.tile, 1);
            set_capture(1);
            if (((StaticObj*)pick.tile)->resource) {
                ((StaticObj*)pick.tile)->get_frame(&min_x, &min_y, &max_y, &max_x);
                pt.x = max_y - min_y;
                pt.y = max_x - min_x;
                if (*(unsigned char*)(*(int*)this->hwndPair + 0x479) == 1) ClientToScreen(this->hwndPair[1], &pt);
                if (*(unsigned char*)(*(int*)this->hwndPair + 0x479) == 1) ScreenToClient(this->hwndPair[1], &pt);
                command_action(4, pt.x, pt.y, a, b);
            }
        }
        break;
    case 1:
        if (pick1(0x28, 0, x, y, &pick, 0, 1) == 0x33) {
            fixup_pick_info(&pick);
            int idx = rge_base_game->selectedType;
            if (idx != -1) {
                ObjectList* list = this->player->objects[idx];
                if (list) {
                    list->vf24((short*)&pick.scr_x, (short*)&pick.scr_x, this->viewObj, 0);
                    this->player->vfB0(idx, pick.scr_x, pick.scr_y, 0);
                } else {
                    ViewSub* subview = *(ViewSub**)((char*)this->viewObj + 0x40);
                    ObjectList* list2 = subview->lists[idx];
                    if (list2) {
                        list2->vf24((short*)&pick.scr_x, (short*)&pick.scr_x, this->viewObj, 0);
                        subview->vfB0(idx, pick.scr_x, pick.scr_y, 0);
                    }
                }
            }
        }
        break;
    case 9: case 10: case 19:
        if (this->player->fog) { this->player->unselect_object(); set_capture(1); }
        if (sub == 19) rge_base_game->set_mouse_mode(sub, 0);
        command_action(9, x, y, a, b);
        break;
    case 2: case 3: case 17: case 21:
        if (this->player->fog) { this->player->unselect_object(); set_capture(1); }
        command_action(3, x, y, a, b);
        break;
    case 15:
        if (pick1(0x29, 0, x, y, &pick, this->player->fog, 1) == 0x34) {
            StaticObj* obj = (StaticObj*)pick.tile;
            if (obj->type->cls != 0x22) {
                unsigned char level;
                if (obj->active) level = obj->active->get_lowest_draw_level();
                else if (obj->sprite) level = obj->sprite->get_lowest_draw_level();
                else level = 0x14;
                this->clickedPlayer = rge_base_game->get_player();
                rge_base_game->set_player(obj->player->civ);
                rge_base_game->selectedType = obj->type->type;
                this->selected = obj;
                obj->state = 7;
                if (!level) set_capture(2);
                rge_base_game->set_mouse_mode(8, 1);
                if (this->selected->resource) {
                    this->selected->get_frame(&min_x, &min_y, &max_y, &max_x);
                    pt.x = max_y - min_y; pt.y = max_x - min_x;
                    if (*(unsigned char*)(*(int*)this->hwndPair + 0x479) == 1) ClientToScreen(this->hwndPair[1], &pt);
                }
                command_action(9, x, y, sub, (short)x);
            }
        }
        break;
    default:
        capture_mouse();
        break;
    }
    color_log(0x4c, 0x5f, 1);
    return 1;
}
