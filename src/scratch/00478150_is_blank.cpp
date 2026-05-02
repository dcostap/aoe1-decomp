// VA: 00478150 TInputPanel::is_blank (65B)
// PDB source: Pnl_inp.cpp lines 991-1013
// tried direct for-loop, explicit null/empty checks, and goto-style blank/not_blank tails
// best 65-byte shape matched the prologue/currentLine call and most of the loop, but still missed the exact early `cmp byte [esi],0` basin and either collapsed the return tail or overflowed to 64/65-byte boundary when forcing separate blank labels

typedef unsigned char uchar;
extern "C" int __cdecl __ismbcspace(unsigned int ch);
extern "C" uchar* __cdecl __mbsinc(const uchar* str);

class TTTextPanel {
public:
    virtual ~TTTextPanel();
    char* currentLine();
};

class TInputPanel : public TTTextPanel {
public:
    int is_blank(void);
};

int TInputPanel::is_blank(void) {
    char* pcVar1;

    pcVar1 = this->currentLine();
    if (pcVar1 == 0) {
        goto blank;
    }
    if (*pcVar1 == '\0') {
        goto blank;
    }
loop_top:
    if (*pcVar1 == '\0') {
        goto blank;
    }
    if (__ismbcspace((unsigned char)*pcVar1) == 0) {
        goto not_blank;
    }
    pcVar1 = (char*)__mbsinc((const uchar*)pcVar1);
    goto loop_top;

not_blank:
    return 0;
blank:
    return 1;
}
