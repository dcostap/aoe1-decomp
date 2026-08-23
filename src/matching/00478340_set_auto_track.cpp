#ifndef AOE1_PNL_LST_CONTEXT_H
class TListPanel {
public:
    virtual ~TListPanel();
    char gap_0[0x184];
    int field_188;
    void set_auto_track(int v);
};
#endif

void TListPanel::set_auto_track(int v) { this->field_188 = v; }
