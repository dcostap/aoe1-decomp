#ifndef INFORMATION_DROPSITES_CONTEXT_H
#define INFORMATION_DROPSITES_CONTEXT_H

// Shared class surface for the ordered taiinfmd.cpp owners in information_dropsites_tu.cpp.
class RGE_Static_Object;

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

struct ResourceInfo {
    int id;
    char gap_04[9];
    unsigned char gone;
    unsigned char dropDistance;
    char gap_0f[1];
    int dropsiteID;
};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecisionAIModule* md;
    char gap_104[0x4D0 - 0x104];
    ResourceInfo* resources[4];
    int numResources[4];

    int importantUnit(int type_id);
    int dropsitesWithinRequiredDistance(int& numApplicableResources,
                                        int resourceType,
                                        int requiredDistance);
};

#endif
