// 0052AB90 T_Scenario::T_Scenario
// tscenaro.cpp
// Attempt log:
// try 1: natural constructor reconstruction from packet: base ctor, vftable, init helpers, version-gated rge_read blocks and defaults.
// try 2: added /GX flag because original has VC5 EH registration around the base-class constructor and state local.
// try 3: modeled constructor parameters as `(int file, RGE_Game_World* world)`, with base ctor receiving both but all rge_read calls using the first argument, matching original ESI usage.
// try 4: modeled immediate vtable store as literal `0x577308` to match `mov dword [edi],577308h` rather than an extern object load.
// try 5: modeled initial defaults at +0x5140/+0x5144/+0x5148 and +0x4BE8/+0x4BF0 before version-gated reads.
// try 6: modeled version < 577318 first branch reading 16 names of 0x100 bytes at +0x0D, and alternate 16 friendliness rows of 0x10 at +0x1990.
// try 7: modeled newer friendliness conversion loop with five reads per iteration at +0x194C/+0x1990/+0x18CC/+0x190C/+0x188C using old strided matrix storage.
// try 8: modeled repeated compatibility dummy 4-byte reads into the dead second parameter/local for version < 57731C.
// try 9: modeled player data block (+0x47A8 0x400, then 16 * 0x2D0 at +0x1AA8), legacy +0x4BA8 read quirk, +0x4BF4/+0x50F4/+0x5100 blocks.
// try 10: tested without /GX; object text size stayed 880B and still too small for compare. Restored /GX because original EH frame requires it.
// try 11: current source compiles but check_function cannot diff: configured original size 910 exceeds rebuilt .text size 880. Missing 30 bytes are likely exact EH/unwind or source-level version-gate shape, not a small localized drift.
// left in scratch: broad constructor/load behavior is reconstructed, but exact VC5 EH/context/source shape is unresolved. No accepted_drift: no byte diff available and object is size-short.

extern "C" void __cdecl rge_read(void* file, void* dst, int size);
extern const float DAT_00577318;
extern const float DAT_0057731c;
extern const float DAT_00577320;
extern const float DAT_00577324;
extern const float DAT_00577328;
extern const float DAT_0057732c;

class RGE_Game_World;
class RGE_Scenario {
public:
    RGE_Scenario(int, RGE_Game_World*);
};

class T_Scenario : public RGE_Scenario {
public:
    char gap_0004[0x0C-0x04];
    unsigned char byte_0c;
    char names[0x1000];              // +0x0d
    char gap_100d[0x1888-0x100d];
    float version;                   // +0x1888
    char gap_188c[0x18cc-0x188c];
    int old_matrix[16][4][4];        // +0x18cc, strided old format
    int matrix[16][4];               // +0x1990
    int count_1a90;                  // +0x1a90
    char blob_1a94[0x14];            // +0x1a94
    char player_data[16][0x2d0];     // +0x1aa8
    char buf_47a8[0x400];            // +0x47a8
    char buf_4ba8[0x40];             // +0x4ba8
    int field_4be8;                  // +0x4be8
    int field_4bec;                  // +0x4bec
    int field_4bf0;                  // +0x4bf0
    char buf_4bf4[0x500];            // +0x4bf4
    int field_50f4;                  // +0x50f4
    int field_50f8;                  // +0x50f8
    int field_50fc;                  // +0x50fc
    char buf_5100[0x40];             // +0x5100
    int field_5140;                  // +0x5140
    int field_5144;                  // +0x5144
    int field_5148;                  // +0x5148

    T_Scenario(int type, RGE_Game_World* world);
    void InitializeVictoryValues();
    void InitializeFriendlinessValues();
    void ClearDisabledTechnologies();
};

T_Scenario::T_Scenario(int type, RGE_Game_World* world) : RGE_Scenario(type, world) {
    void* file = (void*)type;
    *(void**)this = (void*)0x577308;
    InitializeVictoryValues();
    InitializeFriendlinessValues();
    ClearDisabledTechnologies();

    field_5140 = 0;
    field_5144 = 900;
    field_5148 = 9000;
    field_4be8 = 0;
    field_4bf0 = 0;

    if (!(version < DAT_00577318)) {
        int i;
        for (i = 0; i < 16; ++i) rge_read(file, names + i * 0x100, 0x100);
    }

    if (version < DAT_00577318) {
        int i;
        for (i = 0; i < 16; ++i) rge_read(file, matrix[i], 0x10);
    } else {
        int i;
        for (i = 0; i < 16; ++i) {
            rge_read(file, &old_matrix[i][2][0], 4);
            rge_read(file, matrix[i], 0x10);
            rge_read(file, &old_matrix[i][0][0], 4);
            rge_read(file, &old_matrix[i][1][0], 4);
            rge_read(file, &old_matrix[i][-1][0], 4);
        }
    }

    if (version < DAT_0057731c) {
        rge_read(file, &type, 4);
    }

    rge_read(file, blob_1a94, 0x18);
    rge_read(file, &field_4be8, 4);

    if (!(version < DAT_00577318)) {
        rge_read(file, &field_5140, 4);
        rge_read(file, &field_5144, 4);
        rge_read(file, &field_5148, 4);
    } else {
        field_5140 = 4;
        field_5144 = 900;
        field_5148 = 9000;
    }

    rge_read(file, buf_47a8, 0x400);
    for (int p = 0; p < 16; ++p) rge_read(file, player_data[p], 0x2d0);

    if (version < DAT_0057731c) rge_read(file, &type, 4);

    if (*(int*)&version == 0x3f8147ae) {
        for (int j = 0; j < 16; ++j) rge_read(file, buf_4ba8, 0x40);
    }
    if (!(version < DAT_0057731c)) rge_read(file, buf_4ba8, 0x40);
    if (version < DAT_00577320) rge_read(file, buf_4bf4, 0x500);

    if (version < DAT_00577324) {
        if (!(version < DAT_00577328)) {
            rge_read(file, &field_50f4, 4);
            field_50f8 = 0;
            field_50fc = 0;
        } else {
            rge_read(file, &field_50f4, 0x0c);
        }
    }
    if (version < DAT_0057732c) rge_read(file, buf_5100, 0x40);
    if (version < DAT_0057731c) rge_read(file, &type, 4);

    count_1a90 = byte_0c;
}
