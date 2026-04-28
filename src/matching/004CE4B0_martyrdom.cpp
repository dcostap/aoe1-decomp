// 004CE4B0 TRIBE_Action_Convert::martyrdom
// Size: 123 bytes

extern void* rge_base_game;

class RGE_Base_Game_Hack {
public:
    virtual ~RGE_Base_Game_Hack();
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
    virtual void basegame_slot16(int a, int b, int c, int d, int e); // slot 16 (0x40)
};

class TargetObj_Hack {
public:
    virtual ~TargetObj_Hack();
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
    virtual void target_slot17(void* a); // slot 17 (0x44)
};

class PlayerObj_Hack {
public:
    virtual ~PlayerObj_Hack();
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
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void player_slot30(int a, float b, int c); // slot 30 (0x78)
};

class SourceObj_Hack {
public:
    virtual ~SourceObj_Hack();
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
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void source_slot32(int a, int b); // slot 32 (0x80)
};

class TRIBE_Action_Convert_Base {
public:
    virtual ~TRIBE_Action_Convert_Base();
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
    virtual void vf58();
    virtual void this_slot23(int a); // slot 23 (0x5C)
};

class TRIBE_Action_Convert : public TRIBE_Action_Convert_Base {
public:
    void martyrdom();
    char gap_04[4];              // +0x04
    void* source_obj;            // +0x08
    char field_0C;               // +0x0C
    char gap_0D[3];
    void* target_obj;            // +0x10
};

void TRIBE_Action_Convert::martyrdom() {
    if (*(char*)((int)this + 0x0C) != 7) {
        return;
    }
    if (*(void**)((int)this + 0x10) == 0) {
        return;
    }
    if (*(short*)(*(int*)(*(int*)((int)this + 0x10) + 8) + 0x14) == 0x12) {
        return;
    }

    int target_id = *(short*)(*(int*)(*(int*)((int)this + 0x10) + 0x0C) + 0x4A);
    int src_id = *(short*)(*(int*)(*(int*)((int)this + 8) + 0x0C) + 0x4A);

    ((RGE_Base_Game_Hack*)rge_base_game)->basegame_slot16(0x7B, src_id, target_id, 0, 0);
    ((TargetObj_Hack*)(*(void**)((int)this + 0x10)))->target_slot17(*(void**)(*(int*)((int)this + 8) + 0x0C));
    ((PlayerObj_Hack*)(*(void**)(*(int*)((int)this + 8) + 0x0C)))->player_slot30(0x29, 1.0f, 0);
    ((SourceObj_Hack*)(*(void**)((int)this + 8)))->source_slot32(0x22, 0);
    ((TRIBE_Action_Convert_Base*)this)->this_slot23(3);
}
