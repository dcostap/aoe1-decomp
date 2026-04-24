class TDrawArea;

class TEasy_Panel {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void draw_rect2(unsigned char param_1);

    char gap_00[0xEE];
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
    char gap_f4[0x378];
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    void setup_shadow_area(unsigned char param_1);
    void draw();
};

void TEasy_Panel::draw() {
    if (this->need_restore != 0) {
        if (this->shadow_area != 0) {
            this->setup_shadow_area(1);
        }
        this->need_restore = 0;
    }
    if (this->draw_rect2_flag != 0) {
        this->draw_rect2(1);
    } else {
        this->draw_rect2(0);
    }
}
