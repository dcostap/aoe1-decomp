// 00506140 TribePriestUnitAIModule::processMisc
// PDB: taiuaimd.cpp:1761-1796, 247 bytes
// __thiscall, returns int, ret (no params)
// FLAGS: default
//
// Attempt log:
// probe 1-7: calling convention, locals, flow approaches
//
// Parked at 83%. Core logic is correct but calling convention and register
// allocation differences prevent exact match at single-function scope:
// 1. __fastcall for external thiscall functions adds `xor edx, edx` (2B × 3 calls)
// 2. Register for objPtr: original uses EDI (persistent), mine reloads from [esi+4]
//    (4 extra bytes per access)
// 3. Jump offsets differ from cumulative code size differences
// 4. Float constant address (relocation, masked by tool)
//
// Virtual calls (slots 4, 12, 22, 23) via thunk classes work correctly.
// Field layout confirmed: +0x04=objPtr, +0x28=field_28, +0x34=field_34, etc.

typedef unsigned char uchar;

extern int __fastcall computerPlayer(void* self, int);
extern uchar __fastcall have_action(void* self, int);
extern void* __fastcall get_action(void* self, int);
extern int __cdecl fprintf(void* file, const char* fmt, ...);

extern void* actionFile;

struct PriestThunk {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void func4(int, int, int, int, int, int, int, int, int, int, int);
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual int func12(int a, int b, int c);
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void func22(int a);
    virtual int func23(int a, int b);
};

struct TribePriestUnitAIModule {
    void* vtable;               // +0x00
    void* objPtr;               // +0x04: pointer to action object
    char pad_08[0x20];
    int field_28;               // +0x28
    int field_2C;               // +0x2C
    char pad_30[0x4];
    int field_34;               // +0x34: compared with foundID
    char pad_38[0x4];
    int field_3C;               // +0x3C
    int field_40;               // +0x40
    int field_44;               // +0x44: float compared with 100.0
    int field_48;               // +0x48
};

int __fastcall processMisc(TribePriestUnitAIModule* self, int) {
    if (computerPlayer(*(void**)((char*)self->objPtr + 0xC), 0) != 1)
        return 9;

    if (*(float*)((char*)self->objPtr + 0x44) < 100.0f)
        return 9;

    if (have_action(*(void**)((char*)self->objPtr + 0x184), 0) == 1) {
        if (*((uchar*)get_action(*(void**)((char*)self->objPtr + 0x184), 0) + 0xC) == 7)
            return 9;
    }

    int foundID = ((PriestThunk*)self)->func12(1, 1, 0);
    if (foundID == -1) return 9;
    if (self->field_34 == foundID) return 9;

    if (self->field_28 != -1) {
        ((PriestThunk*)self)->func4(
            *(int*)((char*)self->objPtr + 4),
            self->field_28,
            self->field_34,
            -1,
            self->field_3C,
            self->field_40,
            self->field_44,
            self->field_48,
            0,
            0,
            self->field_2C
        );

        if (actionFile) {
            fprintf(actionFile, "#%d call stopObject %s %d\n",
                    self->objPtr ? *(int*)((char*)self->objPtr + 4) : -1,
                    "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x6F8);
        }

        ((PriestThunk*)self)->func22(1);
    }

    return ((PriestThunk*)self)->func23(foundID, 1) == 1 ? 10 : 9;
}
