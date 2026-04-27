// VA: 0043FD50 TMessageDialog::setup (main)
// Dlg_msg.cpp lines 71-165

// attempt 1: main setup with text + button creation
// 464/631 bytes (73.5%)
// Complex: jump tables, button creation loop, virtual dispatch
// Left in scratch.

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    TDrawArea* renderArea(TPanel* param);
    char gap_04[0x3C];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea* area, TPanel* p1, long p2, long p3, char* p4, long p5, int p6);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    void set_text(int id, int zero);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TMessageDialog : public TDialogPanel {
public:
    TPanel* parent;
    char gap_44[0x44C];
    unsigned char msg_type;       // +0x490
    char gap_491[3];
    TPanel* text;                 // +0x494
    TPanel* button[3];            // +0x498, +0x49C, +0x4A0

    int width;     // +0x14
    int height;    // +0x18

    virtual ~TMessageDialog();
    virtual long setup(TPanel* p1, char* p2, long p3, long p4, long p5,
        unsigned char p6, int p7, long p8, long p9);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
    
    virtual int create_text(TPanel** out, char* text, long a, long b, long c,
        long d, long e, int f, int g, int h);
    virtual int create_button(TPanel** out, int id, int zero, long a, long b,
        long c, long d, long e, int f, int g, int h);
};

long TMessageDialog::setup(TPanel* p1, char* p2, long p3, long p4, long p5,
    unsigned char p6, int p7, long p8, long p9) {
    
    button[0] = 0;
    button[1] = 0;
    button[2] = 0;
    
    msg_type = p6;
    
    TDrawArea* draw_area = TPanel::renderArea(p1);
    int result = TDialogPanel::setup(draw_area, p1, p3, p4, p2, p5, 1);
    if (result == 0) return 0;
    
    int h = this->height;
    int btn_h = h;
    int w = this->width;
    
    result = create_text(&text, (char*)p7, h - 6, w - 3, 1, 3, 3, 0x0B, 1, 1);
    if (result == 0) return 0;
    
    int btn_count;
    switch (msg_type) {
        case 0: btn_count = 1; break;
        case 1: btn_count = 3; break;
        case 2: btn_count = 2; break;
        default: return 0;
    }
    
    int spacing = 20;
    
    for (int i = 0; i < btn_count; i++) {
        btn_h -= spacing;
        result = create_button(&button[i], 0xFA1, 0, w, spacing, btn_h, 0x0B, btn_h, 0, 0, 0);
        if (result == 0) return 0;
        
        if (msg_type == 0) {
            ((TButtonPanel*)button[0])->set_text(0xFA1, 0);
        } else if (msg_type == 1) {
            ((TButtonPanel*)button[0])->set_text(0xFA1, 0);
            ((TButtonPanel*)button[1])->set_text(0xFA2, 0);
            ((TButtonPanel*)button[2])->set_text(0xFA3, 0);
        } else if (msg_type == 2) {
            ((TButtonPanel*)button[0])->set_text(0xFA1, 0);
            ((TButtonPanel*)button[1])->set_text(0xFA2, 0);
        }
    }
    
    return 1;
}
