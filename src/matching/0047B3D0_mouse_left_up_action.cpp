// tried a base-sized panel stub with the notify pointer in the wrong payload offset; first mismatch moved to the initial load
// tried a full-size TPanel base and the real +0x40 base pointer; body logic stayed right but the notify/refresh calls still used the wrong caller-cleanup shape
// tried plain function-pointer casts, then __thiscall typedefs with warning 4234 disabled; remaining mismatch is still the virtual-call basin, not the branch logic
// tried real thiscall virtual dispatch through padded slots so VC5 keeps ecx as parent/this and avoids caller cleanup after the two virtual calls

#ifndef PNL_SCBR_CANONICAL_TU
class TPanel {
public:
    virtual ~TPanel();             // vt[0]
    virtual void v1();             // vt[1]
    virtual void v2();             // vt[2]
    virtual void v3();             // vt[3]
    virtual void v4();             // vt[4]
    virtual void v5();             // vt[5]
    virtual void v6();             // vt[6]
    virtual void v7();             // vt[7]
    virtual void redraw(int flag); // vt[8] -> [eax+20h]
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual long action(TPanel* panel, long code, unsigned long value, unsigned long zero); // vt[45] -> [eax+0B4h]

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

    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
};
#endif

long TScrollBarPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    if (this->parent_panel != 0) {
        this->parent_panel->action(this, 5, this->list_num, 0);
    }
    this->release_mouse();
    this->item_down = 0;
    this->item_mode = 0;
    this->item_is_down = 0;
    this->redraw(1);
    return 0;
}
