// 004F8E20 TribeTacticalAIModule::updateGathererDistribution
// Attempt log:
// 1: broad reconstruction from packet: gatherer task counts, age/research special distribution, default weighted percentages, negative-share correction and final food/wood remainder split.
// 2: fixed zero-sized local class gap and compiled; best attempt reaches exact 1369-byte size.
// 3: first mismatch is frame/prologue: rebuilt uses 0x10 frame and pushes EDI before zeroing desired counts, while original uses 0x0C frame, delays EDI push, keeps zero in EAX and zero/index in EBP.
// 4: modeled gatherer stride 0x18, count +0x9CC, desired count +0x9D0, current task/target/priority fields, and resource-id validation scan.
// 5: modeled special cases for advancing ages/research readiness and the 5-priority retask stamping loops for nonzero/non-minus-one gatherers.
// 6: modeled default weighted distribution using integer percent division and late negative distribution correction/remainder split.
// 7: remaining mismatch is broad source/layout: original is highly ordered around explicit stack locals at esp+10/14/18, duplicated age2/age3/age4 blocks, magic multiply divisions, and shared tails; current source has behavior-like structure but wrong register/liveness/block layout. Not accepted_drift-safe.

typedef unsigned char uchar;

class UnitAI { public: int currentAction(); int currentTarget(); };
class ObjType { public: char gap[0x10]; short id; };
class RGE_Static_Object { public: char gap0[4]; int gameID; ObjType* type; UnitAI* unitAI(); };
class MainDecision { public: RGE_Static_Object* object(int); };
class BuildAI { public: int readyToResearch(int,int); };
class InfoAI { public: int numberGameIDsOwnedBy(int,int); };
class AgeAI { public: int ageTime(int); };

class TribeTacticalAIModule {
public:
    char gap0[0xF0]; MainDecision* md;
    char gapF4[0x368-0xF4]; int sn_food1; int sn_wood1; int sn_gold1; int sn_stone1;
    char gap378[0x404-0x378]; int sn_food2; int sn_wood2; int sn_gold2; int sn_stone2;
    char gap414[0x468-0x414]; int age2flag; int age3flag; int age4flag;
    char gap474[0x51C-0x474];
    struct G { int unit; int task; int priority; int target; int lastTask; int time; } gatherers[50];
    int numberGatherersValue; int desiredNumberGatherers;
    char gap9d4[0xD58-0x9D4]; int* resourceIds; int numberResourceIds; int fieldD60; int maxResourceIds;
    int desiredFood; int desiredWood; int desiredGold; int desiredStone;
    int desiredFood2; int desiredWood2; int desiredGold2; int desiredStone2;
    int negIndex[4]; int negValue[4];
    char gapDB8[0xFA4-0xDB8]; int specialGathererDistribution;
    int inAge(int);
    void updateGathererDistribution();
};

#define BUILD (*(BuildAI*)((char*)this->md + 0x104))
#define INFO (*(InfoAI*)((char*)this->md + 0xCEC))
#define AGE (*(AgeAI*)((char*)this->md + 0x10D7C))
#define AGE_RES (*(int*)((char*)this->md + 0x122C))

static int div100(int a, int b) { return (a*b)/100; }

void TribeTacticalAIModule::updateGathererDistribution()
{
    int i;
    int action;
    int task;
    int j;
    desiredFood=desiredWood=desiredGold=desiredStone=0;
    for (i=0;i<numberGatherersValue;i++) {
        G* g=&gatherers[i];
        RGE_Static_Object* o=md->object(g->unit);
        if (o && o->unitAI()) {
            action=o->unitAI()->currentAction();
            task=g->task;
            g->target=o->unitAI()->currentTarget();
            if (action==0x261 && o->type->id==0x103 && task) {
                int found=0;
                for (j=0;j<numberResourceIds && j<maxResourceIds;j++) if (resourceIds[j]==o->gameID) { found=1; break; }
                if (!found) { g->task=0; task=0; }
            }
            if (task>=0 && task<=3) {
                if (action==0x261 || action==0x265) ++((&desiredFood)[task]);
                else {
                    for (j=0;j<numberResourceIds && j<maxResourceIds;j++) if (resourceIds[j]==g->unit) { ++((&desiredFood)[task]); break; }
                }
            }
        }
    }

    desiredFood2=desiredWood2=desiredGold2=desiredStone2=0;
    int special=0;
    if (inAge(1) && age2flag==1) {
        special=1;
        if (BUILD.readyToResearch(2,1) && AGE_RES!=-1 && (AGE.ageTime(1)>120 || specialGathererDistribution==1)) {
            desiredFood2=desiredNumberGatherers;
            for (i=0;i<numberGatherersValue;i++) if (gatherers[i].task!=0 && gatherers[i].task!=-1) gatherers[i].priority=5;
            specialGathererDistribution=1;
        } else goto tryAge3;
    } else if (inAge(2) && age3flag==1) {
tryAge3:
        if (BUILD.readyToResearch(3,1) && (AGE.ageTime(1)>240 || (AGE.ageTime(1)>120 && AGE_RES<20))) {
            special=1; desiredWood2=desiredNumberGatherers;
            for (i=0;i<numberGatherersValue;i++) if (gatherers[i].task!=0 && gatherers[i].task!=-1) gatherers[i].priority=5;
            specialGathererDistribution=1;
        } else goto tryAge4;
    } else if (inAge(3) && age4flag==1) {
tryAge4:
        if (BUILD.readyToResearch(4,1)) {
            special=1; desiredWood2=desiredNumberGatherers/2; desiredGold2=desiredWood2;
            for (i=0;i<numberGatherersValue;i++) if (gatherers[i].task!=0 && gatherers[i].task!=3 && gatherers[i].task!=-1) gatherers[i].priority=5;
            specialGathererDistribution=1;
        } else { desiredFood2=desiredWood2=desiredGold2=desiredNumberGatherers/3; specialGathererDistribution=0; special=1; }
    } else specialGathererDistribution=0;

    if (!special) {
        desiredWood2=div100(sn_wood1+sn_wood2, desiredNumberGatherers);
        desiredGold2=div100(sn_gold1+sn_gold2, desiredNumberGatherers);
        desiredStone2=div100(sn_stone1+sn_stone2, desiredNumberGatherers);
        desiredFood2=div100(sn_food1+sn_food2, desiredNumberGatherers);
    }

    int sum=desiredFood2+desiredWood2+desiredGold2+desiredStone2;
    int rem=desiredNumberGatherers-sum;
    int negCount=0, negSum=0;
    for (i=0;i<4;i++) if (negValue[i]<0) { negSum -= negValue[i]; negIndex[negCount++]=i; }
    if (negCount>0) {
        for (i=0;i<negCount;i++) { int idx=negIndex[i]; (&desiredFood2)[idx] -= ((&negValue[0])[idx]*rem)/negSum; }
    }
    sum=desiredFood2+desiredWood2+desiredGold2+desiredStone2;
    rem=desiredNumberGatherers-sum;
    if (rem>0) {
        int half=rem/2; int other=half; if ((rem<0?-rem:rem)&1) other++;
        desiredFood2+=other; desiredWood2+=half;
    }
}
