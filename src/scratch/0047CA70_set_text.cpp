// tried explicit vtable-slot call, then a real 59th virtual method on TTTextPanel
// tried shrinking the buffer to 4092; that shifted the prolog family, so the closer 4096-byte stack shape is restored here
// remaining gap is the exact esp+4 stack-buffer base and VC5 register choice around the virtual call

class TPanel {
public:
    void* vtable_ptr;
    char gap_0[0xF0];

    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    int get_string(int string_id, char* buffer, int length);
};

class TTTextPanel : public TPanel {
public:
    struct TextNode {
        char* text;
        char* text2;
        long id;
        TextNode* next_node;
    };

    TextNode* list;
    virtual void set_text2(char* text);
    void set_text(long string_id);
};

void TTTextPanel::set_text(long string_id) {
    char str[4096];

    TPanel::get_string((int)string_id, str + 4, 0x1000);
    this->set_text2(str + 4);
}
