// first pass: direct virtual create call, then wire the resulting scrollbar into the text panel
// the target function must stay lexically first so the extractor sees its bytes first
// tried a raw vtable function-pointer cast; the remaining mismatch was the ECX/thiscall setup on the factory call

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TScrollBarPanel;

class TTextPanel {
public:
    char gap_00[0x40];
    long field_40;

    void set_scrollbar(TScrollBarPanel* panel, int auto_scbar_value);
};

class TEasy_Panel {
public:
    virtual int vf00(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf01(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf02(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf03(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf04(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf05(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf06(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf07(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf08(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf09(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf10(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf11(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf12(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf13(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf14(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf15(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf16(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf17(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf18(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf19(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf20(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf21(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf22(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf23(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf24(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf25(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf26(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf27(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf28(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf29(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf30(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf31(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf32(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf33(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf34(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf35(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf36(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf37(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf38(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf39(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf40(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf41(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf42(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf43(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf44(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf45(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf46(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf47(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf48(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf49(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf50(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf51(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf52(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf53(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf54(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf55(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf56(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf57(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf58(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf59(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf60(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf61(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf62(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf63(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf64(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf65(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf66(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf67(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int vf68(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int create_auto_scrollbar_impl(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);

    int create_auto_scrollbar(TScrollBarPanel** scrollbar_out, TTextPanel* text, long param_3);
};

class TScrollBarPanel {
public:
    long dummy;
};
#endif

int TEasy_Panel::create_auto_scrollbar(TScrollBarPanel** scrollbar_out, TTextPanel* text, long param_3) {
    if (this->create_auto_scrollbar_impl(text->field_40, scrollbar_out, text, 0, 0, 0, param_3, 0) == 0) {
        return 0;
    }

    text->set_scrollbar(*scrollbar_out, 1);
    return 1;
}
