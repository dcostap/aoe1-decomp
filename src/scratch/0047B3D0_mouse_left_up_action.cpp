// tried a base-sized panel stub with the notify pointer in the wrong payload offset; first mismatch moved to the initial load
// tried a full-size TPanel base and the real +0x40 base pointer; body logic stayed right but the notify/refresh calls still used the wrong caller-cleanup shape
// tried plain function-pointer casts, then __thiscall typedefs with warning 4234 disabled; remaining mismatch is still the virtual-call basin, not the branch logic
#pragma warning(disable:4234)
class TScrollBarPanel_ListPanel {
public:
    void* vtable_ptr;
};

class TPanel {
public:
    void* vtable_ptr;
    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];

    void release_mouse();
};

class TScrollBarPanel : public TPanel {
public:
    TPanel* list_panel;
    long list_len;
    long one_step;
    long page_step;
    long list_num;
    char gap_108[0x3C];
    unsigned char item_down;
    char gap_145[0x3];
    int item_is_down;
    long item_x;
    long item_y;
    unsigned char item_mode;

    long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
};

long TScrollBarPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    if (this->parent_panel != 0) {
        typedef void (__thiscall *ListNotifyFn)(TPanel* self, int mode, long value, int zero);
        ((ListNotifyFn)((void**)this->parent_panel->vtable_ptr)[45])(this->parent_panel, 5, this->list_num, 0);
    }
    this->release_mouse();
    this->item_down = 0;
    this->item_mode = 0;
    this->item_is_down = 0;
    typedef void (__thiscall *RefreshFn)(TScrollBarPanel* self, int flag);
    ((RefreshFn)((void**)this->vtable_ptr)[8])(this, 1);
    return 0;
}
