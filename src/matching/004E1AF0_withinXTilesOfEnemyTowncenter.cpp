// TribeInformationAIModule::withinXTilesOfEnemyTowncenter (004E1AF0)
// PDB source: taiinfmd.cpp:6721-6744
// Size: 209 bytes
// Probe 6: No caching, direct member access only

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct ObjMem {
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

#endif
#ifndef TAIINFMD_PREFIX_CONTEXT
struct TribeInformationAIModule {
    unsigned char g0[0x100];
    TMainDM* md;
    unsigned char g1[0x0C];
    int max;
    ObjMem* mems;

    int withinXTilesOfEnemyTowncenter(RGE_Obj* obj, int tiles);
};
#endif

#endif
int TribeInformationAIModule::withinXTilesOfEnemyTowncenter(RGE_Obj* obj, int tiles)
{
    int dsq = tiles * tiles;
    int ox = (int)obj->x_pos;
    int oy = (int)obj->y_pos;

    for (int i = 0; i < max; i++)
    {
        if (mems[i].type != 109)
            continue;
        if (!md->player->query18(mems[i].owner))
            continue;
        int dx = (unsigned char)mems[i].x - ox;
        int dy = (unsigned char)mems[i].y - oy;
        if (dx * dx + dy * dy <= dsq)
            return 1;
    }
    return 0;
}
