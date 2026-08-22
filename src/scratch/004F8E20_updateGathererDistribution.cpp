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
// 14: nested the age dispatch in original order and removed the incorrect age1-to-age3 and age2-to-age4 fallbacks; structural shape improved.
// 15: corrected the age4 no-research path to write desired distribution slots 0, 1, and 3, as shown by the original stores.
// 16: tested weighted percentage operand order; VC5 emitted the same arithmetic basin.
// 17: cached the proven object gameID after the action/type/state guard; this matches the original EDI overwrite before the first task-list scan and improved the first scan block.
// 18: separated literal actual-distribution clears from the outer loop index; this improved positional diff by four bytes but did not solve the prologue.
// 19: tried a structured found-label task scan to mirror the original skip-zero CFG; it worsened block shape and was rolled back.
// 20: declared the special-result local before the desired cursor; this improved whole-function liveness by seven bytes and remains plausible source order.
// 21: used pointer dereference spelling for first-slot desired writes; VC5 emitted a duplicate, so no codegen lead was found.
// 22: moved outer-index initialization between the first two clears to mirror stack-store order; it worsened codegen and was rolled back.
// Final clean reconstruction: natural typed ownership, corrected age dispatch and slot writes, 15 ordered calls aligned; remaining gap is structural prologue/CFG layout.
// Managed pass: 20 meaningful probes confirmed the pinned 1369-byte source as
// the best clean natural reconstruction (1237 positional bytes, 83.93% shape,
// 48.21% exact-block coverage, 15/15 ordered calls, and a 0x0C frame).
// Evidence-led layout correction: the resource scan fields include a proven
// DA8-DB8 gap, builtFirstGranary is at +F8C, and zoomingToNextAge is at +FA4.
// The earlier single-field model wrote the wrong member, even though its code
// size stayed equal. The corrected model improved exact blocks and is retained.
// Rejected managed probes: initialization reordering, found-label scan CFG,
// unsigned remainder parity, bool special flag, declaration-order changes,
// receiver aliases, sum-count aliases, nested age syntax, and standard-header
// combinations either worsened codegen or emitted the same bytes. Polymorphic
// donor-supported type surfaces also emitted the same bytes. The remaining
// blocker is structural prologue/register scheduling and the first-loop scan
// CFG, not call identity or field ownership.
// Follow-up worker validation: the pinned source still builds at 1369 bytes,
// with a 0x0C frame, 15 ordered calls, 83.93% shape, and 1237 differing bytes.
// Tested Ghidra-shaped task-scan labels, local_4 reuse for the negative count,
// initial-clear order, final remainder spellings, canonical sn-array layout,
// nested MainDecision ownership, and top-level object lifetime. The best new
// natural codegen was 1232 differing bytes but lost structural coverage; it
// was restored. The tested scan and prologue variants were worse or duplicate.

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
    char gapDA8[0xDB8-0xDA8];
    char gapDB8[0xF8C-0xDB8]; int builtFirstGranary;
    char gapF90[0xFA4-0xF90]; int specialGathererDistribution;
    int inAge(int);
    void updateGathererDistribution();
};

#define BUILD (*(BuildAI*)((char*)this->md + 0x104))
#define INFO (*(InfoAI*)((char*)this->md + 0xCEC))
#define RESOURCE (*(ResourceAI*)((char*)this->md + 0x10D7C))
#define AGE_RES (*(int*)((char*)this->md + 0x122C))

void TribeTacticalAIModule::updateGathererDistribution()
{
    int i;
    int gSTT;
    int gAction;
    int local_4=0;
    int* g;
    int* distribution;
    actualGathererDistribution[0]=0;
    actualGathererDistribution[1]=0;
    actualGathererDistribution[2]=0;
    actualGathererDistribution[3]=0;
    if (numberGatherersValue > 0) {
        g = &gatherers[0].data1;
        do {
            RGE_Static_Object* o=md->object(g[-1]);
            if (o && o->unitAI()) {
                gAction=o->unitAI()->currentAction();
                gSTT=g[0];
                g[3]=o->unitAI()->currentTarget();
                if (gAction==0x261 && o->type->id==0x103 && gSTT) {
                    int gameID=o->gameID;
                    for (i=0;i<unitsTaskedThisUpdate.numberValue && i<unitsTaskedThisUpdate.maximumSizeValue;i++)
                        if (unitsTaskedThisUpdate.value[i]==gameID) break;
                    if (i==unitsTaskedThisUpdate.numberValue || i==unitsTaskedThisUpdate.maximumSizeValue) { g[0]=0; }
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
    int special=0;
    *distribution=0;
    distribution[1]=0;
    distribution[2]=0;
    distribution[3]=0;
    if (inAge(1)) {
        if (age2flag==1) {
            if (BUILD.readyToResearch(2,1) && AGE_RES!=-1 && (RESOURCE.resource(1)>120 || builtFirstGranary==1)) {
                *distribution=desiredNumberGatherers;
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
                specialGathererDistribution=1;
                special=1;
            } else {
                specialGathererDistribution=0;
                distribution[1]=desiredNumberGatherers;
                special=1;
            }
        } else specialGathererDistribution=0;
    } else if (inAge(2)) {
        if (age3flag==1) {
            if (BUILD.readyToResearch(3,1) && (RESOURCE.resource(1)>240 || (RESOURCE.resource(1)>120 && AGE_RES<20))) {
                *distribution=desiredNumberGatherers;
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=-1) g[1]=5;
                specialGathererDistribution=1;
                special=1;
            } else {
                specialGathererDistribution=0;
                distribution[1]=desiredNumberGatherers;
                special=1;
            }
        } else specialGathererDistribution=0;
    } else if (inAge(3)) {
        if (age4flag==1) {
            if (BUILD.readyToResearch(4,1)) {
                *distribution=desiredNumberGatherers/2;
                distribution[3]=distribution[0];
                g=&gatherers[0].data1;
                for (i=0;i<numberGatherersValue;i++,g+=6) if (g[0]!=0 && g[0]!=3 && g[0]!=-1) g[1]=5;
                specialGathererDistribution=1;
                special=1;
            } else {
                *distribution=desiredNumberGatherers/3;
                distribution[1]=distribution[0];
                distribution[3]=distribution[0];
                specialGathererDistribution=0;
                special=1;
            }
        } else specialGathererDistribution=0;
    } else specialGathererDistribution=0;

    if (!special) {
        desiredGathererDistribution[2]=(sn_gold1+sn_gold2)*desiredNumberGatherers/100;
        desiredGathererDistribution[3]=(sn_wood1+sn_stone2)*desiredNumberGatherers/100;
        desiredGathererDistribution[1]=(sn_stone1+sn_wood2)*desiredNumberGatherers/100;
        desiredGathererDistribution[0]=(sn_food1+sn_food2)*desiredNumberGatherers/100;
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
