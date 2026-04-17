// STATUS: blocked
// BLOCKER: VC5 keeps preserving this in eax and reshaping the mode dispatch, producing an 80-byte body instead of the original 81-byte eax/sub/dec chain
// NOTE: behavior matches; remaining drift is register/cfg shape in the parent-present prologue and root-panel mode switch

class TPanel {
public:
    char gap_00[0x40];
    TPanel* parent_panel;
    char gap_44[0x98];
    int z_order;

    void set_child_z_order(TPanel* child, int mode, short z_order);
    void set_z_order(int mode, short z_order);
};

void TPanel::set_z_order(int mode, short order) {
    if (parent_panel != 0) {
        parent_panel->set_child_z_order(this, mode, order);
        return;
    }
    mode &= 0xFF;
    if (mode == 0) {
        z_order = order;
        return;
    }
    --mode;
    if (mode == 0) {
        z_order = 0;
        return;
    }
    --mode;
    if (mode != 0) {
        return;
    }
    z_order = 0;
}
