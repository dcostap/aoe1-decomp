// RGE_Flic_Player constructor at 00449BE0 (flics.cpp lines 54-70)
// Inventory: 00449BE0_RGE_Flic_Player
// Asm: 00449BE0-00449C33 (28 bytes)
// Attempt log:
//   v1: first pass with minimal stub, wrong offset for flic_width; also EBX used for param, EDI not used.
//   v2: correcting class layout to include drawarea & drawarea_width, full FlicHead, and using explicit member calls.

#pragma pack(1) // enforce exact layout

class TDrawArea; // forward

struct FlicHead {
    long          size;        // +0x0
    unsigned short type;       // +0x4
    short         frames;      // +0x6
    short         width;       // +0x8  <-- target field
    short         height;      // +0xA
    short         depth;       // +0xC
    short         flags;       // +0xE
    long          speed;       // +0x10
    short         reserved1;   // +0x14
    unsigned char _pad0[0x2];  // align to +0x18
    long          created;     // +0x18
    long          creator;     // +0x1C
    long          updated;     // +0x20
    long          updater;     // +0x24
    short         aspect_dx;   // +0x28
    short         aspect_dy;   // +0x2A
    char          reserved2[0x26]; // up to +0x52
    unsigned char _pad1[0x2];     // +0x52 align?
    char*         oframe1;     // +0x54
    char*         oframe2;     // +0x58
    char          reserved3[0x28]; // +0x5C (40) => up to +0x84
};

class RGE_Flic_Player {
public:
    unsigned char* flic_buffer;  // +0x0
    int            flic_handle;  // +0x4
    FlicHead       flichead;     // +0x8  size 0x84
    TDrawArea*     drawarea;     // +0x8C
    long           drawarea_width;// +0x90
    long           flic_width;   // +0x94
    // other fields not needed for this ctor

    RGE_Flic_Player(int file_handle);
    void start();
};

extern "C" int read(int handle, void* buffer, int size); // 0054CD80 (cdecl)

void RGE_Flic_Player::start(); // member function at 00449E20 (__thiscall)

RGE_Flic_Player::RGE_Flic_Player(int file_handle) {
    if (file_handle > -1) {
        read(file_handle, &this->flichead, 0x84);
        this->flic_width  = (int)(short)this->flichead.width;
        this->flic_handle = file_handle;
        this->flic_buffer = 0;
        this->start();
    }
    else {
        this->flic_buffer = 0;
        this->flic_handle = -1;
    }
}
