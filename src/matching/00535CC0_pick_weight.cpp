// 00535CC0 pick_weight (view.cpp:2396-2440)
// PDB source: view.cpp (RGE_View::pick_weight)
//
// virtual int __thiscall RGE_View::pick_weight(RGE_Static_Object*, int)
// Returns: weight value (1-5, 0 = unselectable)
// ret 8 cleanup (2 params, thiscall)
//
// === Attempt log ===
// Baseline isolated source was structurally broad (198 differing bytes, 198-byte
// rebuilt body).  Reconstructing a separate select_level local, initialized before
// the touched-object test, recovered the original 211-byte size and the complete
// first 46-byte load/test block (probe 3).
// Probes 4-6: bool/initialized-result/local-declaration-order variants either
// regressed or were codegen duplicates.  A polymorphic TPanel/RGE_View surface and
// int/long result-width variants were also duplicates (probes 8-9).
// Probe 7: a named zero result was a duplicate, but is retained because the binary
// pre-zeroes EAX before the level dispatch and returns that zero on two arms.
// Probe 10: reversing the final case-2 equality to an explicit negative guard
// improved the isolated result to 207 bytes, 150 differing bytes, 88.57% shape,
// and 77.94% exact-block coverage.  The remaining first hunk is register coloring:
// rebuilt bVar1 is ECX while original is EDX; rebuilt dispatch value is EAX while
// original is ECX; original also hoists XOR EAX,EAX and keeps a branching case-2
// tail.  No calls, frame, or ABI/layout uncertainty remains.
// Fresh pass probe 1 rolled back: the natural nested level/predicate spelling
// restored the 211-byte size and improved positional diff to 139 bytes, but it
// changed the dispatch CFG to cmp/jne (72.46% shape, 57.35% blocks), farther
// from the original sub/dec/je dispatch than the switch basin.
// Fresh pass probe 2: the full proven TPanel/RGE_View and static-object surfaces
// were a codegen duplicate of the minimal shells; retained because ownership is
// more canonical, with no metric change.
// Fresh pass probe 3: next test mirrors the decompiler's proven source lifetime:
// save the object pointer, write the level through param_1 before the touched
// predicate, then use the saved pointer for the id comparison.
// Probe 3 rolled back: the explicit saved pointer forced an EBX save and a
// 211-byte/194-diff basin, so the compiler's existing parameter-home reuse is
// the better source reconstruction.
// Fresh pass probe 4: add the period RGE_View virtual surface (TPanel slots
// 0-47, view slots 48-55, pick_through_fog 56, pick_weight 57) without adding
// any function bodies, testing TU/vtable context rather than body control flow.
// Fresh pass probe 5: retain the saved object only for the proven id read, but
// express the observed byte write to the incoming parameter home directly.
// Probe 5 was a codegen duplicate of the clean 207-byte basin; the explicit
// byte-home form did not alter VC5's register family.
// Fresh pass probe 6: test a narrow register-qualified result local because the
// executable carries the predicate as a full-width EDX value across dispatch.
// Probe 6 was also a codegen duplicate; register qualification did not move the
// predicate from ECX or the level key from EAX.
// Fresh pass probe 7: move the proven zero result initialization to function
// entry, testing declaration/lifetime placement for the original pre-dispatch
// XOR EAX,EAX without retaining the duplicate raw alias experiment.
// Probe 7 was a codegen duplicate. The 108-variant fresh lab over level-home,
// zero-lifetime, and late predicate spellings produced eight nonexact groups;
// no exact or invariant-eligible variant was found. Final source below keeps
// the full proven layout/vtable context and natural nested predicates; remaining
// drift is the isolated VC5 register/dispatch basin (ECX/EAX vs EDX/ECX) plus
// the pre-dispatch zero/branch-tail topology.
// Main-agent normalization replaced the raw static-object vptr field with its
// canonical virtual destructor surface; emitted code is unchanged.
// Session normalization uses the canonical RGE_View, RGE_Static_Object, and
// RGE_Master_Static_Object names and a real unsigned-char level local; no
// parameter-home pointer alias remains.  The best natural source is retained
// below; remaining drift is the VC5 register/dispatch basin described above.
// Main-agent audit restored polymorphic master/panel ownership; the natural
// select-level switch remains authoritative.
// Matching-worker probe: mirrored the exact TRIBE_Main_View::pick_weight donor's
// int touched/result declaration and result-local fallthrough shape.  Cases 2
// and 3 assign the initialized result and return it after the switch, preserving
// the original shared zero tail.  This is a natural source form and matches all
// 211 bytes exactly.

// Fresh pass probe 2 uses the proven concrete RGE_View/TPanel and
// RGE_Static_Object data surfaces rather than the prior minimal helper shells.
struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char _gap_04[0x89];
    unsigned char select_level;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    char _gap_0C[0x7C];
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
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
    char _gap_04[0xF0];
};

class RGE_View : public TPanel {
public:
    char _gap_F4[0x33C - 0xF4];
    int UC_ObjectTouched;
    int UC_TouchedObj;
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object* param_1, int param_2);
};

int RGE_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    unsigned char select_level = param_1->master_obj->select_level;
    int touched;

    // Check touched state.
    if (this->UC_ObjectTouched && this->UC_TouchedObj == param_1->id)
        touched = 1;
    else
        touched = 0;

    int result = 0;

    // Switch on select_level (values 2,3,4 handled, default=1)
    switch ((int)(unsigned)select_level) {
        case 4:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2) return 4;
            if (param_2 == 3) return 3;
            return 2;
        case 3:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            break;
        case 2:
            if (touched) return 5;
            if (param_2 == 1 || param_2 == 2)
                result = 3;
            else if (param_2 == 3)
                result = 2;
            break;
        default:
            return 1;
    }

    return result;
}
