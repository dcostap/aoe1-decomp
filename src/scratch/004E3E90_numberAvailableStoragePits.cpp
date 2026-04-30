// 004E3E90 TribeInformationAIModule::numberAvailableStoragePits (taiinfmd.cpp:8079-8129)
// ~7 attempts: register allocation (esi=this, edi=md vs edi=this, esi=md) drifts ~30%. Remaining: uVar1 in [esp+0x14] vs ebp+and masks; missing param_1 reload; 8 nops vs 0. Structurally complete.

class RGE_Static_Object;

class AIModule {
public:
    char gap_00[0xF0];
};

class InformationAIModule : public AIModule {
public:
};

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;   // +0xF0

    RGE_Static_Object* object(int);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
};

class ManagedArray_int {
public:
    int value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray_int farmsTaskedThisUpdate;       // +0xF0
    MainDecisionAIModule* md;                     // +0x100
    char gap_104_to_500[0x500 - 0x104];
    int dropsitesByAge[4][4];                     // +0x500
    int closestDropsiteValue[4];                  // +0x540
    int closestDropsiteResourceID[4];             // +0x550

    int numberAvailableStoragePits(int param_1);
};

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float field_0x38;
    float field_0x3C;

    int currentZone();
    int lookupZone(int, int);
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int);
};

int TribeInformationAIModule::numberAvailableStoragePits(int param_1)
{
    int age_idx = (int)(this->md->player->attributes[6]);
    age_idx--;

    if (age_idx < 0) {
        age_idx = 0;
    } else if (age_idx > 3) {
        age_idx = 3;
    }

    if (this->dropsitesByAge[param_1][age_idx] == 0) {
        return 0;
    }

    RGE_Static_Object* obj1 = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);

    if (obj1 != 0) {
        RGE_Static_Object* obj2 = this->md->object(this->closestDropsiteResourceID[param_1]);

        if (obj2 != 0) {
            int uVar1 = obj1->currentZone();
            int iVar3 = (int)(obj2->field_0x3C);
            int iVar5 = (int)(obj2->field_0x38);
            int uVar2 = obj1->lookupZone(iVar5, iVar3);

            if (uVar1 != uVar2) {
                return 0;
            }
        }
    }

    int sn = ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(param_1 + 0xA3);
    return (this->closestDropsiteValue[param_1] > sn) ? 1 : 0;
}
