// VA: 00475970 TEditPanel::set_text
// pnl_edit.cpp

#include <string.h>

class TEditPanel {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void update(int);
    char gap_04[0xF0];
    int hwnd;
    short maxTextLen;
    char pad_FA[2];
    char* textBuffer;
    int textLength;
    char gap_104[0x48];
    int updateFlag;

    void set_text(char* text);
};

void __cdecl strncpy(char* dst, char* src, int n);
extern int (__stdcall *SetWindowTextA_ptr)(int, char*);
#pragma comment(linker, "/alternatename:_SetWindowTextA_ptr=__imp__SetWindowTextA@8")

void TEditPanel::set_text(char* text) {
    if (hwnd) {
        if (text) {
            memset(textBuffer, 0, (short)maxTextLen);
            strncpy(textBuffer, text, (short)maxTextLen - 1);
            textBuffer[(short)maxTextLen - 1] = 0;
            textLength = strlen(textBuffer);
        } else {
            textBuffer[0] = 0;
            textLength = 0;
        }
        SetWindowTextA_ptr(hwnd, textBuffer);
        updateFlag = 0;
    }
    update(1);
}
