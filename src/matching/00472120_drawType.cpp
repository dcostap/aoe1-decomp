#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x13C];
    int field_140;
    int drawType();
};
#endif /* PNL_BTN_SHARED_CONTEXT */

int TButtonPanel::drawType() { return this->field_140; }
