// attempt 2: string-id wrapper that resolves text then delegates to the real virtual create_text slot

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel {};
class TTextPanel {};

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
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual int create_text(TPanel* parent, TTextPanel** out, char* text, long p4, long p5, long p6, long p7, long p8, long p9, long p10, long p11);
    int create_text(TPanel* parent, TTextPanel** out, long string_id, long p4, long p5, long p6, long p7, long p8, long p9, long p10, long p11);
};
#endif

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, int string_id, long p4, long p5, long p6, long p7, long p8, int p9, int p10, int p11) {
    char text[256];

    this->get_string(string_id, text, 0x100);
    return this->create_text(parent, out, text, p4, p5, p6, p7, p8, p9, p10, p11);
}
