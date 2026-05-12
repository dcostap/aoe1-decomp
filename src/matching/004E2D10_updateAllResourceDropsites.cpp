// VA: 004E2D10
// PDB: taiinfmd.cpp lines 7422-7466
// updateAllResourceDropsites

class RGE_Master_Static_Object {
public:
    char gap_0[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_0[0x04];
    int id;
    RGE_Master_Static_Object* master_obj;
};

class MainDecisionAIModule {
public:
    char gap_0[0xF0];
    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

class ResourceMemory {
public:
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char _pad_07;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

// Matches per-resource-type layout from &resources[iter]
struct ResourceTypeBlock {
    ResourceMemory* resArray;   // +0x00
    char _pad0[0x0C];           // +0x04 to +0x0F  
    int count;                  // +0x10
    char _pad1[0x5C];           // +0x14 to +0x6F
    int closestValue;           // +0x70
    int _pad2[3];               // +0x74 to +0x7F
    int closestResID;           // +0x80
};

class TribeInformationAIModule {
public:
    char gap_0[0x100];
    TribeMainDecisionAIModule* md;
    char gap_104[0x4D0 - 0x104];
    ResourceMemory* resources[4];
    int numResources[4];
    int maxResources[4];
    int dropsitesByAge[16];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];

    float findClosestDropsite(RGE_Static_Object* obj, int mode, int* dropsiteID);
    void updateAllResourceDropsites();
};

extern float DAT_005755b8;
extern float DAT_005755bc;

void TribeInformationAIModule::updateAllResourceDropsites()
{
    int counter = 4;
    ResourceTypeBlock* rp = (ResourceTypeBlock*)&this->resources[0];

    do {
        int i = 0;
        int dropsiteID;

        rp->closestValue = -1;
        rp->closestResID = -1;

        if (rp->count > 0) {
            do {
                RGE_Static_Object* obj = this->md->object(rp->resArray[i].id);
                if (obj) {
                    dropsiteID = -1;
                    float dist = this->findClosestDropsite(obj, 1, &dropsiteID);
                    rp->resArray[i].gatherValue = (int)(DAT_005755bc - dist * DAT_005755b8);
                    rp->resArray[i].dropDistance = (unsigned char)(int)dist;
                    rp->resArray[i].dropsiteID = dropsiteID;

                    int grp = obj->master_obj->object_group;
                    if (grp == 0x0F) {
                        if ((int)dist < this->closestDropsiteValue[1] || this->closestDropsiteValue[1] == -1) {
                            this->closestDropsiteValue[1] = (int)dist;
                            this->closestDropsiteResourceID[1] = obj->id;
                        }
                    } else if (grp == 0x20) {
                        if ((int)dist < this->closestDropsiteValue[3] || this->closestDropsiteValue[3] == -1) {
                            this->closestDropsiteValue[3] = (int)dist;
                            this->closestDropsiteResourceID[3] = obj->id;
                        }
                    } else if (grp == 0x08) {
                        if ((int)dist < this->closestDropsiteValue[2] || this->closestDropsiteValue[2] == -1) {
                            this->closestDropsiteValue[2] = (int)dist;
                            this->closestDropsiteResourceID[2] = obj->id;
                        }
                    } else if (grp == 0x07) {
                        if ((int)dist < this->closestDropsiteValue[0] || this->closestDropsiteValue[0] == -1) {
                            this->closestDropsiteValue[0] = (int)dist;
                            this->closestDropsiteResourceID[0] = obj->id;
                        }
                    }
                }
                i++;
            } while (i < rp->count);
        }

        rp = (ResourceTypeBlock*)((int*)rp + 1);
        counter--;
    } while (counter != 0);
}
