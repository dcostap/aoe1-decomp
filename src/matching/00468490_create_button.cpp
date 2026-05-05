// attempt 2: string-id wrapper that resolves two labels then delegates to the real virtual create_button slot

class TPanel {};
class TButtonPanel {};

class TEasy_Panel {
public:
    int get_string(long id, char* buffer, long size);
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
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual int create_button(TPanel* parent, TButtonPanel** out, char* text1, char* text2, long p5, long p6, long p7, long p8, long p9, long p10, long p11);
    int create_button(TPanel* parent, TButtonPanel** out, long id1, long id2, long p5, long p6, long p7, long p8, long p9, long p10, long p11);
};

int TEasy_Panel::create_button(TPanel* parent, TButtonPanel** out, long id1, long id2, long p5, long p6, long p7, long p8, long p9, long p10, long p11) {
    char text2[120];
    char text1[120];

    this->get_string(id1, text1, 0x78);
    this->get_string(id2, text2, 0x78);
    return this->create_button(parent, out, text1, text2, p5, p6, p7, p8, p9, p10, p11);
}
