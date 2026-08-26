#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    virtual ~TButtonPanel();
    enum NotifyType { NotifyAction = 1 };
    char gap_0[0x140];
    int field_144;
    NotifyType notifyType() const;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

TButtonPanel::NotifyType TButtonPanel::notifyType() const { return this->field_144; }
