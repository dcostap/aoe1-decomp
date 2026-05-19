// VA: 00416B80 UnitAIModule::moveTo(int,float,int)
// aiuaimod.cpp lines 3410-3428
// Retry 2026-05-19: replace raw __fastcall/free-function body with natural member-call surface
// copied from matched 00416AF0 shape and adjusted for 3-arg virtual canMoveTo.

class RGE_Static_Object {
public:
    char gap_00[0x38];
    int world_x;
    int world_y;
    int world_z;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class Unit {
public:
    virtual int vf00(); virtual int vf01(); virtual int vf02(); virtual int vf03();
    virtual int vf04(); virtual int vf05(); virtual int vf06(); virtual int vf07();
    virtual int vf08(); virtual int vf09(); virtual int vf10(); virtual int vf11();
    virtual int vf12(); virtual int vf13(); virtual int vf14(); virtual int vf15();
    virtual int vf16(); virtual int vf17(); virtual int vf18(); virtual int vf19();
    virtual int vf20(); virtual int vf21(); virtual int vf22(); virtual int vf23();
    virtual int vf24(); virtual int vf25(); virtual int vf26(); virtual int vf27();
    virtual int vf28(); virtual int vf29(); virtual int vf30(); virtual int vf31();
    virtual int vf32(); virtual int vf33(); virtual int vf34(); virtual int vf35();
    virtual int vf36(); virtual int vf37(); virtual int vf38(); virtual int vf39();
    virtual int vf40(); virtual int vf41(); virtual int vf42(); virtual int vf43();
    virtual int vf44(); virtual int vf45(); virtual int vf46(); virtual int vf47();
    virtual int vf48(); virtual int vf49(); virtual int vf50(); virtual int vf51();
    virtual int vf52(); virtual int vf53(); virtual int vf54(); virtual int vf55();
    virtual int vf56(); virtual int vf57(); virtual int vf58(); virtual int vf59();
    virtual int vf60(); virtual int vf61(); virtual int vf62(); virtual int vf63();
    virtual int vf64(); virtual int vf65(); virtual int vf66(); virtual int vf67();
    virtual int vf68(); virtual int vf69(); virtual int vf70(); virtual int vf71();
    virtual int vf72(); virtual int vf73(); virtual int vf74(); virtual int vf75();
    virtual int vf76(); virtual int vf77(); virtual int vf78(); virtual int vf79();
    virtual int vf80(); virtual int vf81(); virtual int vf82(); virtual int vf83();
    virtual int vf84(); virtual int vf85();
    virtual int canMoveTo(int id, float range, int flag);

    char gap_04[8];
    Player* owner;
};

class UnitAIModule {
public:
    Unit* objectValue;
    char gap_04[0x28];
    int currentActionValue;

    virtual int moveTo(int targetId, float range, int flag);
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int x, int y, int z);
};

int UnitAIModule::moveTo(int targetId, float range, int flag) {
    if (flag || this->currentActionValue == -1) {
        if (this->objectValue->canMoveTo(targetId, range, flag) == 1) {
            RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
            this->setCurrentAction(0x262);
            if (target == 0) {
                this->setCurrentTarget(targetId, 0, 0, 0);
                return 1;
            }
            this->setCurrentTarget(targetId, target->world_x, target->world_y, target->world_z);
            return 1;
        }
    }
    return 0;
}
