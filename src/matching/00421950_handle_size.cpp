// VA: 00421950 RGE_Base_Game::handle_size(void*, unsigned int, unsigned int, long)
// PDB source: basegame.cpp lines 4626-4649 (151 B, 52 asm)
// Attempt log:

class TDrawSystem {
public:
    char gap_00[0x2C];
    int ScreenWidth;   // +0x2C
    int ScreenHeight;  // +0x30

    void HandleSize(void* p1, unsigned int p2, unsigned int p3, long p4);
};

class RGE_Prog_Info {
public:
    char gap_000[0x8E0];
    long main_wid;     // +0x8E0
    long main_hgt;     // +0x8E4
};

class TPanel {
public:
    // 19 dummy virtuals + HandleSize at vtable+0x50
    virtual void d01(); virtual void d02(); virtual void d03();
    virtual void d04(); virtual void d05(); virtual void d06();
    virtual void d07(); virtual void d08(); virtual void d09();
    virtual void d10(); virtual void d11(); virtual void d12();
    virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18();
    virtual void d19(); virtual void d20();
    virtual void HandleSize(long wid, long hgt);  // +0x50
};

class TPanelSystem {
public:
    char gap_00[0x0C];
    TPanel* currentPanel_; // +0x0C
    TPanel* currentPanel();
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_04[8];       // +0x04 (after implicit vtable)
    RGE_Prog_Info* prog_info; // +0x0C
    char gap_10[0x48 - 0x10];
    TDrawSystem* draw_system; // +0x48
    // 71 dummy virtuals + endMethod at vtable+0x120
    virtual void f01(); virtual void f02(); virtual void f03(); virtual void f04();
    virtual void f05(); virtual void f06(); virtual void f07(); virtual void f08();
    virtual void f09(); virtual void f10(); virtual void f11(); virtual void f12();
    virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16();
    virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20();
    virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28();
    virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32();
    virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36();
    virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40();
    virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44();
    virtual void f45(); virtual void f46(); virtual void f47(); virtual void f48();
    virtual void f49(); virtual void f50(); virtual void f51(); virtual void f52();
    virtual void f53(); virtual void f54(); virtual void f55(); virtual void f56();
    virtual void f57(); virtual void f58(); virtual void f59(); virtual void f60();
    virtual void f61(); virtual void f62(); virtual void f63(); virtual void f64();
    virtual void f65(); virtual void f66(); virtual void f67(); virtual void f68();
    virtual void f69(); virtual void f70(); virtual void f71();
    virtual void f72();
    virtual void endMethod();  // +0x120

    int handle_size(void* p1, unsigned int p2, unsigned int p3, long p4);
};

int RGE_Base_Game::handle_size(void* p1, unsigned int p2, unsigned int p3, long p4)
{
    if (p3 == 1) return 1;

    if (this->draw_system != 0) {
        this->draw_system->HandleSize(p1, p2, p3, p4);

        if (this->draw_system != 0 && this->draw_system->ScreenWidth != 0) {
            this->prog_info->main_wid = this->draw_system->ScreenWidth;
            this->prog_info->main_hgt = this->draw_system->ScreenHeight;
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->HandleSize(this->prog_info->main_wid, this->prog_info->main_hgt);
        }
    }

    this->endMethod();
    return 1;
}
