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
