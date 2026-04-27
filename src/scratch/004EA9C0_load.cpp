// 004EA9C0 TacticalAIGroup::load(int fd)
// Source: taitacmd.cpp lines 150-199
// Deserializes struct fields with version-conditional reads
// Load has 4 float comparisons for backward compat: conditional field reads
//
// Attempt log:
// Probe 1: 624/721 bytes — missing conditional reads
// Probe 2: full version-conditional read logic

#include "..\..\include\game_globals.h"

extern "C" void __cdecl read_data(int fd, void* data, int size); // 00480080

extern float DAT_0058ebcc;
extern float DAT_005756e0;
extern float DAT_005756e4;
extern float DAT_005756e8;
extern float DAT_005756ec;
extern float DAT_0058ebcc;

class TacticalAIGroup {
public:
    char _gap_04[8];
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int members[40];
    int companion[40];
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    char data_170[0x10];
    int field_180;
    int field_184;
    int field_188;
    char data_18C[0x10];
    char data_19C[0x10];
    char data_1AC[0x10];
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    unsigned char byte_1D4;
    unsigned char byte_1D5;
    char data_1D8[0xF0];
    unsigned char byte_2C8;
    int field_2CC;
    char data_2D0[0x50];
    int field_320;
    int field_324;
    int field_328;
    int field_32C;

    int load(int fd);
};

int TacticalAIGroup::load(int fd)
{
    read_data(fd, &this->field_0C, 4);
    read_data(fd, &this->field_10, 4);

    int* ptr = this->companion;
    for (int i = 0; i < 40; i++) {
        read_data(fd, &ptr[-40 + i], 4);
        read_data(fd, &ptr[i], 4);
    }

    read_data(fd, &this->field_15C, 4);
    read_data(fd, &this->field_160, 4);
    read_data(fd, &this->field_164, 4);
    read_data(fd, &this->field_168, 4);
    read_data(fd, &this->field_16C, 4);
    read_data(fd, &this->data_170, 0x10);
    read_data(fd, &this->field_180, 4);
    read_data(fd, &this->field_184, 4);
    read_data(fd, &this->field_188, 4);
    read_data(fd, &this->data_18C, 0x10);
    read_data(fd, &this->data_19C, 0x10);
    read_data(fd, &this->data_1AC, 0x10);
    read_data(fd, &this->field_1BC, 4);
    read_data(fd, &this->field_1C0, 4);
    read_data(fd, &this->field_1C4, 4);
    read_data(fd, &this->field_1C8, 4);
    read_data(fd, &this->field_14, 4);
    read_data(fd, &this->field_18, 4);
    read_data(fd, &this->field_1CC, 4);
    read_data(fd, &this->byte_1D4, 1);
    read_data(fd, &this->byte_1D5, 1);
    read_data(fd, &this->data_1D8, 0xF0);
    read_data(fd, &this->field_1D0, 4);

    // Version detection: conditional field reads based on float version comparison
    // Asm pattern: fld [58EBCCh]; fcomp [5756E0h]; test ah,1; jne → if (ver < threshold)
    if (DAT_0058ebcc >= DAT_005756e0) {
        read_data(fd, &this->byte_2C8, 1);
    } else {
        this->byte_2C8 = 0;
    }

    if (DAT_0058ebcc >= DAT_005756e4) {
        read_data(fd, &this->field_2CC, 4);
        read_data(fd, &this->data_2D0, 0x50);
        read_data(fd, &this->field_320, 4);
        read_data(fd, &this->field_324, 4);
    }

    if (DAT_0058ebcc >= DAT_005756e8) {
        read_data(fd, &this->field_328, 4);
    }

    if (DAT_0058ebcc >= DAT_005756ec) {
        read_data(fd, &this->field_32C, 4);
    }

    return 1;
}
