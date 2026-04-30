// TribeInformationAIModule::placeDock (004D9B20)
// PDB source: taiinfmd.cpp:1678-1811
// Size: 922 bytes

struct ConstructionItem {
    unsigned char g0[0x80];
    ConstructionItem(float a, float b, float c, float d, float e, float f, int g, char* h);
};

struct BuildItem;

struct BaseItem {
    char* name();
    int typeID();
    float xSize();
    float ySize();
    float zSize();
};

struct TribeInformationAIModule {
    ConstructionItem* placeDock(BuildItem* p1, float p2, float p3, int p4, int p5);
};

ConstructionItem* TribeInformationAIModule::placeDock(BuildItem* p1, float p2, float p3, int p4, int p5)
{
    unsigned char zoneCounter[256];
    int i;
    for (i = 0; i < 64; i++) {
        ((int*)zoneCounter)[i] = -1;
    }
    ConstructionItem* result = new ConstructionItem(1.0f, 2.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0, 0);
    return result;
}
