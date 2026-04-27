// 004EACA0 TacticalAIGroup::save(int fd)
// Source: taitacmd.cpp lines 204-242
// Serializes all struct fields via fwrite (004802C0)
// Returns 1 on success.
//
// Attempt log:
// Probe 1: proper serialization body — 624/636 bytes (12 short)
//   Loop structure different: original writes 2 ints per iteration.
// Probe 2: match the dual-write loop pattern

#include "..\..\include\game_globals.h"

extern "C" void __cdecl write_data(int fd, void* data, int size); // 004802C0 (fwrite-like)

// TacticalAIGroup layout (partial, only serialized fields)
class TacticalAIGroup {
public:
    // vtable at +0x00 (4 bytes)
    char _gap_04[8];           // +0x04 to +0x0B
    int field_0C;              // +0x0C
    int field_10;              // +0x10
    int field_14;              // +0x14
    int field_18;              // +0x18
    int members[40];           // +0x1C (40 ints = 160 bytes)
    int companion[40];         // +0xBC (40 ints = 160 bytes)
    int field_15C;             // +0x15C
    int field_160;             // +0x160
    int field_164;             // +0x164
    int field_168;             // +0x168
    int field_16C;             // +0x16C
    char data_170[0x10];       // +0x170 (16 bytes)
    int field_180;             // +0x180
    int field_184;             // +0x184
    int field_188;             // +0x188
    char data_18C[0x10];       // +0x18C (16 bytes)
    char data_19C[0x10];       // +0x19C (16 bytes)
    char data_1AC[0x10];       // +0x1AC (16 bytes)
    int field_1BC;             // +0x1BC
    int field_1C0;             // +0x1C0
    int field_1C4;             // +0x1C4
    int field_1C8;             // +0x1C8
    int field_1CC;             // +0x1CC
    int field_1D0;             // +0x1D0
    unsigned char byte_1D4;    // +0x1D4
    unsigned char byte_1D5;    // +0x1D5
    char data_1D8[0xF0];       // +0x1D8 (240 bytes)
    unsigned char byte_2C8;    // +0x2C8
    int field_2CC;             // +0x2CC
    char data_2D0[0x50];       // +0x2D0 (80 bytes)
    int field_320;             // +0x320
    int field_324;             // +0x324
    int field_328;             // +0x328
    int field_32C;             // +0x32C

    int save(int fd);
};

int TacticalAIGroup::save(int fd)
{
    write_data(fd, &this->field_0C, 4);
    write_data(fd, &this->field_10, 4);

    // Write members array (40 ints) + companion array at +0xBC
    // Original loops: for i in 0..40, write members[i], then write companion[i]
    int* ptr = this->companion;
    for (int i = 0; i < 40; i++) {
        write_data(fd, &ptr[-40 + i], 4);
        write_data(fd, &ptr[i], 4);
    }

    write_data(fd, &this->field_15C, 4);
    write_data(fd, &this->field_160, 4);
    write_data(fd, &this->field_164, 4);
    write_data(fd, &this->field_168, 4);
    write_data(fd, &this->field_16C, 4);
    write_data(fd, &this->data_170, 0x10);
    write_data(fd, &this->field_180, 4);
    write_data(fd, &this->field_184, 4);
    write_data(fd, &this->field_188, 4);
    write_data(fd, &this->data_18C, 0x10);
    write_data(fd, &this->data_19C, 0x10);
    write_data(fd, &this->data_1AC, 0x10);
    write_data(fd, &this->field_1BC, 4);
    write_data(fd, &this->field_1C0, 4);
    write_data(fd, &this->field_1C4, 4);
    write_data(fd, &this->field_1C8, 4);
    write_data(fd, &this->field_14, 4);
    write_data(fd, &this->field_18, 4);
    write_data(fd, &this->field_1CC, 4);
    write_data(fd, &this->byte_1D4, 1);
    write_data(fd, &this->byte_1D5, 1);
    write_data(fd, &this->data_1D8, 0xF0);
    write_data(fd, &this->field_1D0, 4);
    write_data(fd, &this->byte_2C8, 1);
    write_data(fd, &this->field_2CC, 4);
    write_data(fd, &this->data_2D0, 0x50);
    write_data(fd, &this->field_320, 4);
    write_data(fd, &this->field_324, 4);
    write_data(fd, &this->field_328, 4);
    write_data(fd, &this->field_32C, 4);

    return 1;
}
