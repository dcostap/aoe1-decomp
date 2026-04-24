// first pass: release the mouse capture, clear the two scroll-state fields, and conditionally dispatch the panel callback
// tried exact offset stubs for +40/+F8/+100/+194/+198 and several callback shapes; the remaining mismatch stayed in register allocation around the panel load / vtable dispatch

class TListPanelCallbackOwner {
public:
    void** vftable;
};

class TListPanel {
public:
    void release_mouse();

    char gap_00[0x40];
    TListPanelCallbackOwner* field_40;
    char gap_44[0xB4];
    short field_f8;
    char gap_FA[6];
    short field_100;
    char gap_102[0x92];
    int field_194;
    int field_198;

    long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
};

long TListPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    short index;

    release_mouse();
    this->field_194 = 0;
    this->field_198 = 0;
    {
        register TListPanelCallbackOwner* panel = this->field_40;

        if (panel != 0) {
            register void** vtable = panel->vftable;

            index = this->field_100;
            if (index > -1 && index < this->field_f8) {
                ((void (__cdecl *)(TListPanel*, int, int, int))vtable[45])(this, 2, index, 0);
            }
        }
    }
    return 1;
}
