// first pass: update the edit text, then scan currentLine for any non-space multibyte char
// tried the decompiler-shaped scan and a split early-return form; the remaining mismatch stayed in the early null/empty + first char check basin

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
    uchar* line;

    this->update_text();
    line = (uchar*)this->currentLine;
    if (line == 0 || *line == '\0') {
        return 1;
    }
    do {
        if (__ismbcspace((unsigned int)*line) == 0) {
            return 0;
        }
        line = __mbsinc(line);
    } while (*line != '\0');
    return 1;
}
