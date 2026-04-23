// tried the direct whitespace scan over currentLine with separate null/empty checks
// tried the decompiler-shaped for-loop spelling; mismatch stayed at the early currentLine/cmp-byte basin
// remaining gap is codegen-family drift around the first few branches, not the overall blank-check logic

typedef unsigned char uchar;
extern "C" int __cdecl __ismbcspace(unsigned int ch);
extern "C" uchar* __cdecl __mbsinc(const uchar* str);

class TTextPanel {
public:
    virtual ~TTextPanel();
    char* currentLine();
};

class TInputPanel : public TTextPanel {
public:
    int is_blank(void);
};

int TInputPanel::is_blank(void) {
    char* pcVar1 = this->currentLine();

    if ((pcVar1 != 0) && (*pcVar1 != '\0')) {
        for (; *pcVar1 != '\0'; pcVar1 = (char*)__mbsinc((const uchar*)pcVar1)) {
            if (__ismbcspace((unsigned char)*pcVar1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
