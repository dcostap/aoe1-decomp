#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    enum DrawType { DrawClear = 1 };
    char gap_0[0x13C];
    int field_140;
    void setDrawType(DrawType v);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::setDrawType(TButtonPanel::DrawType v) { this->field_140 = v; }
