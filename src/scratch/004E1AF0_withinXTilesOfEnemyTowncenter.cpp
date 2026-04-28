// TribeInformationAIModule::withinXTilesOfEnemyTowncenter (004E1AF0)
// PDB source: taiinfmd.cpp:6721-6744
// Size: 209 bytes
// Probe 3: Use while loop, merge checks

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char _pad0[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char _pad1[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

struct RGE_Player_VTable {
    virtual void dd00() = 0; virtual void dd01() = 0;
    virtual void dd02() = 0; virtual void dd03() = 0;
    virtual void dd04() = 0; virtual void dd05() = 0;
    virtual int vf18(int) = 0;
};

struct RGE_Static_Object {
    unsigned char gap_00[0x08];
    void* master_obj;
    void* owner;
    unsigned char gap_10[0x28];
    float x_pos;
    float y_pos;
};

struct TribeMainDecisionAIModule;

struct TribeInformationAIModule {
    unsigned char gap_00[0x100];
    TribeMainDecisionAIModule* md;
    unsigned char gap_104[0x0C];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;

    int withinXTilesOfEnemyTowncenter(RGE_Static_Object* obj, int tiles);
};

struct MainDecisionAIModule {
    unsigned char gap_00[0xF0];
    RGE_Player_VTable* player;
};

struct TribeMainDecisionAIModule : public MainDecisionAIModule {
};

int TribeInformationAIModule::withinXTilesOfEnemyTowncenter(RGE_Static_Object* obj, int tiles)
{
    int distSq = tiles * tiles;
    int objX = (int)obj->x_pos;
    int objY = (int)obj->y_pos;
    int max = maxImportantObjectMemory;
    int i = 0;

    while (i < max)
    {
        ObjectMemory* mem = &importantObjectMemory[i];
        if (mem->type == 109)
        {
            if (md->player->vf18(mem->owner))
            {
                int dx = (unsigned char)mem->x - objX;
                int dy = (unsigned char)mem->y - objY;
                if (dx * dx + dy * dy <= distSq)
                {
                    return 1;
                }
            }
        }
        i++;
    }
    return 0;
}
