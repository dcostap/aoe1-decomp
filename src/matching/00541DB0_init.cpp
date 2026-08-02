// 00541DB0 RGE_Game_World::init
// PDB: World.cpp:871-896, 190 bytes
// Virtual slot: vt[44] (0xB0)
// FLAGS: default
//
// Exact match: the natural outer `fd != -1` guard with an inner mismatch-first
// version guard reproduces the original block order and epilogues.
// Positional diff: 0/190 (0.0%), Edit diff: 0 (0.0%)
// Relocs masked: 5
//
// Attempt log:
// prior probes 1-16: direct fd-failure forms, comparison-direction forms,
// explicit fail labels, and a focused variant lab left two codegen groups;
// the best success-first form was 55 positional bytes away in this TU.
// current probe: put the read/version logic inside `if (fd != -1)` and use
// `if (strcmp(...) != 0)` for the close/false arm; exact 190-byte match.

#include <string.h>

class TSound_Driver;
class TCommunications_Handler;

extern "C" int __cdecl rge_open(const char* path, int access);
extern "C" void __cdecl rge_read(int fd, void* buf, int size);
extern "C" int __cdecl rge_close(int fd);

class RGE_Game_World {
public:
    // vtable slots 0-21 (0x00-0x54)
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();

    // slot 22 (0x58): world_init
    virtual void world_init(int fd, TSound_Driver* sd, TCommunications_Handler* ch);

    // slots 23-43 (0x5C-0xAC)
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();

    // slot 44 (0xB0): this function
    virtual unsigned char init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3);
};

unsigned char RGE_Game_World::init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3) {
    char version[8];

    *(TSound_Driver**)((char*)this + 0x80) = param_2;
    *(long*)((char*)this + 0x68) = 0;

    int fd = rge_open(param_1, 0x8000);
    if (fd != -1) {
        rge_read(fd, version, 8);

        if (strcmp(version, "VER 3.7") != 0) {
            rge_close(fd);
            return 0;
        }

        this->world_init(fd, param_2, param_3);
        rge_close(fd);
        return 1;
    }

    return 0;
}
