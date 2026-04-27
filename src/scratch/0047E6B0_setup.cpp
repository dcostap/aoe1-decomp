// RGE_Dialog_List::setup
// VA: 0047E6B0
// PDB: rdlg_lst.cpp:45-91

// Sibling: ~RGE_Dialog_List (0047E830, MATCHED)

#include "..\..\include\game_globals.h"
#include <string.h>

class TListDialog {
public:
    virtual ~TListDialog();
    virtual void d1();  virtual void d2();  virtual void d3();
    virtual void d4();  virtual void d5();  virtual void d6();
    virtual void d7();  virtual void d8();  virtual void d9();
    virtual void d10(); virtual void d11(); virtual void d12();
    virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18();
    virtual void d19(); virtual void d20(); virtual void d21();
    virtual void d22(); virtual void d23(); virtual void d24();
    virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30();
    virtual void d31(); virtual void d32(); virtual void d33();
    virtual void d34(); virtual void d35(); virtual void d36();
    virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42();
    virtual void d43(); virtual void d44(); virtual void d45();
    virtual void d46(); virtual void d47(); virtual void d48();
    virtual void d49(); virtual void d50(); virtual void d51();
    virtual void d52(); virtual void d53(); virtual void d54();
    virtual void d55(); virtual void d56(); virtual void d57();
    virtual void d58(); virtual void d59(); virtual void d60();
    virtual void d61(); virtual void d62(); virtual void d63();
    virtual void d64(); virtual void d65(); virtual void d66();
    virtual void d67(); virtual void d68(); virtual void d69();
    virtual void d70(); virtual void d71(); virtual void d72();
    virtual void d73(); virtual void d74(); virtual void d75();
    virtual void d76(); virtual void d77();
    virtual int init();  // slot 78 = vtable+0x138
    virtual long setup(void* a, long b, void* c,
        int a0, int a1, int a2, int a3, int a4,
        int a5, void* a6, int a7, int a8, int a9,
        int a10, char** a11, int a12, int a13, int a14,
        int a15, int a16, int a17, int a18);
};

class rdlg_list_info {
public:
    char text[0x64];
    short id;
};

class RGE_Dialog_List : public TListDialog {
public:
    char gap_04[0xD4];
    int field_0D8;
    char gap_DC[0x3D0];
    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info* list_info;
    char** list_text;

    int setup(void* param_1, void* param_2, long param_3, int param_4, void* param_5);
};

int RGE_Dialog_List::setup(void* param_1, void* param_2, long param_3, int param_4, void* param_5)
{
    int i;
    int off;
    int len;
    char* src;
    char* dst;

    this->list_type = param_4;

    if (this->field_0D8)
        return 0;

    this->list_info = 0;
    this->list_text = 0;

    if (!this->init())
        return 0;

    {
        extern void sort_list(void*);
        extern void calc_list_line(void*);
        sort_list(this);
        calc_list_line(this);
    }

    this->list_text = (char**)calloc(this->list_size, 4);
    if (!this->list_text)
        return 0;

    for (i = 0; i < this->list_size; i++) {
        off = i * 0x66;
        src = (char*)this->list_info + off;
        len = strlen(src) + 1;
        dst = (char*)calloc(len, 1);
        this->list_text[i] = dst;
        if (!dst)
            return 0;
        memcpy(dst, src, len);
    }

    long result = this->TListDialog::setup(
        param_1, param_3, param_2,
        0x136, 0x190, 10, 10, 0x122,
        0x19, param_5, 10, 0x2D, 0x122,
        0x131, this->list_text, this->list_size, this->list_line,
        10, 0xA0, 0x168, 0x8C, 0x1E);

    return (result != 0) ? 1 : 0;
}
