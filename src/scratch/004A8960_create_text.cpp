// tried the direct wrapper with the TEasy_Panel::create_text call and the post-success z-order/vcall tail; prolog stayed wrong
// tried the decompiler-shaped local-result form; VC5 still emitted a different entry load/push order and the first mismatch stayed at offset 0
// leaving in scratch because the remaining gap is prolog/call-shape drift, not the side-effect tail
class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int value);
    virtual void set_z_order(unsigned char mode, short order);
};

class TTextPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    int create_text(TPanel* panel, TTextPanel** text_panel, char* text, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

class TRIBE_Screen_Sed : public TEasy_Panel {
public:
    int create_text(TPanel* panel, TTextPanel** text_panel, char* text);
};

int TRIBE_Screen_Sed::create_text(TPanel* panel, TTextPanel** text_panel, char* text) {
    int result;

    result = ((TEasy_Panel*)this)->create_text(panel, text_panel, text, 0, 0, 0, 0, 10, 0, 0, 0, 0);
    if (result == 0) {
        return 0;
    }
    (*text_panel)->set_z_order(1, 0);
    (*text_panel)->vf14(0);
    return 1;
}
