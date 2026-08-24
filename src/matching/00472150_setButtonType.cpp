#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x138];
    int field_13C;
    void setButtonType(int v);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::setButtonType(int v) { this->field_13C = v; }
