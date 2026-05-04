// VA: 00476A60 TEditPanel::is_blank (71B)
// PDB source: pnl_edit.cpp lines 987-1011
// retry using the matched TInputPanel::is_blank source family exactly: volatile pre-check + while(1) scan

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
    if (*(volatile unsigned char*)pcVar1 == 0) {
        goto blank;
    }
    while (1) {
        if (*pcVar1 == '\0') {
            goto blank;
        }
        if (__ismbcspace((unsigned char)*pcVar1) == 0) {
            return 0;
        }
        pcVar1 = (char*)__mbsinc((const uchar*)pcVar1);
    }

blank:
    return 1;
}
