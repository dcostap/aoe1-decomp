// VA: 00476A60 TEditPanel::is_blank (71B)
// PDB source: pnl_edit.cpp lines 987-1011
// tried decompiler-style scan, split early returns, and goto-style blank/not_blank tails
// closest shape matches update_text + text reload and most of the whitespace loop, but VC5 still drops the explicit pre-loop `cmp byte [esi],0` basin and prefers a tighter `mov al/test` loop-top with shifted blank/not-blank tails

typedef unsigned char uchar;
extern "C" int __cdecl __ismbcspace(unsigned int ch);
extern "C" uchar* __cdecl __mbsinc(const uchar* str);

class TEditPanel {
public:
    char gap_00[0xFC];
    char* currentLine;

    void update_text(void);
    int is_blank(void);
};

int TEditPanel::is_blank(void) {
    char* pcVar1;

    this->update_text();
    pcVar1 = this->currentLine;
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
