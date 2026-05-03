// VA: 0048B5A0, RGE_Scenario::~RGE_Scenario, 288 bytes
// Source: scenario.cpp lines 374-419
// FLAGS: /nologo /c /O2 /Oy

#include <stddef.h>

typedef unsigned char uchar;

extern "C" void free(void* ptr);
void operator delete(void* ptr);

struct RGE_Timeline {
    void* vtable;
    virtual ~RGE_Timeline();
};

struct TPicture {
    void* vtable;
    ~TPicture();
};

struct RGE_Scenario {
    void* vtable;                    // +0x00
    RGE_Timeline* time_line;         // +0x04
    char _pad_08[0x1008];            // +0x08 to +0x100F
    char* scenario_name;             // +0x1010
    char* description;               // +0x1014
    char* hints;                     // +0x1018
    char* win_message;               // +0x101C
    char* loss_message;              // +0x1020
    char* historicle_notes;          // +0x1024
    char _pad_1028[0x964];           // +0x1028 to +0x198B
    TPicture* mission_picture;       // +0x198C

    ~RGE_Scenario();
};

RGE_Scenario::~RGE_Scenario()
{
    this->vtable = (void*)0x572128;

    if (this->time_line != 0) {
        delete this->time_line;
        this->time_line = 0;
    }

    if (this->description != 0) free(this->description);
    if (this->hints != 0) free(this->hints);
    if (this->win_message != 0) free(this->win_message);
    if (this->loss_message != 0) free(this->loss_message);
    if (this->historicle_notes != 0) free(this->historicle_notes);

    operator delete(this->scenario_name);

    TPicture* pic = this->mission_picture;
    if (pic != 0) {
        pic->~TPicture();
        operator delete(pic);
        this->mission_picture = 0;
    }

    // CityPlan loop: 16 iterations, advancing by one pointer each step
    char** cp = (char**)((char*)this + 0x1308);
    int count = 16;
    do {
        operator delete(cp[-16]);
        operator delete(cp[0]);
        operator delete(cp[16]);
        if (cp[32] != 0) free(cp[32]);
        if (cp[48] != 0) free(cp[48]);
        if (cp[64] != 0) free(cp[64]);
        cp++;
    } while (--count != 0);
}
