#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x13C];
    int field_140;
    void setDrawType(int v);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::setDrawType(int v) { this->field_140 = v; }
