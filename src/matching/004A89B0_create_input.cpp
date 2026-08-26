// first pass: forward to TEasy_Panel::create_input with the fixed tail arguments, then promote the created input panel to z-order 1 and call its slot-0x14 virtual
// if this misses, the remaining gap is likely just the exact virtual-call spelling for the final input-panel vfunc
#pragma warning(disable:4234)
#ifndef SCR_SED_TU_CONTEXT
class TPanel {
public:
    void set_z_order(unsigned char mode, short z_order);
};

class TInputPanel {
public:
    enum FormatType { FormatText = 0, FormatUnsignedInt = 3,
                      FormatMultiLine = 7 };
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int param_1);
};

class TEasy_Panel {
public:
    int create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10);
};

class TRIBE_Screen_Sed : public TEasy_Panel {
public:
    int create_input(TPanel* param_1, TInputPanel** param_2, char* param_3,
                     short param_4, TInputPanel::FormatType param_5);
};
#endif

int TRIBE_Screen_Sed::create_input(TPanel* param_1, TInputPanel** param_2,
                                   char* param_3, short param_4,
                                   TInputPanel::FormatType param_5) {
    if (TEasy_Panel::create_input(param_1, param_2, param_3, param_4, param_5, 0, 0, 0, 0, 10) == 0) {
        return 0;
    }
    ((TPanel*)*param_2)->set_z_order(1, 0);
    ((TInputPanel*)*param_2)->v5(0);
    return 1;
}
