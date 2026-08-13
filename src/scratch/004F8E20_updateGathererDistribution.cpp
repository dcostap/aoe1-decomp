// 004F8E20 TribeTacticalAIModule::updateGathererDistribution
// Attempt log:
// 1: broad reconstruction from packet: gatherer task counts, age/research special distribution, default weighted percentages, negative-share correction and final food/wood remainder split.
// 2: fixed zero-sized local class gap and compiled; best attempt reaches exact 1369-byte size.
// 3: first mismatch is frame/prologue: rebuilt uses 0x10 frame and pushes EDI before zeroing desired counts, while original uses 0x0C frame, delays EDI push, keeps zero in EAX and zero/index in EBP.
// 4: modeled gatherer stride 0x18, count +0x9CC, desired count +0x9D0, current task/target/priority fields, and resource-id validation scan.
// 5: modeled special cases for advancing ages/research readiness and the 5-priority retask stamping loops for nonzero/non-minus-one gatherers.
// 6: modeled default weighted distribution using integer percent division and late negative distribution correction/remainder split.
// 7: remaining mismatch is broad source/layout: original is highly ordered around explicit stack locals at esp+10/14/18, duplicated age2/age3/age4 blocks, magic multiply divisions, and shared tails; current source has behavior-like structure but wrong register/liveness/block layout. Not accepted_drift-safe.
// 8: replaced the first resource-ID boolean temporary with the bounded scan index as the natural not-found guard; frame reached 0x0C and positional diff improved, but the research call surface remains unresolved.
// 9: replaced guessed ageTime calls with the proven resource(1) calls and inlined the four percent products; all 15 direct call sites now align.
// 10: modeled UnitData, ManagedArray ownership, and the proven data1 cursor; the gatherer stride/address shape improved and the source remains period-plausible.
// 11: rewrote distribution totals and negative-resource correction as pointer loops; exact-block coverage improved to 43.37%, but the prologue remains structurally different.
// 12: retained the desired-distribution cursor and corrected array index ownership from original stores; current structural best is 1258 bytes (91.8919%) with 100% ordered-call alignment.
// 13: tested explicit absolute-remainder parity; it improved positional diff by one byte but reduced shape slightly, and remains the current clean reconstruction after the 10-hypothesis budget.

typedef unsigned char uchar;

class UnitAI { public: int currentAction(); int currentTarget(); };
class ObjType { public: char gap[0x10]; short id; };
class RGE_Static_Object { public: char gap0[4]; int gameID; ObjType* type; UnitAI* unitAI(); };
class MainDecision { public: RGE_Static_Object* object(int); };
class BuildAI { public: int readyToResearch(int,int); };
class InfoAI { public: int numberGameIDsOwnedBy(int,int); };
class ResourceAI { public: int resource(int) const; };
struct UnitData { int id; int data1; int data2; int data3; int data4; int data5; };
struct ManagedArrayInt { int* value; int numberValue; int desiredNumberValue; int maximumSizeValue; };

class TribeTacticalAIModule {
public:
    char gap0[0xF0]; MainDecision* md;
    char gapF4[0x368-0xF4]; int sn_food1; int sn_wood1; int sn_gold1; int sn_stone1;
    char gap378[0x404-0x378]; int sn_food2; int sn_wood2; int sn_gold2; int sn_stone2;
    char gap414[0x468-0x414]; int age2flag; int age3flag; int age4flag;
    char gap474[0x51C-0x474];
    UnitData gatherers[50];
    int numberGatherersValue; int desiredNumberGatherers;
    char gap9d4[0xD58-0x9D4]; ManagedArrayInt unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4]; int resourceDifferenceValue[4];
    char gapDB8[0xFA4-0xDB8]; int specialGathererDistribution;
    int inAge(int);
    void updateGathererDistribution();
};

#define BUILD (*(BuildAI*)((char*)this->md + 0x104))
#define INFO (*(InfoAI*)((char*)this->md + 0xCEC))
#define RESOURCE (*(ResourceAI*)((char*)this->md + 0x10D7C))
#define AGE_RES (*(int*)((char*)this->md + 0x122C))

void TribeTacticalAIModule::updateGathererDistribution()
{
    int i=0;
    int gSTT;
    int gAction;
    int local_4;
    int* g;
    int* distribution;
    actualGathererDistribution[0]=i;
    actualGathererDistribution[1]=i;
    local_4=i;
    actualGathererDistribution[2]=i;
    actualGathererDistribution[3]=i;
    if (numberGatherersValue > 0) {
        g = &gatherers[0].data1;
        do {
            RGE_Static_Object* o=md->object(g[-1]);
            if (o && o->unitAI()) {
                gAction=o->unitAI()->currentAction();
                gSTT=g[0];
                g[3]=o->unitAI()->currentTarget();
                if (gAction==0x261 && o->type->id==0x103 && gSTT) {
                    for (i=0;i<unitsTaskedThisUpdate.numberValue && i<unitsTaskedThisUpdate.maximumSizeValue;i++)
                        if (unitsTaskedThisUpdate.value[i]==o->gameID) break;
                    if (i==unitsTaskedThisUpdate.numberValue || i==unitsTaskedThisUpdate.maximumSizeValue) { g[0]=0; gSTT=0; }
                }
                if (gSTT>=0 && gSTT<=3) {
                    if (gAction==0x261 || gAction==0x265) ++actualGathererDistribution[gSTT];
                    else {
                        for (i=0;i<unitsTaskedThisUpdate.numberValue && i<unitsTaskedThisUpdate.maximumSizeValue;i++) if (unitsTaskedThisUpdate.value[i]==g[-1]) { ++actualGathererDistribution[gSTT]; break; }
                    }
                }
            }
            local_4++;
            g += 6;
        } while (local_4 < numberGatherersValue);
    }

    distribution=desiredGathererDistribution;
    distribution[0]=0;
    distribution[1]=0;
    distribution[2]=0;
    distribution[3]=0;
    int special=0;
    if (inAge(1) && age2flag==1) {
        special=1;
        if (BUILD.readyToResearch(2,1) && AGE_RES!=-1 && (RESOURCE.resource(1)>120 || specialGathererDistribution==1)) {
            distribution[0]=desiredNumberGatherers;
            g=&gatherers[0].data1;
            for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
            specialGathererDistribution=1;
        } else goto tryAge3;
    } else if (inAge(2) && age3flag==1) {
tryAge3:
        if (BUILD.readyToResearch(3,1) && (RESOURCE.resource(1)>240 || (RESOURCE.resource(1)>120 && AGE_RES<20))) {
            special=1; distribution[0]=desiredNumberGatherers;
            g=&gatherers[0].data1;
            for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
            specialGathererDistribution=1;
        } else goto tryAge4;
    } else if (inAge(3) && age4flag==1) {
tryAge4:
        if (BUILD.readyToResearch(4,1)) {
            special=1; distribution[0]=desiredNumberGatherers/2; distribution[3]=distribution[0];
            g=&gatherers[0].data1;
            for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=3 && g[0]!=-1) g[1]=5;
            specialGathererDistribution=1;
        } else { distribution[0]=distribution[2]=distribution[3]=desiredNumberGatherers/3; specialGathererDistribution=0; special=1; }
    } else specialGathererDistribution=0;

    if (!special) {
        desiredGathererDistribution[2]=(sn_gold2+sn_gold1)*desiredNumberGatherers/100;
        desiredGathererDistribution[3]=(sn_stone2+sn_wood1)*desiredNumberGatherers/100;
        desiredGathererDistribution[1]=(sn_wood2+sn_stone1)*desiredNumberGatherers/100;
        desiredGathererDistribution[0]=(sn_food2+sn_food1)*desiredNumberGatherers/100;
    }

    int sum=0;
    distribution = desiredGathererDistribution;
    for (i=4;i!=0;i--) { sum += *distribution; distribution++; }
    int rem=desiredNumberGatherers-sum;
    int negCount=0, negSum=0;
    int* difference = resourceDifferenceValue;
    for (i=4;i!=0;i--) {
        if (*difference<0) { negSum -= *difference; negCount++; }
        difference++;
    }
    if (negCount>0) {
        int count=negCount;
        int* needed=neededResourceValue;
        do {
            int idx=*needed++;
            desiredGathererDistribution[idx] -= (resourceDifferenceValue[idx]*rem)/negSum;
            count--;
        } while (count!=0);
    }
    sum=0;
    distribution=desiredGathererDistribution;
    for (i=4;i!=0;i--) { sum += *distribution; distribution++; }
    rem=desiredNumberGatherers-sum;
    int odd=rem;
    if (odd<0) odd=-odd;
    if (rem>0) {
        int half=rem/2; int other=half; if (odd&1) other++;
        desiredGathererDistribution[0]+=other; desiredGathererDistribution[1]+=half;
    }
}
