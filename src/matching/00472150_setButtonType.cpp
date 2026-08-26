#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    enum ButtonType { Normal = 1 };
    char gap_0[0x138];
    int field_13C;
    void setButtonType(ButtonType v);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::setButtonType(TButtonPanel::ButtonType v) { this->field_13C = v; }
