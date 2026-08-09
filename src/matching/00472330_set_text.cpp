// VA: 00472330 set_text
// PDB source: Pnl_btn.cpp:282-331
// Attempt log:
// - baseline candidate: natural one/two-line replacement using the proven
//   text1/text2 arrays at +0x198/+0x1BC.
// Main-agent audit named the donor-backed slot-0x20 set_redraw surface;
// emitted code remains exact.

#include <string.h>

extern "C" void __cdecl free(void* ptr);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class TButtonPanel {
public:
    virtual ~TButtonPanel();
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void set_redraw(int param_1);

    char gap_04[0x194];
    char* text1[9];
    char* text2[9];

    void set_text(short state, char* text);
};

void TButtonPanel::set_text(short state, char* text) {
    if (text1[state] != 0) {
        free(text1[state]);
        text1[state] = 0;
    }
    if (text2[state] != 0) {
        free(text2[state]);
        text2[state] = 0;
    }
    if (text != 0 && *text != 0) {
        char* newline = strchr(text, 10);
        short length;

        if (newline != 0) {
            length = (short)(newline - text);
        } else {
            length = (short)strlen(text);
        }
        text1[state] = (char*)calloc(length + 1, 1);
        if (text1[state] != 0) {
            strncpy(text1[state], text, length);
            text1[state][length] = 0;
            if (newline != 0) {
                newline++;
                text2[state] = (char*)calloc(strlen(newline) + 1, 1);
                if (text2[state] != 0) {
                    strcpy(text2[state], newline);
                }
            }
        }
    }
    set_redraw(1);
}
