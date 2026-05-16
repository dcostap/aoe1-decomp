// VA: 00507640 TribeSoldierUnitAIModule::processIdle
// Attempt log:
// try 1: natural reconstruction from packet/Ghidra using virtual slots and direct member surfaces.
// try 2: raw __thiscall function-pointer casts failed on VC5 C4234; replaced with padded virtual declarations.
// try 3: padded UnitAIModule vtable slots 12/16/23/39/55 and RGE_Static_Object slot 63 so source compiles naturally.
// try 4: natural source compiles but text is too small (432 vs 564); final FPU pursuit/retreat math is not shaped like original.
// try 5: /GX tested; no change and not justified, removed.
// try 6: volatile temp probe made exact-size possible but introduced artificial prologue/frame code and was rolled back as a padding-like hack.
// try 7: self/local object-pointer variants did not recover original push ecx + esi=this prologue while preserving size.
// try 8: direct member calls for computerPlayer/inGroup/scenario/singlePlayer modeled; broad call scheduling remains.
// try 9: final move-to-position expression modeled behaviorally, but VC5 emits sqrt helper/high-level expression family rather than original hand-scheduled FPU stack sequence.
// try 10: leaving clean behavioral source in scratch rather than artificial exact-size volatile padding; not accepted-drift-safe.

extern void* rge_base_game;
extern "C" double __cdecl sqrt(double);

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;

class RGE_Base_Game { public: int scenarioGame(); int singlePlayerGame(); };
class RGE_Game_World { public: int difficultyLevel(); RGE_Static_Object* object(int id); };
class RGE_Player {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual int vt3C(int);
    int computerPlayer();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short civilization;
};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual int vt3C(int);
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vt9C(float, float, void*, int, int);
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC();
    virtual void vfF0(); virtual void vfF4(); virtual void vfF8(); virtual void vfFC();
    char gap_04[4];
    void* master;
    RGE_Player* player;
    short type;
    char gap_12[0x38-0x12];
    float x;
    float y;
    int z;
    int inGroup();
};

class UnitAIModule {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual int findTarget(int,int,int);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual int findTarget2(int,int,int,int,int);
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual int setTarget(int,int);
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void moveTo(float,float,RGE_Static_Object*,int,int);
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual int stateType();
    RGE_Static_Object* object;
    char gap_08[0x20];
    int actionType;
    int processIdle(int param);
};

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    virtual int getClass(); // not real index; unused direct vtable via inherited layout may shift
    int processIdle(int param);
};

int TribeSoldierUnitAIModule::processIdle(int param)
{
    if (param == 1) {
        if (this->stateType() == 8) {
            return 6;
        }
    }
    RGE_Player* player = this->object->player;
    if (player->civilization == 0) return 5;
    if (!player->computerPlayer()) {
        if (this->object->type == 0x12B) return 5;
    }
    if (this->actionType == 0x2D5) {
        short t = this->object->type;
        if (t == 0x23 || t == 0x24 || t == 0xFA) return 5;
    }
    int id = this->findTarget(1,0,0);
    if (id != -1) {
        if (this->setTarget(id,1) == 1) return 6;
    }
    if (!this->object->player->computerPlayer()) return 5;
    if (this->object->inGroup() == 1) return 5;
    this->object->player->world->difficultyLevel();
    if (((RGE_Base_Game*)rge_base_game)->scenarioGame() == 1 && ((RGE_Base_Game*)rge_base_game)->singlePlayerGame() == 1) {
        if (!this->object->player->vt3C(0x8F)) return 5;
    }
    if (((RGE_Base_Game*)rge_base_game)->singlePlayerGame() == 1) {
        if (!this->object->player->vt3C(0x8F)) return 5;
    }
    if (this->actionType == 0x2BD || this->actionType == 0x2D5) return 5;
    int target = this->findTarget2(-1,-1,-1,-1,0);
    if (target == -1) return 5;
    RGE_Static_Object* obj = this->object->player->world->object(target);
    if (obj == 0) return 5;
    this->object->vfFC();
    float yd = obj->y - this->object->y;
    float xd = obj->x - this->object->x;
    float dist = (float)sqrt((double)(xd*xd + yd*yd));
    float scale = 1.0f / dist;
    float nx = this->object->x - (xd * scale * 0.0f);
    float ny = this->object->y - (yd * scale * 0.0f);
    this->moveTo(nx, ny, this->object, this->object->z, 1);
    return 6;
}
