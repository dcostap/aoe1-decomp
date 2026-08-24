// first pass: direct field stores followed by a straightforward base setup call with trailing zero
// if this stays sticky, the remaining mismatch is likely just the exact parameter load order into the base call
#ifndef PNL_SCBR_CANONICAL_TU
class TDrawArea;
class TPanel {
public:
    char pad_00[0xF4];
    int setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, int value);
};

class TScrollBarPanel : public TPanel {
public:
    TPanel* list_panel;      // +0xF4
    long list_len;           // +0xF8
    char pad_FC[0x20];       // +0xFC..+0x11B
    long arrowSize;          // +0x11C
    long tabSize;            // +0x120
    char pad_124[0x90];      // +0x124..+0x1B3
    long orientationValue;   // +0x1B4
    long bevel_type;         // +0x1B8

    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6,
               char* param_7, char* param_8, char* param_9, char* param_10,
               long param_11, long param_12, TPanel* param_13, long param_14, long param_15);
};
#endif

long TScrollBarPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6,
                            char* param_7, char* param_8, char* param_9, char* param_10,
                            long param_11, long param_12, TPanel* param_13, long param_14, long param_15) {
    long result;

    this->orientationValue = param_15;
    this->arrowSize = param_11;
    this->tabSize = param_12;
    this->list_panel = param_13;
    this->list_len = param_14;
    result = this->TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);
    result = 1;
    return result;
}
