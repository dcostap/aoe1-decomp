// VA: 00442680 TDrawSystem::TDrawSystem
// PDB source: Drawarea.cpp lines 316-378
// Attempt log:
// rewrite 2026-05-19: implemented full observed constructor field initialization and _ASMSet_Shadowing call.

extern "C" void __cdecl _ASMSet_Shadowing(int, int, int, int);
#define system_ignore_size_messages (*(int*)0x62E63C)

class TDrawSystem {
public:
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int ColorBits;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
    int f64;
    int f68;
    int f6C;
    int f70;
    int f74;
    char gap_78[0x478 - 0x78];
    unsigned char DrawType;
    unsigned char ScreenMode;

    TDrawSystem();
};

TDrawSystem::TDrawSystem()
{
    this->f00 = 0;
    this->f04 = 0;
    this->f08 = 0;
    this->f0C = 0;
    this->f10 = 0;
    this->f18 = 0;
    this->f1C = 0;
    this->f20 = 0;
    this->f24 = 0;
    this->f3C = 0;
    this->DrawType = 0;
    this->ScreenMode = 0;
    this->f2C = 0;
    this->f30 = 0;
    this->ColorBits = 8;
    this->f28 = 0;
    this->f40 = 0;
    this->f44 = 0;
    this->f14 = 0;
    this->f48 = 0;
    this->f4C = 0;
    this->f50 = 0;
    this->f54 = 0;
    this->f58 = 0;
    this->f5C = 0;
    this->f60 = 0;
    this->f64 = 0;
    this->f68 = 0;
    this->f6C = 0;
    this->f70 = 0;
    this->f74 = 0;
    this->f38 = 0;
    system_ignore_size_messages = 0;
    _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
}
