// VA: 0047E6B0 RGE_Dialog_List::setup
// PDB: rdlg_lst.cpp:45-91, 376 bytes
//
// Attempt log:
// - Prior scratch source had a duplicate list_text allocation and a decompiler
//   `init()` name for the vslot at +0x138; this reconstruction restores the
//   single allocation, typed list records, and the RGE_Dialog_List::create_list
//   virtual surface.
// - Baseline: canonical TPanel/TDialogPanel/TListDialog ownership with
//   strlen()+1 allocation and strcpy copy loop; calls/CFG matched, but the
//   compiler initialized the text offset before the positive-count branch
//   (383 rebuilt bytes, 230 positional diff).
// - Guarded natural while/for forms moved offset initialization after the
//   count test and were the best basin (383 bytes, 225 diff, 93.43% shape,
//   exact ordered call set). A nested do form peeled the first iteration and
//   added an extra calloc, so it was rolled back.
// - Parameter-home reuse, reversed pointer arithmetic, flat text-pointer
//   casts, and a strlen-only source alias all emitted the same code as the
//   guarded form. Remaining drift is the first scan's address/register order
//   and the resulting seven-byte loop/block displacement shift.
// - Fresh pass baseline from the exact rdlg_lst and panel donors reproduced the
//   prior 383-byte, 225-diff basin with all six ordered calls aligned.
// - A source pointer kept for both strlen and strcpy changed the prologue and
//   worsened the diff. It was rolled back.
// - A focused six-form natural loop lab, direct char overlay, reversed addition,
//   inline length, short-lived text alias, and indexed address spelling found no
//   closer emitted group. The direct typed form remains the clean source.
// - The oracle boolifies the TListDialog::setup(...) result. The natural
//   `!= 0` return improves block shape, but the first scan still adds four
//   bytes until its address and copy lowering is recovered.
// - Remaining structural hunk is original EDI=list_info; rebuilt EAX=list_info,
//   EDI=offset, then add. It shifts the seven-byte loop suffix; no ABI or call
//   mismatch remains.
// - Replaced the flattened vtable with the exact panel/list donor hierarchy and
//   corrected TScreenPanel's TEasy_Panel base; emitted code was unchanged, so
//   the natural typed hierarchy is retained.
// - Fresh bounded pass: dossier, same-TU donors, ABI evidence, and focused scan
//   donors confirm the typed record model. Zero-index record spelling, separate
//   cursors, typed aliases, explicit string declarations, and a post-allocation
//   source alias all duplicated the 376-byte basin. Restored the direct typed
//   source; the EDI versus EAX scan-base allocation remains the next lead.
// - New bounded block-shape pass: reversed pointer-add order, direct byte-base
//   casts, dead list_type parameter reuse, a diagnostic char-pointer field,
//   guarded do-loop form, register-qualified aliases, and inline strlen length
//   all duplicated the 376-byte basin. The char-pointer and do-loop forms were
//   diagnostic only and were removed. The clean typed source remains best.
// - Current bounded pass: short-lived and retained text/list-info aliases,
//   inline length, long locals, declaration-order changes, malloc-header and
//   intrinsic-pragmas context, a char-pointer list-info overlay, and reversed
//   update order all duplicated or worsened the 376-byte basin. The clean typed
//   source was restored. The unresolved hunk remains the original EDI=list_info
//   scan base versus rebuilt EAX=list_info followed by EDI=offset.
// - Latest claim probes kept typed class and record ownership. Indexed text
//   spelling and direct strlen-plus-one lowering were duplicates. A typed alias
//   worsened the frame. The final natural source keeps the oracle bool return.
// - Revisit probes for char-pointer and fixed-stride overlays, reversed and
//   indexed address forms, list_type offset reuse, and a combined allocation
//   guard all reproduced 380 bytes and 223 differing bytes. The pinned typed
//   source is restored; direct EDI scan-base allocation remains unresolved.
// - Claim probes confirmed the blocker source shape. Reversing the calloc
//   arguments produced the wrong push order and 222 differing bytes. Reversed
//   addition, named and split length locals, sizeof(char), explicit width
//   casts, a unit local, and equivalent arithmetic all reproduced the 380-byte
//   basin. The natural calloc(strlen(text) + 1, 1) source is restored.
// - Binary evidence: the target pushes 1 then the scanned length after the
//   first REPNE scan, so its C argument order is calloc(strlen(text) + 1, 1).
//   Exact donor 00472440 uses the same natural call but VC5 emits push 1 before
//   its scan. The remaining order is TU or expression-context sensitive; no
//   tested period-plausible form restores the target fault context.
// - Claim audit tested narrow and unsigned size types, custom int strlen
//   declarations, same-TU method declarations, Windows and ambient declaration
//   context, and reversible text-pointer forms. All kept the same basin or
//   worsened structure; none restored scan-before-push ordering.
// - Exact finish: declaration-only panel surfaces and a reference to the
//   list_info pointer member form one required group. Together, they emit the
//   exact 376-byte function. The scan completes before both calloc pushes. The
//   result publishes before its null test. The copy then reloads list_info.
// - Walkback: removing the member reference kept the prior 380-byte basin.
//   Restoring inline placeholder bodies while keeping the reference also kept
//   that basin. Both changes are required. Short length, helper, pointer-scope,
//   and pointer-reassignment probes were incidental or worse.

#include <stdlib.h>
#include <string.h>

class TPanel {
public:
    virtual ~TPanel();
    virtual void setup();
    virtual void set_rect_1();  virtual void set_rect_2();
    virtual void set_color();  virtual void set_active();
    virtual void set_positioning();  virtual void set_fixed_position();
    virtual void set_redraw();  virtual void set_overlapped_redraw();
    virtual void draw_setup();  virtual void draw_finish();
    virtual void draw();  virtual void draw_rect();
    virtual void draw_offset();  virtual void draw_rect2();
    virtual void draw_offset2();  virtual void paint();
    virtual void wnd_proc();  virtual void handle_idle();
    virtual void handle_size();  virtual void handle_paint();
    virtual void handle_key_down();  virtual void handle_char();
    virtual void handle_command();  virtual void handle_user_command();
    virtual void handle_timer_command();  virtual void handle_scroll();
    virtual void handle_mouse_down();  virtual void handle_mouse_move();
    virtual void handle_mouse_up();  virtual void handle_mouse_dbl_click();
    virtual void mouse_move_action();  virtual void mouse_left_down_action();
    virtual void mouse_left_hold_action();  virtual void mouse_left_move_action();
    virtual void mouse_left_up_action();  virtual void mouse_left_dbl_click_action();
    virtual void mouse_right_down_action();  virtual void mouse_right_hold_action();
    virtual void mouse_right_move_action();  virtual void mouse_right_up_action();
    virtual void mouse_right_dbl_click_action();  virtual void key_down_action();
    virtual void char_action();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void vfB8();  virtual void vfBC();  virtual void vfC0();
    virtual void vfC4();  virtual void vfC8();  virtual void vfCC();
    virtual void vfD0();  virtual void vfD4();  virtual void vfD8();
    virtual void vfDC();

    char gap_04[0xD4];
    int error_code;                 // +0x0D8
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, void**, long, long, long, long, long, long, long, long, long);
    virtual int create_button_text(TPanel*, void**, char*, char*, long, long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, void**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, void**, long, long, long, long, long, long);
    virtual int create_text_number(TPanel*, void**, int, long, long, long, long, long, int, int, int);
    virtual int create_text_list(TPanel*, void**, char**, long, long, long, long, long, long, int, int);
    virtual int create_text(TPanel*, void**, char*, long, long, long, long, long, int, int, int);
    virtual int create_input(TPanel*, void**, char*, short, long, long, long, long, long, long);
    virtual int create_edit(TPanel*, void**, char*, short, long, long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, void**, long, long, long, long, long, long, long);
    virtual int create_list(TPanel*, void**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, void**, TPanel*, long, long, long, long, long);
    virtual int create_auto_scrollbar(void**, TPanel*, long);
    virtual int create_vert_slider(TPanel*, void**, long, long, long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, void**, long, long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_F4[0x384];
    void* dlg_wnd;                  // +0x478
    TPanel* save_parent_child;      // +0x47C
    int text_font_id;               // +0x480
    int input_font_id;              // +0x484
    int button_font_id;             // +0x488
    int button_sound_id;            // +0x48C

    virtual int setup(TPanel*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TPanel*, TPanel*, long, long, char*, long, int);
};

class TListDialog : public TDialogPanel {
public:
    void* title;                    // +0x490
    void* list;                     // +0x494
    void* scroll_bar;               // +0x498
    void* ok_btn;                   // +0x49C
    void* cancel_btn;               // +0x4A0
    short list_id;                  // +0x4A4
    char gap_4A6[0x02];
    char* list_name;                // +0x4A8

    virtual short get_list_id();
    virtual char* get_list_name();

    long setup(TPanel* param_1, char* param_2, long param_3,
               long param_4, long param_5, long param_6, long param_7,
               long param_8, long param_9, char* param_10,
               long param_11, long param_12, long param_13, long param_14,
               char** param_15, short param_16, short param_17,
               long param_18, long param_19, long param_20, long param_21,
               long param_22);
};

class TScreenPanel : public TEasy_Panel {
};

struct rdlg_list_info {
    char text[100];
    short id;
};

class RGE_Dialog_List : public TListDialog {
public:
    int list_type;                  // +0x4AC
    short list_size;                // +0x4B0
    short list_line;                // +0x4B2
    rdlg_list_info* list_info;      // +0x4B4
    char** list_text;               // +0x4B8

    virtual int create_list();      // vslot +0x138
    void sort_list();
    void calc_list_line();

    int setup(TScreenPanel* screen, char* popup_file, long popup_id,
              int list_type, char* title);
};

void* __cdecl calloc(unsigned int count, unsigned int size);

int RGE_Dialog_List::setup(TScreenPanel* screen, char* popup_file,
                           long popup_id, int list_type, char* title)
{
    this->list_type = list_type;
    this->list_info = 0;
    this->list_text = 0;

    if (this->error_code != 0) {
        return 0;
    }

    if (this->create_list() == 0) {
        return 0;
    }

    this->sort_list();
    this->calc_list_line();

    this->list_text = (char**)calloc((unsigned int)this->list_size, 4);
    if (this->list_text == 0) {
        return 0;
    }

    int i;
    int offset;
    // BINARY NOTE: Keep this alias. It completes strlen before calloc setup and reloads list_info for strcpy.
    rdlg_list_info*& info = this->list_info;
    i = 0;
    if (i < this->list_size) {
        offset = 0;
        while (i < this->list_size) {
            this->list_text[i] = (char*)calloc(strlen(info->text + offset) + 1, 1);
            if (this->list_text[i] == 0) {
                return 0;
            }
            strcpy(this->list_text[i], info->text + offset);
            ++i;
            offset += 0x66;
        }
    }

    return this->TListDialog::setup(
        screen, popup_file, popup_id,
        0x136, 0x190, 0x0A, 0x0A, 0x122,
        0x19, title, 0x0A, 0x2D, 0x122,
        0x131, this->list_text, this->list_size, this->list_line,
        0x0A, 0xA0, 0x168, 0x8C, 0x1E) != 0;
}
