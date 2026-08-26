#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    enum DrawType { DrawClear = 1 };
    char gap_0[0x13C];
    int field_140;
    DrawType drawType() const;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

TButtonPanel::DrawType TButtonPanel::drawType() const { return this->field_140; }
