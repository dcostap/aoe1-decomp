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
// Final retained reconstruction: typed TPanel/RGE_View/world/player/map and
// virtual pick helpers, natural casts/member calls, inline output stores. The
// remaining 602-byte drift is a broad local-home/frame basin (rebuilt frame
// 0xc versus original 0x8), plus the self-call relocation classification; no
// further blind source-shape lead remains in this bounded pass.
// Current validation: exact size, 602 strict differing bytes (61.3035%) and
// 404 edit-diff bytes (41.14%), with 13/13 ordered calls aligned except the
// self-call relocation classification. Frame remains 0xc versus original 0x8;
// no inline asm or accepted-drift proposal.

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
    byte owner;
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

byte RGE_Main_View::pick1(byte cmd, byte small, long x, long y, PickInfo* out, RGE_Static_Object* exclude, int alt)
{
    int count;
    RGE_Main_View* self = this;
    if (cmd == 0x29) {
        out->x = 0; out->y = 0; out->sx = 0; out->sy = 0; out->obj = 0; out->tile = 0;
        if (!small)
            count = self->pick_objects(x, y, 0, 40, 15, 4, 1);
        else
            count = self->pick_objects(x, y, 10, 20, 15, 4, 1);
        if (!count) return 0x32;
        if (!exclude) {
            RGE_Static_Object* best = 0;
            int bestScore = 0;
            short bestx = 0, besty = 0;
            for (int i = 0; i < count; ++i) {
                PickedInfo* p = &Picked_Objects[i];
                if (p->id >= 0) {
                    RGE_Static_Object* obj = self->world->objects[p->id];
                    if (obj && obj->owner < 7 && obj->master_obj->select_level >= small) {
                        if (alt || self->map->flag || self->pick_through_fog(obj) ||
                            self->player->visible->get_visible((int)obj->x, (int)obj->y) == 0x0f) {
                            int s = self->pick_weight(obj, p->confidence);
                            if (s > bestScore) {
                                bestx = self->render_rect.left + p->sx;
                                besty = self->render_rect.top + p->sy;
                                best = obj;
                                bestScore = s;
                            }
                        }
                    }
                }
            }
            if (!best) return 0x32;
            out->obj = best;
            out->sx = bestx;
            out->sy = besty;
            out->x = best->x;
            out->y = best->y;
            return 0x34;
        } else {
            int seenExclude = 0;
            RGE_Static_Object* chosen = 0;
            short cx = 0, cy = 0;
            for (int j = 0; j < count; ++j) {
                PickedInfo* p = &Picked_Objects[j];
                if (p->id >= 0) {
                    RGE_Static_Object* obj = self->world->objects[p->id];
                    if (obj && obj->owner < 7 && obj->master_obj->select_level >= small) {
                        int s = self->pick_weight(obj, p->confidence);
                        if (s > 0 && (alt || self->map->flag || self->pick_through_fog(obj) ||
                                      self->player->visible->get_visible((int)obj->x, (int)obj->y) == 0x0f)) {
                            if (obj == exclude) seenExclude = 1;
                            else if (!seenExclude) {
                                if (!chosen) { chosen = obj; cx = self->render_rect.left + p->sx; cy = self->render_rect.top + p->sy; }
                            } else {
                                chosen = obj; cx = self->render_rect.left + p->sx; cy = self->render_rect.top + p->sy; break;
                            }
                        }
                    }
                }
            }
            if (seenExclude && !chosen) {
                chosen = exclude;
                cx = self->render_rect.left + Picked_Objects[count].sx;
                cy = self->render_rect.top + Picked_Objects[count].sy;
            }
            if (!chosen) return 0x32;
            out->obj = chosen;
            out->sx = cx;
            out->sy = cy;
            out->x = chosen->x;
            out->y = chosen->y;
            return 0x34;
        }
    }
    if (cmd == 0x2a) {
        if (self->pick1(0x29, small, x, y, out, exclude, 1) == 0x34) return 0x34;
    }
    return self->pick(0x28, small, x, y, out, exclude);
}
