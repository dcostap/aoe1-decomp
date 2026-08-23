// VA: 0052AF20 T_Scenario::save
// Straight source from packet/asm: base save plus fixed binary blocks.

#include "../../include/tscenaro_context.h"

extern "C" void __cdecl rge_write(int file, void* data, int size);

#if 0
class RGE_Scenario {
public:
    void save(int file);
};

class T_Scenario : public RGE_Scenario {
public:
    void WriteDisabledTechnologiesToMainSystem(void);
    void save(int file);
};
#endif

void T_Scenario::save(int file) {
    int checksum;
    char* p;
    int i;

    checksum = -99;
    WriteDisabledTechnologiesToMainSystem();
    RGE_Scenario::save(file);

    p = (char*)this + 0x1990;
    for (i = 0x10; i != 0; --i) {
        rge_write(file, p, 0x10);
        p += 0x10;
    }

    rge_write(file, &checksum, 4);
    rge_write(file, (char*)this + 0x1A90, 0x18);
    rge_write(file, (char*)this + 0x4BE8, 4);
    rge_write(file, (char*)this + 0x5140, 4);
    rge_write(file, (char*)this + 0x5144, 4);
    rge_write(file, (char*)this + 0x5148, 4);
    rge_write(file, (char*)this + 0x47A8, 0x400);

    p = (char*)this + 0x1AA8;
    for (i = 0x10; i != 0; --i) {
        rge_write(file, p, 0x2D0);
        p += 0x2D0;
    }

    rge_write(file, &checksum, 4);
    rge_write(file, (char*)this + 0x4BA8, 0x40);
    rge_write(file, (char*)this + 0x4BF4, 0x500);
    rge_write(file, (char*)this + 0x50F4, 0x0C);
    rge_write(file, (char*)this + 0x5100, 0x40);
    rge_write(file, &checksum, 4);
}
