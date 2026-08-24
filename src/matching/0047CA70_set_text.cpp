// VA: 0047CA70 TTextPanel::set_text (63 B)
// PDB source: Pnl_txt.cpp lines 566-570

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
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
    virtual void vf0A();
    virtual void vf0B();
    virtual void vf0C();
    virtual void vf0D();
    virtual void vf0E();
    virtual void vf0F();
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
    virtual void vf1A();
    virtual void vf1B();
    virtual void vf1C();
    virtual void vf1D();
    virtual void vf1E();
    virtual void vf1F();
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
    virtual void vf2A();
    virtual void vf2B();
    virtual void vf2C();
    virtual void vf2D();
    virtual void vf2E();
    virtual void vf2F();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void set_text(long id);
    virtual void set_text2(char* str);
    int get_string(int string_id, char* buffer, int length);
};
#endif

void TTextPanel::set_text(long id) {
    char buffer[0x1000];
    this->get_string(id, buffer, 0x1000);
    this->set_text2(buffer);
}
