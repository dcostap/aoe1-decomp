// VA: 005059A0 TribePriestUnitAIModule::attackObject(int, int)
// PDB source: taiuaimd.cpp lines 1338-1349
// Default flags
//
// attempt log:
// Attempt 1: explicit vtable with void* vtable → shifted offsets by 4 (extra vtable ptr)
// Attempt 2: removed explicit void* vtable → TribePriestUnitAIModule offsets correct
// Attempt 3: UnitObject with gap_00[0xC] → shifted offsets by 4 (hidden vtable)
// Attempt 4: UnitObject with gap_04[0x8] → all offsets correct, 99/103 matching
// Attempt 5: float temp for vf10C result → 51 diff bytes (worse)
// Attempt 6: int cp temp → same 4-byte register diff
// Attempt 7: UnitObject* u temp → 51 diff bytes (worse)
//
// Remaining mismatch: 4 bytes of register allocation in vf10C call block:
//   Original: mov edx,[esp+14h]; push edx; mov eax,[ecx]; call [eax+10Ch]
//   Rebuild:  mov eax,[esp+14h]; push eax; mov edx,[ecx]; call [edx+10Ch]
// This is a stable register-color difference in VC5's virtual-call scheduling.

class RGE_Player {
public:
    int computerPlayer();
};

class UnitObject {
public:
    char gap_04[0x8];
    RGE_Player* ownerPlayer; // +0x0C
    // 67 vtable slots for vf10C at offset 0x10C
    virtual void vf00();  virtual void vf01();  virtual void vf02();  virtual void vf03();
    virtual void vf04();  virtual void vf05();  virtual void vf06();  virtual void vf07();
    virtual void vf08();  virtual void vf09();  virtual void vf10();  virtual void vf11();
    virtual void vf12();  virtual void vf13();  virtual void vf14();  virtual void vf15();
    virtual void vf16();  virtual void vf17();  virtual void vf18();  virtual void vf19();
    virtual void vf20();  virtual void vf21();  virtual void vf22();  virtual void vf23();
    virtual void vf24();  virtual void vf25();  virtual void vf26();  virtual void vf27();
    virtual void vf28();  virtual void vf29();  virtual void vf30();  virtual void vf31();
    virtual void vf32();  virtual void vf33();  virtual void vf34();  virtual void vf35();
    virtual void vf36();  virtual void vf37();  virtual void vf38();  virtual void vf39();
    virtual void vf40();  virtual void vf41();  virtual void vf42();  virtual void vf43();
    virtual void vf44();  virtual void vf45();  virtual void vf46();  virtual void vf47();
    virtual void vf48();  virtual void vf49();  virtual void vf50();  virtual void vf51();
    virtual void vf52();  virtual void vf53();  virtual void vf54();  virtual void vf55();
    virtual void vf56();  virtual void vf57();  virtual void vf58();  virtual void vf59();
    virtual void vf60();  virtual void vf61();  virtual void vf62();  virtual void vf63();
    virtual void vf64();  virtual void vf65();  virtual void vf66();
    virtual float vf10C(int param_1); // slot 67, offset 0x10C
};

class TribePriestUnitAIModule {
public:
    UnitObject* unit;         // +0x04 (hidden vtable at +0x00)
    char gap_08[0x20];        // +0x08 to +0x27
    int field_28;             // +0x28

    // vtable: 27 padding → vf6C(slot27) → 9 padding → vf94(slot37) → 11 padding → vfC4(slot49)
    virtual void vf00();  virtual void vf01();  virtual void vf02();  virtual void vf03();
    virtual void vf04();  virtual void vf05();  virtual void vf06();  virtual void vf07();
    virtual void vf08();  virtual void vf09();  virtual void vf10();  virtual void vf11();
    virtual void vf12();  virtual void vf13();  virtual void vf14();  virtual void vf15();
    virtual void vf16();  virtual void vf17();  virtual void vf18();  virtual void vf19();
    virtual void vf20();  virtual void vf21();  virtual void vf22();  virtual void vf23();
    virtual void vf24();  virtual void vf25();  virtual void vf26();
    virtual int vf6C(int param_1, int param_2); // slot 27, offset 0x6C
    virtual void vf28();  virtual void vf29();  virtual void vf30();  virtual void vf31();
    virtual void vf32();  virtual void vf33();  virtual void vf34();  virtual void vf35();
    virtual void vf36();
    virtual int vf94(int param_1, float param_2); // slot 37, offset 0x94
    virtual void vf38();  virtual void vf39();  virtual void vf40();  virtual void vf41();
    virtual void vf42();  virtual void vf43();  virtual void vf44();  virtual void vf45();
    virtual void vf46();  virtual void vf47();  virtual void vf48();
    virtual int vfC4(int param_1); // slot 49, offset 0xC4

    int attackObject(int param_1, int param_2);
};

int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    if (this->vfC4(param_1) == 0) {
        if (this->field_28 == -1) {
            if (this->unit->ownerPlayer->computerPlayer() != 0) {
                return this->vf94(param_1, this->unit->vf10C(param_2));
            }
        }
        return 0;
    }
    return this->vf6C(param_1, param_2);
}
