// VA: 00476A60 TEditPanel::is_blank (71B)
// PDB source: pnl_edit.cpp lines 987-1011
// Use the matched TInputPanel::is_blank source family: explicit pre-check and
// a while(1) scan. The canonical text field owns the +0xFC pointer.
// BINARY NOTE: Keep the separate pre-check and loop test. The executable reads
// text[0] twice before the first __ismbcspace call.

#include "../../include/pnl_edit_context.h"

typedef unsigned char uchar;
extern "C" int __cdecl __ismbcspace(int ch);
extern "C" uchar* __cdecl __mbsinc(const uchar* str);

int TEditPanel::is_blank(void) {
    char* pcVar1;

    this->update_text();
    pcVar1 = this->text;
    if (pcVar1 == 0) {
        goto blank;
    }
    if (*(unsigned char*)pcVar1 == 0) {
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
