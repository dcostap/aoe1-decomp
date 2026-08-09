// VA: 00472440 set_text
// PDB source: Pnl_btn.cpp:337-372
// Attempt log:
// - baseline: natural two-string replacement with calloc/strcpy and the
//   proven text1/text2 arrays at +0x198/+0x1BC; exact 250/250 bytes.

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
    virtual void vf20(int param_1);

    char gap_04[0x194];
    char* text1[9];
    char* text2[9];

    void set_text(short state, char* text1_arg, char* text2_arg);
};

void TButtonPanel::set_text(short state, char* text1_arg, char* text2_arg) {
    if (text1[state] != 0) {
        free(text1[state]);
        text1[state] = 0;
    }
    if (text2[state] != 0) {
        free(text2[state]);
        text2[state] = 0;
    }
    if (text1_arg != 0 && *text1_arg != 0) {
        text1[state] = (char*)calloc(strlen(text1_arg) + 1, 1);
        if (text1[state] != 0) {
            strcpy(text1[state], text1_arg);
            if (text2_arg != 0 && *text2_arg != 0) {
                text2[state] = (char*)calloc(strlen(text2_arg) + 1, 1);
                if (text2[state] != 0) {
                    strcpy(text2[state], text2_arg);
                }
            }
        }
    }
    vf20(1);
}
