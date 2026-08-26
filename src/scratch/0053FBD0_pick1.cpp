// 0053FBD0 RGE_Main_View::pick1
// Attempt log:
// try 1: packet-grounded reconstruction using vw_main pick family context. Models 0x29 pick path, output zeroing, pick_objects radius variants, no-exclude best scan, exclude-object alternate scan, output fill, 0x2a recursive wrapper, and fallback pick_multi call.
// try 2: fixed Picked_Objects entry stride/fields and helper declaration; reached exact configured size 982.
// try 3: first 0x60 bytes nearly match: parameter byte test, 0x29 branch, out struct zeroing, and pick_objects argument variants are in the right basin.
// try 4: modeled no-exclude best-object scan over Picked_Objects, player object array at +0xfc/+88, owner < 7, master byte +0x8d >= small.
// try 5: modeled optional terrain/path filter: alt param, terrain flag +0x8db8, virtual can_pick at vtable +0xe0, tile helper returning 0x0f.
// try 6: modeled score_pick virtual at +0xe4 and best-score update with view offsets +0x8c/+0x90 plus picked dx/dy.
// try 7: modeled exclude-object path with seen-exclude flag and alternate selection, including fallback to last picked entry.
// try 8: modeled output fill fields: world x/y from object +0x38/+0x3c, screen shorts, object pointer, and 0x34/0x32 return codes.
// try 9: modeled 0x2a wrapper that retries as 0x29 with alt=1 and returns early on 0x34.
// try 10: tried casting float positions directly to int for tile helper instead of ftol calls; worsened to 78.5132% positional / 111.6090% edit, rolled back.
// try 11: restored the vw_main/view ABI surface: pick_through_fog and pick_weight
// are RGE_View virtuals at +0xe0/+0xe4, get_visible is the direct two-argument
// RGE_Visible_Map member, and output stores are inline rather than a helper call.
// try 12: corrected get_visible to the natural (int)x,(int)y source order so
// VC5 emits the two right-to-left __ftol conversions without explicit cdecl calls.
// This fixed the call set and reduced the strict diff to 602 bytes at exact size.
// try 13: restored TPanel::render_rect ownership for the +0x8c/+0x90 screen
// offsets; this is codegen-neutral to the prior short-field stub but is the
// canonical period layout. The fallback now preserves the oracle's proven
// `chosen = exclude` behavior and uses the count-indexed picked screen pair.
// try 14: removed the redundant `self` alias and used direct `this` member
// calls throughout. Emitted code was unchanged; the wrapper call remains the
// natural recursive `pick1` call, while the checker labels the oracle target
// as internal+0x0 because it is the function entry.
// try 15: qualified the recursive call as `RGE_Main_View::pick1`. Emitted code
// was unchanged and the source was restored to the ordinary unqualified
// member-call spelling.
// Final retained reconstruction: typed TPanel/RGE_View/world/player/map and
// virtual pick helpers, natural casts/member calls, inline output stores. The
// remaining 602-byte drift is a broad local-home/frame basin (rebuilt frame
// 0xc versus original 0x8), plus the self-call relocation classification; no
// further blind source-shape lead remains in this bounded pass.
// Current validation: exact size, 602 strict differing bytes (61.3035%) and
// 404 edit-diff bytes (41.14%), with 13/13 ordered calls aligned except the
// self-call relocation classification. Frame remains 0xc versus original 0x8;
// no inline asm or accepted-drift proposal.
// try 16: shared selected-object and screen-pair ownership across both 0x29
// branches reduced the frame to 0x8 but worsened the strict diff to 896 bytes;
// rolled back to the clean branch-local reconstruction.
// try 17: express successful output as the positive selected-object branch,
// matching the oracle's `cmp selected,0; je return32` block shape.
// try 18: an absolute Picked_Objects address was rejected; it changed the
// relocation basin and worsened the strict diff.
// try 19: moving PickedInfo cursors recovered the oracle's 12-byte cursor
// updates and improved the strict diff from 566 to 559 bytes.
// try 20: split screen declarations were a codegen duplicate.
// tries 21-23: biased cursors, explicit while scans, and shared screen pairs
// worsened code or shape; restored typed branch-local forms.
// try 24: direct this calls, y reused for the post-pick count, and x reused
// for the no-exclude score reached 547 strict differing bytes and 74.36%
// shape similarity. This is the best clean unresolved source.
// BINARY NOTE: the oracle walks Picked_Objects with a 12-byte moving cursor.
// BINARY NOTE: the oracle reuses dead coordinate parameter homes for the
// post-pick count and no-exclude score after pick_objects returns.
// Open: the oracle has an 8-byte local frame; this source remains at 0xC.
// Worker pass 2026-08-22: tested a y-mutating no-exclude countdown, an explicit
// target_count local, indexed and loop-local PickedInfo cursors, screen
// assignment order, bool and register-qualified flags/shorts, outer-guard
// inversion, nested visibility checks, shared cursor scope, and declaration
// order. The best unchanged natural source remains 547 strict differing bytes
// at exact size with 74.36% shape similarity. These variants did not recover
// the original 8-byte frame or its BP/BX exclude-screen register pair.
// Open: source-level cause of the remaining local-home rotation is unknown.
// TU pass: using owner_type restores the proven +48h field without a source
// fork. A grouped-only render-rectangle view reduced the diff to 548 bytes,
// but it was rejected. The shared RGE_View layout needs a reviewed +8Ch field.

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
typedef unsigned char byte;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};


struct RGE_Tile;

struct PickInfo {
    float x;
    float y;
    short sx;
    short sy;
    void* obj;
    RGE_Tile* tile;
};

struct PickedInfo {
    int id;
    short confidence;
    short draw_level;
    short sx;
    short sy;
};
extern PickedInfo Picked_Objects[];

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap04[0x89];
    byte select_level;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap0c[0x2c];
    float x;
    float y;
    char gap40[8];
    union { byte owner; byte owner_id; byte owner_type; };
};

class RGE_Visible_Map {
public:
    byte get_visible(int x, int y);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap04[0x34];
    RGE_Visible_Map* visible;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap04[0x84];
    RGE_Static_Object** objects;
};

class RGE_Map { public: char gap00[0x8db8]; byte flag; };

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup(void*, TPanel*, long, long, long, long, byte);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(byte);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual long handle_mouse_down(byte, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(byte, long, long, int, int);
    virtual long handle_mouse_dbl_click(byte, long, long, int, int);
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
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual byte get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap04[0x84];
    void* clip_rgn;
    tagRECT render_rect;
    char gap9c[0x58];
};

class RGE_View : public TPanel {
public:
    char gapf4[8];
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;

    virtual int pick_through_fog(RGE_Static_Object* object);
    virtual int pick_weight(RGE_Static_Object* object, int confidence);

    int pick_objects(int x, int y, int a, int b, int radius, int c, int d);
    byte pick(byte command, byte mode, long x, long y, PickInfo* out,
              RGE_Static_Object* exclude);
};

class RGE_Main_View : public RGE_View {
public:
    byte pick1(byte cmd, byte small, long x, long y, PickInfo* out, RGE_Static_Object* exclude, int alt);
};
#endif

#ifdef RGE_MAIN_VIEW_SHARED_CONTEXT
typedef RGE_Pick_Info PickInfo;
#endif

byte RGE_Main_View::pick1(byte cmd, byte small, long x, long y, PickInfo* out, RGE_Static_Object* exclude, int alt)
{
    if (cmd == 0x29) {
        out->x = 0; out->y = 0; out->sx = 0; out->sy = 0; out->obj = 0; out->tile = 0;
        if (!small)
            y = this->pick_objects(x, y, 0, 40, 15, 4, 1);
        else
            y = this->pick_objects(x, y, 10, 20, 15, 4, 1);
        if (!y) return 0x32;
        if (!exclude) {
            RGE_Static_Object* best = 0;
            short bestx = 0, besty = 0;
            x = 0;
            PickedInfo* p = Picked_Objects;
            for (int i = 0; i < y; ++i, ++p) {
                if (p->id >= 0) {
                    RGE_Static_Object* obj = this->world->objects[p->id];
                    if (obj && obj->owner_type < 7 && obj->master_obj->select_level >= small) {
                        if (alt || this->map->flag || this->pick_through_fog(obj) ||
                            this->player->visible->get_visible((int)obj->x, (int)obj->y) == 0x0f) {
                            int s = this->pick_weight(obj, p->confidence);
                            if (s > x) {
                                bestx = this->render_rect.left + p->sx;
                                besty = this->render_rect.top + p->sy;
                                best = obj;
                                x = s;
                            }
                        }
                    }
                }
            }
            if (best) {
                out->obj = best;
                out->sx = bestx;
                out->sy = besty;
                out->x = best->x;
                out->y = best->y;
                return 0x34;
            }
            return 0x32;
        } else {
            int seenExclude = 0;
            RGE_Static_Object* chosen = 0;
            short cx = 0;
            short cy = 0;
            PickedInfo* p = Picked_Objects;
            for (int j = 0; j < y; ++j, ++p) {
                if (p->id >= 0) {
                    RGE_Static_Object* obj = this->world->objects[p->id];
                    if (obj && obj->owner_type < 7 && obj->master_obj->select_level >= small) {
                        int s = this->pick_weight(obj, p->confidence);
                        if (s > 0 && (alt || this->map->flag || this->pick_through_fog(obj) ||
                                      this->player->visible->get_visible((int)obj->x, (int)obj->y) == 0x0f)) {
                            if (obj == exclude) seenExclude = 1;
                            else if (!seenExclude) {
                                if (!chosen) { chosen = obj; cx = this->render_rect.left + p->sx; cy = this->render_rect.top + p->sy; }
                            } else {
                                chosen = obj; cx = this->render_rect.left + p->sx; cy = this->render_rect.top + p->sy; break;
                            }
                        }
                    }
                }
            }
            if (seenExclude && !chosen) {
                chosen = exclude;
                cx = this->render_rect.left + Picked_Objects[y].sx;
                cy = this->render_rect.top + Picked_Objects[y].sy;
            }
            if (chosen) {
                out->obj = chosen;
                out->sx = cx;
                out->sy = cy;
                out->x = chosen->x;
                out->y = chosen->y;
                return 0x34;
            }
            return 0x32;
        }
    }
    if (cmd == 0x2a) {
        if (pick1(0x29, small, x, y, out, exclude, 1) == 0x34) return 0x34;
    }
    return this->pick(0x28, small, x, y, out, exclude);
}
