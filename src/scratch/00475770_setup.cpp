// VA: 00475770 TEditPanel::setup
// Source: pnl_edit.cpp lines 121-189
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: first pass - compilation issues with windows.h
// 2: clean version - 447 bytes match! 63.3% positional, 68.9% edit match
// 3: fix IAT calls + restructure style computation

#include <stdlib.h>

// IAT import thunks
extern "C" {
    void* (__stdcall* const CreateWindowExA)(int, const char*, const char*, int, int, int, int, int, void*, void*, void*, void*) = (void* (__stdcall*)(int, const char*, const char*, int, int, int, int, int, void*, void*, void*, void*))0x88A7F8;
    long (__stdcall* const SetWindowLongA)(void*, int, long) = (long (__stdcall*)(void*, int, long))0x88A8B8;
    long (__stdcall* const GetWindowLongA)(void*, int) = (long (__stdcall*)(void*, int))0x88A890;
    void* (__stdcall* const GetStockObject)(int) = (void* (__stdcall*)(int))0x88A5A4;
    long (__stdcall* const SendMessageA)(void*, unsigned int, unsigned int, long) = (long (__stdcall*)(void*, unsigned int, unsigned int, long))0x88A85C;
}

long pnl_sub_wnd_proc(void*, unsigned int, unsigned int, long);

class TDrawArea {
public:
    char gap_00[4];
    void* Wnd;         // +0x04
};

class TPanel {
public:
    char gap_00[0x20];
    void* padding_ptr;  // +0x20
    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, long p7);
};

class TEditPanel : public TPanel {
public:
    char gap_24[0xF4 - 0x24];
    void* edit_wnd;             // +0xF4
    short fixed_len;            // +0xF8
    char gap_FA[0xFC - 0xFA];
    char* text;                 // +0xFC
    int text_len;               // +0x100
    char gap_104[0x108 - 0x104];
    void* brush;                // +0x108
    char gap_10C[0x110 - 0x10C];
    void* old_sub_wnd_proc;     // +0x110
    int text_color1;            // +0x114
    int text_color2;            // +0x118
    int highlight_text_color1;  // +0x11C
    int highlight_text_color2;  // +0x120
    int back_color;             // +0x124
    int format;                 // +0x128
    void* font;                 // +0x12C
    char gap_130[0x144 - 0x130];
    int draw_format;            // +0x144
    int auto_sel;               // +0x148

    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, void* p7, short p8, char* p9, int p10, int p11);
    void set_text(char* txt);
};

long TEditPanel::setup(
    TDrawArea* param_1,
    TPanel* param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6,
    void* param_7,
    short param_8,
    char* param_9,
    int param_10,
    int param_11)
{
    long result;

    this->format = param_10;

    if (param_8 > 0) {
        param_8++;
    }
    this->fixed_len = param_8;

    this->font = param_7;
    this->auto_sel = param_11;

    result = TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0xFF);
    if (result == 0) {
        return 0;
    }

    // Get hInstance from vtable (needs padding_ptr loaded early)
    if (1) {
        void* hInst = *(void**)*(void**)this->padding_ptr;

        // Create edit window
        int styleVal = this->format - 7;
        if (styleVal) styleVal = -1;
        styleVal &= 0xFFE0003C;
        styleVal += 0x40200044;

        void* wnd = CreateWindowExA(
            0, "edit", 0,
            styleVal,
            param_3 + 1, param_4 + 1, param_5 - 2, param_6 - 2,
            param_1->Wnd, (void*)1,
            hInst,
            0
        );
        this->edit_wnd = wnd;
        if (wnd == 0) {
            return 0;
        }
    }

    // SetWindowLongA(edit_wnd, -0x15, this)
    SetWindowLongA(this->edit_wnd, -0x15, (long)(void*)this);

    // GetWindowLongA(edit_wnd, -4) -> old_sub_wnd_proc
    this->old_sub_wnd_proc = (void*)GetWindowLongA(this->edit_wnd, -4);

    // SetWindowLongA(edit_wnd, -4, pnl_sub_wnd_proc)
    SetWindowLongA(this->edit_wnd, -4, (long)(void*)pnl_sub_wnd_proc);

    // Allocate text buffer
    {
        char* textBuf = (char*)calloc(this->fixed_len + 2, 1);
        this->text = textBuf;
        if (textBuf == 0) {
            return 0;
        }
        *textBuf = 0;
    }

    this->text_len = 0;

    if (param_9 != 0 && *param_9 != 0) {
        this->set_text(param_9);
    }

    this->brush = GetStockObject(4);

    this->text_color1 = 0xFFFFFF;
    this->highlight_text_color1 = 0xFFFFFF;
    this->back_color = 0;
    this->text_color2 = 0;
    this->highlight_text_color2 = 0;

    if (this->font != 0) {
        SendMessageA(this->edit_wnd, 0x30, (unsigned int)this->font, 0);
    }

    // draw_format: 0x2000 then -(format != 7) & 0x10 + 0x2010
    this->draw_format = 0x2000;
    {
        int df2 = this->format - 7;
        if (df2) df2 = -1;
        df2 &= 0x10;
        df2 += 0x2010;
        this->draw_format = df2;
    }

    return 1;
}
