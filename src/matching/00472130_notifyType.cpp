#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x140];
    int field_144;
    int notifyType();
};
#endif /* PNL_BTN_SHARED_CONTEXT */

int TButtonPanel::notifyType() { return this->field_144; }
