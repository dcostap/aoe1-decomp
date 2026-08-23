// 00535A80 RGE_View::pick_multi (view.cpp:2306-2370)
// Attempt log:
// 1: Natural decompiler-shaped implementation: 86.46% diff; RGE_Static_Object fields were 4 bytes early and parameter/register allocation differed.
// 2: Add object vptr pad fixed object_state/master offsets; diff still broad, first mismatch register allocation for params/count.
// 3: Register loop index/named coordinate locals made no codegen change.
// 4: Mutating x2/y2 into deltas made no codegen change.
// 5: Pointer-before-index swapped init order slightly but still wrong registers.
// 6: Register count did not change allocation.
// 7: Negated dy spelling no change.
// 8: Hoisting loop index before pick call improved to 40% positional / 21.6% edit and restored xor ESI/count EBP.
// 9: Register y1 local did not change EBX (still y2).
// 10: Volatile y2 worsened to 87.68% and first mismatch offset 1; rolled back.
// 11: Used the incoming y1 parameter directly in both rectangle calls, matching the packet's direct y1 home reloads; VC5 emitted the same 495-byte code.
// 12: Spelled the first direct selection block as an early failure break followed by picked_any=1; testing the call before the assignment was a natural source-order lead.
// 13: Replaced raw int pick-record access with a typed RGE_Pick_Obj_Info pointer and named confidence field; VC5 was a codegen duplicate.
// 14: Declared the y delta before the x delta to test y1/EBX liveness coloring; diff worsened by 5 bytes, so restored x delta first.
// 15: Reused y1 as the second-pass count and x2 as the selected-object home; this matched the observed parameter writes but was a codegen duplicate, so restored named locals.
// 16: Carried y2 through a named local across both passes; VC5 was a codegen duplicate.
// 17: Removed register qualifiers from count and loop index; both were codegen duplicates, and the natural unqualified locals remain.
// 18: Used a positive second-pass do-while predicate; rebuilt size grew to 501 bytes and strict diff to 276, so restored count != 0.
// 19: A separate remaining count, initialized after the second cursor setup,
// recovered the original second-pass stack-home and reduced the diff to 40.
// 20: Reusing y1 for the second result, and moving remaining before the score,
// were duplicates or regressions. The separate remaining form remains best.
// 21: Split delta declarations were a duplicate. dx >= dy reduced the diff to
// 39. An explicit sub-50 if/else grew the body to 497 bytes and was restored.
// 22: Restored the canonical TPanel base surface. VC5 emitted a duplicate.
// 23: A 4x4 call/coordinate variant lab and a 32-sample ambient-context lab
// emitted one 495-byte group. No alias, delta, or ambient form moved bytes.
// Bounded session probes: exact-source ABI correction fixed the two helper
// relocations but did not move bytes; parameter-home reuse, declaration-order,
// natural delta, header-context, and focused score-lifetime variants were
// codegen duplicates or regressed size. The retained source below is the
// simplest typed reconstruction: the PDB-proven picked_obj local is function
// scoped, while the score/count remain ordinary locals.
// Current pass: the retained typed source builds to 495 bytes with 9 aligned
// calls and no frame/EH. The best strict diff is 39 bytes (7.8788%), first
// mismatch +0x0e.
// Direct y1/x2 parameter-home reuse, a split 56-slot TPanel surface, coordinate
// aliases, and register-qualified locals were codegen duplicates. A bool flag,
// declaration-site pointer initialization, and explicit radius arms regressed.
// Left in scratch: rebuilt size/calls/frame match, with exact first-pass and
// later loop islands. The first mismatch remains the initial y-coordinate load:
// original keeps y1 in EBX, while rebuilt keeps y2. The radius block also uses
// a different coordinate register map. No policy-valid exact source was found.
// Current claim probes:
// 24: Replaced unnamed virtual slots and flat overlays with the period
//     RGE_View/TPanel, player, object, master, and world surfaces. Renamed the
//     virtual calls to pick_through_fog and pick_weight. The 495-byte,
//     39-byte-diff output was unchanged.
// 25: Made the Picked_Objects cursor function scoped. Codegen was unchanged.
// 26: Initialized that cursor at function entry to follow its earlier PDB
//     declaration. This moved the load before the helper call and regressed
//     to a 382-byte diff; it was restored.
// 27: Reordered the first-pass declarations. Codegen was unchanged.
// 28: Reused dead rectangle parameters for the second-pass count and selected
//     object. This reached 51 bytes and was restored.
// 29: Reversed the natural selected-object and score zero stores. This reached
//     the current 37-byte frontier and remains in the source.
// 30: Reused y1 only for the second-pass count. This reached 52 bytes and was
//     restored.
// 31: Added one natural y1 copy for the helper and delta. Codegen was a
//     duplicate of the 37-byte frontier.
// 32: Joined dx/dy declarations with their assignments. Codegen was unchanged.
// 33: Removed the repeated radius assignment. This made 493 bytes and 312
//     differing bytes, so it was restored.
// 34: Made the inner radius choice an explicit if/else. This made 497 bytes
//     and 309 differing bytes, so it was restored.
// 35: Moved the remaining-count declaration to function scope. Codegen was a
//     duplicate of the 37-byte frontier, so it was restored.
// 36: Added the full reviewed RGE_View size surface. Codegen was unchanged,
//     so the local class surface was restored.
// 37: Reused y1 as the second-pass result. This made 495 bytes and 211
//     differing bytes, so it was restored.
// 38: Mutated x2 and y2 into the coordinate deltas. This made 495 bytes and
//     56 differing bytes, so it was restored.
// 39: Staged the coordinate delta assignments. The live translation-unit
//     config changed during the check, so the source was restored before a
//     result was recorded.
// 40: Made the coordinate delta and radius locals long. Codegen was a
//     duplicate of the 37-byte frontier; the widths match the PDB/decompiler
//     long coordinate evidence.
// BINARY NOTE: The original stores the second-pass count in the y1 home and
// the selected object in the x2 home. The natural local form stores the count
// in the y2 home while preserving the selected-object home.
// BINARY NOTE: Fresh checks keep exact calls, x87 conversion order, object and
// player rereads, the 495-byte boundary, and the RGE_View owner symbol.
// BLOCKED: The target is not an owner in config/translation_units.json. A
// shared view.cpp wrapper would need a config owner and shared-header changes.
// Both changes are outside this task. The exact view anchors remain untouched.
// ACCEPTED DRIFT: The changed regions use different registers for x1, y1, x2,
// y2, dx, dy, and the second-pass counter. Both builds push identical helper
// arguments, compute the same wrapped coordinate differences and radius, and
// visit objects in the same order. Reordered reads are parameter or private
// stack reads. Calls, used flags, memory effects, returns, and fault behavior
// match.

struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

extern RGE_Pick_Obj_Info Picked_Objects[];

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x89];
    unsigned char select_level; // +0x8d
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

struct RGE_Static_Object;

struct RGE_Player {
    virtual ~RGE_Player();
    char gap_04[0x34];
    RGE_Visible_Map* visible; // +0x38
    char gap_3c[0x0e];
    short id; // +0x4a
    int select_one_object(RGE_Static_Object*, int);
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner; // +0x0c
    char gap_10[0x28];
    float x; // +0x38
    float y; // +0x3c
    char gap_40[8];
    unsigned char object_state; // +0x48
};

struct RGE_World {
    virtual ~RGE_World();
    char gap_04[0x84];
    RGE_Static_Object** objectsValue; // +0x88
};

class RGE_Map {
public:
    char gap_00[0x8db8];
    unsigned char map_visible_flag; // +0x8db8
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(void*);
    virtual int is_inside(long, long);
    char gap_04[0xf0];
};

class RGE_View : public TPanel {
public:
    void* cur_render_area; // +0xf4
    int calc_draw_count; // +0xf8
    RGE_World* world; // +0xfc
    RGE_Player* player; // +0x100
    RGE_Map* map; // +0x104
    char gap_108[0x5c];

    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int picked_index);

    unsigned char pick_multi(unsigned char p1, long x1, long y1, long x2, long y2);
protected:
    int pick_multi_objects(int x1, int y1, int x2, int y2,
                           int a, int b, int player, unsigned char p1, int flag);
    int pick_objects(int x, int y, int a, int b, int radius, int c, int d);
};

unsigned char RGE_View::pick_multi(unsigned char p1, long x1, long y1, long x2, long y2)
{
    RGE_Pick_Obj_Info* pp;
    int i = 0;
    int picked_any = 0;
    int count;
    RGE_Static_Object* picked_obj;
    count = this->pick_multi_objects(x1, y1, x2, y2, 10, 20, this->player->id, p1, 1);
    if (count > 0) {
        pp = Picked_Objects;
        do {
            int idx = pp->object_id;
            if (idx != -1) {
                RGE_Static_Object* obj = this->world->objectsValue[idx];
                if (obj != 0 && obj->object_state < 7) {
                    if (!this->player->select_one_object(obj,0)) break;
                    picked_any = 1;
                }
            }
            i++;
            ++pp;
        } while (i < count);
    }
    if (picked_any) return 1;

    long dx = x2 - x1;
    long dy = y2 - y1;
    long r = dx;
    if (dx >= dy) r = dy;
    if (r < 50) {
        r = dy;
        if (dx < dy) r = dx;
    } else r = 50;

    count = this->pick_objects(x1 + dx/2, y1 + dy/2, 10, 20, r, 4, 1);
    if (count) {
        picked_obj = 0;
        int bestScore = 0;
        int remaining;
        if (count > 0) {
            pp = Picked_Objects;
            remaining = count;
            do {
                int idx = pp->object_id;
                if (idx >= 0) {
                    RGE_Static_Object* obj = this->world->objectsValue[idx];
                    if (obj && obj->object_state < 7 && obj->master_obj->select_level >= 2) {
                        if (!this->map->map_visible_flag && !this->pick_through_fog(obj)) {
                            int vy = (int)obj->y;
                            int vx = (int)obj->x;
                            if (this->player->visible->get_visible(vx, vy) != 0x0f) goto next;
                        }
                        int score = this->pick_weight(obj, pp->confidence);
                        if (obj->owner == this->player) score += 5;
                        if (score > bestScore) { picked_obj = obj; bestScore = score; }
                    }
                }
next:
                ++pp;
                remaining--;
            } while (remaining != 0);
        }
        if (picked_obj && this->player->select_one_object(picked_obj,0)) return 1;
    }
    return 0;
}
