class TShape;

class TButtonPanel {
public:
    void set_picture(short p0, TShape* p1, short p2);
};

class TScrollBarPanel {
public:
    void set_buttons(TShape* p1, int p2, int p3, int p4, int p5);
};

class TDropDownPanel {
public:
    char gap_00[0xF8];
    TButtonPanel* btn_panel;
    char gap_fc[4];
    TScrollBarPanel* scbar_panel;

    void set_buttons(TShape* shape, int p2, int p3, int p4, int p5, int p6);
};

void TDropDownPanel::set_buttons(TShape* shape, int p2, int p3, int p4, int p5, int p6) {
    if (btn_panel != 0) {
        if (shape != 0) {
            btn_panel->set_picture(0, shape, (short)p2);
        } else {
            btn_panel->set_picture(0, 0, -1);
        }
    }
    if (scbar_panel != 0) {
        scbar_panel->set_buttons(shape, p3, p4, p5, p6);
    }
}
