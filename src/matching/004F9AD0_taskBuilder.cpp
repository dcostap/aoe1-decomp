// VA: 004F9AD0 TribeTacticalAIModule::taskBuilder
// PDB source: taitacmd.cpp lines 8257-8344
// attempt log:
// 1: natural decompiler-shaped source with local class stubs.
// 2: fixed vtable padding for RGE_Static_Object task slot +0x198 and AiPlayer builderTask +0xFC; /O2 /Oy remains 784B vs original 801B, extraction stops.
// 3: tried /GX and /O2 no /Oy: still 784B; /O1 shrinks to 706B; /Od reaches 801B but broad mismatch from offset 0 (wrong debug/EBP codegen), rolled back.
// 4: natural array-removal/tasked-update loops retained; behavior/call set plausible but exact source/register scheduling unresolved.
// 5: restored the binary-proven PlacementState anchor at +0xE4C and the
//    three-int XYZPoint task ABI; the previously dead z conversion is an
//    observed fifth __ftol call and the task record reserves 0x0c bytes.
// 6: restored md->player->world ownership (+0xF0/+0x3C) and the canonical
//    TribeConstructionAIModule placement offset (+0x6C4).
// 7: corrected task-failure cleanup to destroy the ConstructionItem argument,
//    as shown by the original +0xC parameter-home destructor call.
// 8: mirrored the same-TU indexed task scan and un-nested bounded growth copy;
//    these recover the target count/register topology and exact CFG.
// 9-10: typed PlacementState and used the donor's reference ABI for the direct
//    placeStructure relocation without changing emitted code.
// 11: replaced manual deleting-vtable calls with natural delete ConstructionItem;
//     default VC5 /O2 /Oy now matches 801/801 bytes exactly.
// FLAGS: config/flags/004F9AD0_taskBuilder.rsp (/nologo /c /O2 /Oy)
// Final: exact default-flags match; source retains named object/module ownership,
// natural same-TU ManagedArray-style loops, typed XYZPoint/PlacementState ABIs,
// and ordinary C++ cleanup. No inline asm or compiler-steering scaffolding.

typedef unsigned long ulong;
struct XYPoint { int x; int y; };
struct XYZPoint { int x; int y; int z; };
struct PlacementState { char gap[0x130]; };
class BuildItem { public: virtual void vd(int); int typeID(); int uniqueID(); float x(); float y(); void setInProgress(int); void setBuilt(int); };
class ConstructionItem { public: virtual ~ConstructionItem(); int typeID(); float x(); float y(); };
class TribeBuildAIModule { public: char gap[0x104]; BuildItem* nextBuildableItem(int); };
class TribeConstructionAIModule { public: char gap[0x6c4]; ConstructionItem* placeStructure(BuildItem*, int, PlacementState&, ulong); };
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_a)
#define VPAD4(n) VPAD2(n) VPAD2(n##_b)
#define VPAD8(n) VPAD4(n) VPAD4(n##_c)
#define VPAD16(n) VPAD8(n) VPAD8(n##_d)
#define VPAD32(n) VPAD16(n) VPAD16(n##_e)
#define VPAD64(n) VPAD32(n) VPAD32(n##_f)
class RGE_Static_Object { public: VPAD64(0) VPAD32(64) VPAD4(96) VPAD1(100) VPAD1(101) virtual int task(XYZPoint,int,int,int,int,int,int); char gap04[0x3c]; float z; void* unitAI(); };
class RGE_Game_World { public: RGE_Static_Object* object(int); };
class RGE_Player { public: char gap0[0x3c]; RGE_Game_World* world; };
class AiPlayer { public: VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e) VPAD1(f) virtual void builderTask(int,int,float,float,int); };
struct ModuleData { char gap0[0xf0]; RGE_Player* player; char gapf4[0x10]; TribeBuildAIModule buildAI; char gap608[0x4bc]; TribeConstructionAIModule constructionAI; char gapD88[0x117e4]; AiPlayer* aiPlayer; };
void* operator_new(unsigned int); void operator_delete(void*);

class TribeTacticalAIModule {
public:
    char gap0[0xf0]; ModuleData* md; char gapf4[0x10]; int* civilianValue; int civilianNumber; char gap10c[4]; int civilianMax;
    char gap114[0xc44]; int* taskedValue; int taskedNumber; char gapD60[4]; int taskedMax; char gapD68[0xdc]; int wonderInProgress; int wonderBuilt; PlacementState placementState;
    int civilian(XYPoint*, int, int, int, int, int);
    int taskBuilder(int id, BuildItem* item, ConstructionItem* con, ulong flags);
};

int TribeTacticalAIModule::taskBuilder(int id, BuildItem* item, ConstructionItem* con, ulong flags) {
    if (item == 0) {
        item = this->md->buildAI.nextBuildableItem(0);
        if (item == 0) return 0;
    }
    if (con == 0) {
        con = this->md->constructionAI.placeStructure(item, id, this->placementState, flags);
        if (con == 0) return 0;
    }
    if (id == -1) {
        XYPoint position;
        position.x = (int)con->x();
        position.y = (int)con->y();
        id = this->civilian(&position, 1, 0x2be, 0x2ce, 0x2bc, 0);
    }
    RGE_Static_Object* obj = this->md->player->world->object(id);
    if (obj == 0 || obj->unitAI() == 0) {
        if (con != 0) delete con;
        return 0;
    }
    int tx = (int)con->x();
    int ty = (int)con->y();
    int tz = (int)obj->z;
    XYZPoint p; p.x = tx; p.y = ty; p.z = tz; if (obj->task(p, 0x40000000, -1, 0, 1, -1, -1) == 0) {
        if (con != 0) delete con;
        return 0;
    }
    item->setInProgress(1);
    item->setBuilt(0);
    int count = this->civilianMax;
    int i = 0;
    if (count > 0) {
        while (i < count) { if (this->civilianValue[i] == id) break; i++; }
    }
    if (i < count) {
        if (i < count - 1) {
            do { this->civilianValue[i] = this->civilianValue[i+1]; i++; } while (i < this->civilianMax - 1);
        }
        this->civilianNumber--;
        if (this->civilianNumber < 0) this->civilianNumber = 0;
    }
    count = this->taskedNumber;
    for (i = 0; i < count; i++) {
        if (i >= this->taskedMax)
            break;
        if (this->taskedValue[i] == id)
            goto have;
    }
    if (count > this->taskedMax - 1) {
        int newMax = count + 1;
        int* p = (int*)operator_new(newMax * 4);
        if (p != 0) {
            for (i = 0; i < this->taskedMax && i < newMax; i++)
                p[i] = this->taskedValue[i];
            operator_delete(this->taskedValue);
            this->taskedValue = p; this->taskedMax = newMax;
        }
    }
    this->taskedValue[this->taskedNumber] = id;
    this->taskedNumber++;
have:
    if (con->typeID() == 0x114) this->wonderInProgress = 1;
    this->md->aiPlayer->builderTask(id, con->typeID(), con->x(), con->y(), item->uniqueID());
    if (con != 0) delete con;
    return 1;
}
