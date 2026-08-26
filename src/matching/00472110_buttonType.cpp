#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    enum ButtonType { Normal = 1 };
    char gap_0[0x138];
    int field_13C;
    ButtonType buttonType() const;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

TButtonPanel::ButtonType TButtonPanel::buttonType() const { return this->field_13C; }
