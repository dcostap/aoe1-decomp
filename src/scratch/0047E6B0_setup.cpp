// VA: 0047E6B0 RGE_Dialog_List::setup
// PDB: rdlg_lst.cpp:45-91, 376 bytes
// FLAGS: default
//
// Attempt log:
// - probe 1 (current): fix class layout, field offsets, loop structure,
//   virtual call for init() via proper vtable slot count,
//   direct calls for sort_list/calc_list_line, proper calloc decl,
//   correct register usage (ebx=this)

#include "..\..\include\game_globals.h"
#include <string.h>

// Base class from dlg_list.cpp (RGE_Dialog_List parent)
// Has many virtuals from TPanel chain; init() at vtable slot 78 (0x138)
class TListDialog {
public:
    virtual ~TListDialog() {}
    // 77 slots before init (indices 1-77)
    virtual void d01() {}  virtual void d02() {}  virtual void d03() {}
    virtual void d04() {}  virtual void d05() {}  virtual void d06() {}
    virtual void d07() {}  virtual void d08() {}  virtual void d09() {}
    virtual void d10() {}  virtual void d11() {}  virtual void d12() {}
    virtual void d13() {}  virtual void d14() {}  virtual void d15() {}
    virtual void d16() {}  virtual void d17() {}  virtual void d18() {}
    virtual void d19() {}  virtual void d20() {}  virtual void d21() {}
    virtual void d22() {}  virtual void d23() {}  virtual void d24() {}
    virtual void d25() {}  virtual void d26() {}  virtual void d27() {}
    virtual void d28() {}  virtual void d29() {}  virtual void d30() {}
    virtual void d31() {}  virtual void d32() {}  virtual void d33() {}
    virtual void d34() {}  virtual void d35() {}  virtual void d36() {}
    virtual void d37() {}  virtual void d38() {}  virtual void d39() {}
    virtual void d40() {}  virtual void d41() {}  virtual void d42() {}
    virtual void d43() {}  virtual void d44() {}  virtual void d45() {}
    virtual void d46() {}  virtual void d47() {}  virtual void d48() {}
    virtual void d49() {}  virtual void d50() {}  virtual void d51() {}
    virtual void d52() {}  virtual void d53() {}  virtual void d54() {}
    virtual void d55() {}  virtual void d56() {}  virtual void d57() {}
    virtual void d58() {}  virtual void d59() {}  virtual void d60() {}
    virtual void d61() {}  virtual void d62() {}  virtual void d63() {}
    virtual void d64() {}  virtual void d65() {}  virtual void d66() {}
    virtual void d67() {}  virtual void d68() {}  virtual void d69() {}
    virtual void d70() {}  virtual void d71() {}  virtual void d72() {}
    virtual void d73() {}  virtual void d74() {}  virtual void d75() {}
    virtual void d76() {}  virtual void d77() {}
    virtual int init();  // slot 78 = 0x138

    // Non-virtual base setup with many layout params
    long setup(void* param1, void* param2, void* param3,
               int a, int b, int c, int d, int e,
               int f, void* g, int h, int i, int j,
               int k, char** list, int size, int line,
               int m, int n, int o, int p, int q);
};

extern void* calloc(int count, int size);
extern void free(void*);

class RGE_Dialog_List : public TListDialog {
public:
    char gap_04[0xD4];
    int field_0D8;                     // +0x0D8
    char gap_DC[0x3D0];
    int list_type;                     // +0x4AC
    short list_size;                   // +0x4B0
    short list_line;                   // +0x4B2
    void* list_info;                   // +0x4B4
    char** list_text;                  // +0x4B8

    void sort_list();
    void calc_list_line();
    int setup(void* param1, void* param2, long param3, int param4, void* param5);
};

int RGE_Dialog_List::setup(void* param1, void* param2, long param3, int param4, void* param5)
{
    this->list_type = param4;
    this->list_info = 0;
    this->list_text = 0;

    if (this->field_0D8) {
        return 0;
    }

    if (!this->init()) {
        return 0;
    }

    this->sort_list();
    this->calc_list_line();

    this->list_text = (char**)calloc(this->list_size, 4);
    if (!this->list_text) {
        return 0;
    }

    this->list_text = (char**)calloc(this->list_size, 4);
    if (!this->list_text) {
        return 0;
    }

    {
        int i, off, len;
        for (i = 0, off = 0; i < this->list_size; off += 0x66, i++) {
            len = strlen((char*)this->list_info + off) + 1;
            this->list_text[i] = (char*)calloc(len, 1);
            if (!this->list_text[i])
                return 0;
            memcpy(this->list_text[i], (char*)this->list_info + off, len);
        }
    }

    long result = this->TListDialog::setup(
        param1, param2, (void*)param3,
        0x136, 0x190, 0x0A, 0x0A, 0x122,
        0x19, param5, 0x0A, 0x2D, 0x122,
        0x131, this->list_text, this->list_size, this->list_line,
        0x0A, 0xA0, 0x168, 0x8C, 0x1E);

    return (result != 0) ? 1 : 0;
}
