// VA: 004219F0 RGE_Base_Game::handle_palette_changed
// basegame.cpp lines 4655-4678
//
// Attempt log:
// - Initial stub was empty.
// - Natural member-call/control-flow shape nearly matched, but the fallback virtual call initially used the wrong
//   vtable slot and returned the virtual result, shortening the final epilogue.
// - SpruceGlow MATCH: expose the fallback virtual at vtable offset 0xEC (59 dummy slots before it) and call it for
//   side effect only, then return 1. Keep the slightly unsafe source order `DrawType || ScreenMode || ds == 0` to
//   preserve the original null test after the byte checks.
// Result: MATCH locally with `python tools/check_function.py --va 004219F0`.

class TDrawSystem {
public:
    char gap_00[0x78];
    char palette[0x400];
    unsigned char DrawType;
    unsigned char ScreenMode;

    void HandlePaletteChanged(void* p1, unsigned int p2, unsigned int p3, long p4);
    void ModifyPalette(int start, int count, void* palette);
};

class RGE_Base_Game {
public:
    virtual int vf00();
    virtual int vf01();
    virtual int vf02();
    virtual int vf03();
    virtual int vf04();
    virtual int vf05();
    virtual int vf06();
    virtual int vf07();
    virtual int vf08();
    virtual int vf09();
    virtual int vf10();
    virtual int vf11();
    virtual int vf12();
    virtual int vf13();
    virtual int vf14();
    virtual int vf15();
    virtual int vf16();
    virtual int vf17();
    virtual int vf18();
    virtual int vf19();
    virtual int vf20();
    virtual int vf21();
    virtual int vf22();
    virtual int vf23();
    virtual int vf24();
    virtual int vf25();
    virtual int vf26();
    virtual int vf27();
    virtual int vf28();
    virtual int vf29();
    virtual int vf30();
    virtual int vf31();
    virtual int vf32();
    virtual int vf33();
    virtual int vf34();
    virtual int vf35();
    virtual int vf36();
    virtual int vf37();
    virtual int vf38();
    virtual int vf39();
    virtual int vf40();
    virtual int vf41();
    virtual int vf42();
    virtual int vf43();
    virtual int vf44();
    virtual int vf45();
    virtual int vf46();
    virtual int vf47();
    virtual int vf48();
    virtual int vf49();
    virtual int vf50();
    virtual int vf51();
    virtual int vf52();
    virtual int vf53();
    virtual int vf54();
    virtual int vf55();
    virtual int vf56();
    virtual int vf57();
    virtual int vf58();
    virtual int base_handle_palette_changed(void* p1, unsigned int p2, unsigned int p3, long p4);

    char gap_04[0x44];
    TDrawSystem* draw_system;
    char gap_4C[0x164];
    int prog_mode;

    int handle_palette_changed(void* p1, unsigned int p2, unsigned int p3, long p4);
};

int RGE_Base_Game::handle_palette_changed(void* p1, unsigned int p2, unsigned int p3, long p4) {
    if (this->draw_system != 0) {
        this->draw_system->HandlePaletteChanged(p1, p2, p3, p4);
    }

    if ((void*)p3 != p1) {
        TDrawSystem* ds = this->draw_system;
        if (ds->DrawType == 1 || ds->ScreenMode == 1 || ds == 0) {
            this->base_handle_palette_changed(p1, p2, p3, p4);
        }
        else if (this->prog_mode != 1) {
            ds->ModifyPalette(0, 0x100, ds->palette);
            return 1;
        }
    }

    return 1;
}
