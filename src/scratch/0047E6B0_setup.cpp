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
// - Remaining structural hunk is original EDI=list_info; rebuilt EAX=list_info,
//   EDI=offset, then add. It shifts the seven-byte loop suffix; no ABI or call
//   mismatch remains.

#include <stdlib.h>
#include <string.h>

class TPanel {
public:
    virtual ~TPanel() {}
    virtual void vf01() {}  virtual void vf02() {}  virtual void vf03() {}
    virtual void vf04() {}  virtual void vf05() {}  virtual void vf06() {}
    virtual void vf07() {}  virtual void vf08() {}  virtual void vf09() {}
    virtual void vf0A() {}  virtual void vf0B() {}  virtual void vf0C() {}
    virtual void vf0D() {}  virtual void vf0E() {}  virtual void vf0F() {}
    virtual void vf10() {}  virtual void vf11() {}  virtual void vf12() {}
    virtual void vf13() {}  virtual void vf14() {}  virtual void vf15() {}
    virtual void vf16() {}  virtual void vf17() {}  virtual void vf18() {}
    virtual void vf19() {}  virtual void vf1A() {}  virtual void vf1B() {}
    virtual void vf1C() {}  virtual void vf1D() {}  virtual void vf1E() {}
    virtual void vf1F() {}  virtual void vf20() {}  virtual void vf21() {}
    virtual void vf22() {}  virtual void vf23() {}  virtual void vf24() {}
    virtual void vf25() {}  virtual void vf26() {}  virtual void vf27() {}
    virtual void vf28() {}  virtual void vf29() {}  virtual void vf2A() {}
    virtual void vf2B() {}  virtual void vf2C() {}  virtual void vf2D() {}
    virtual void vf2E() {}  virtual void vf2F() {}  virtual void vf30() {}
    virtual void vf31() {}  virtual void vf32() {}  virtual void vf33() {}
    virtual void vf34() {}  virtual void vf35() {}  virtual void vf36() {}
    virtual void vf37() {}  virtual void vf38() {}  virtual void vf39() {}
    virtual void vf3A() {}  virtual void vf3B() {}  virtual void vf3C() {}
    virtual void vf3D() {}  virtual void vf3E() {}  virtual void vf3F() {}
    virtual void vf40() {}  virtual void vf41() {}  virtual void vf42() {}
    virtual void vf43() {}  virtual void vf44() {}  virtual void vf45() {}
    virtual void vf46() {}  virtual void vf47() {}  virtual void vf48() {}
    virtual void vf49() {}  virtual void vf4A() {}  virtual void vf4B() {}
    virtual void vf4C() {}  virtual void vf4D() {}

    char gap_04[0xD4];
    int error_code;                 // +0x0D8
    char gap_DC[0x18];
};

class TDialogPanel : public TPanel {
public:
    char gap_F4[0x384];
    void* dlg_wnd;                  // +0x478
    TPanel* save_parent_child;      // +0x47C
    int text_font_id;               // +0x480
    int input_font_id;              // +0x484
    int button_font_id;             // +0x488
    int button_sound_id;            // +0x48C
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

    long setup(TPanel* param_1, char* param_2, long param_3,
               long param_4, long param_5, long param_6, long param_7,
               long param_8, long param_9, char* param_10,
               long param_11, long param_12, long param_13, long param_14,
               char** param_15, short param_16, short param_17,
               long param_18, long param_19, long param_20, long param_21,
               long param_22);
};

class TScreenPanel : public TPanel {
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
    int length;
    i = 0;
    if (i < this->list_size) {
        offset = 0;
        while (i < this->list_size) {
            length = strlen(this->list_info->text + offset) + 1;
            this->list_text[i] = (char*)calloc((unsigned int)length, 1);
            if (this->list_text[i] == 0) {
                return 0;
            }
            strcpy(this->list_text[i], this->list_info->text + offset);
            ++i;
            offset += 0x66;
        }
    }

    long result = this->TListDialog::setup(
        screen, popup_file, popup_id,
        0x136, 0x190, 0x0A, 0x0A, 0x122,
        0x19, title, 0x0A, 0x2D, 0x122,
        0x131, this->list_text, this->list_size, this->list_line,
        0x0A, 0xA0, 0x168, 0x8C, 0x1E);

    return result != 0;
}
