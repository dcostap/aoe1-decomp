// 004E21E0 TribeInformationAIModule::setupLOSMap
// taiinfmd.cpp:7032-7076
// Status: scratch / not exact.
// Attempt log:
// - Natural implementation with losMap.initialize/setReferencePoint, importantObjectMemory scan, md->object lookup, ftol radius/x/y, vf[0x108] float test, incrementValue, maxValue gets exact size (269) and 13.01% positional / 14.87% edit diff.
// - Prologue, losMap setup, loop frame, null-object path, final loop increment, and maxValue tail are largely aligned.
// - First persistent drift is loop entry register allocation/order: original loads importantObjectMemory into EDX, offset into EAX, then owner param into EDX and zero-extends owner byte into ECX; rebuilt uses EAX for base and EDX for offset/byte. Tried separate mem local, char* field, and compare operand swap; compare swap improved one byte but allocation remained.
// - Tried reordering radius/x/y integer calculations to match original `fld y; mov ebx,eax; lea ecx,[edi+eax]; sub ebx,edi; store maxX; ftol`; source variants either kept current call-before-integer scheduling or caused a larger shifted diff.
// - Tried explicit UnitTypeInfo temp/yfloat temp; worsened to ~47% positional by shortening the middle block.
// - Promoted ObjectMemory and RGE master/object layouts from the local gaps; bytes were unchanged.
// - Reordered bound declarations, raw id/owner record access, split base/record setup, and a focused
//   36-variant lab over record/master/bounds/virtual spellings; no emitted group reached the original.
// - Final clean source keeps the canonical typed ObjectMemory stride and natural bound locals; remaining
//   drift is VC5 register allocation/FPU scheduling at loop entry and the three bound conversions.
// - Remaining blocker: VC5 register allocation and scheduling in the object-memory entry check plus FPU/int interleaving before incrementValue.
// - Main-agent audit restored canonical InfluenceMap/master/object/AI destructor
//   surfaces; the validated 39-byte codegen gap is unchanged.
// - Session probe: retaining only the binary-indicated maxX local and inlining
//   the other bounds removed the proven 8-byte frame and regressed to 258 diff;
//   restored the natural bound-local source.
// - Main-agent audit replaced the raw influence-map address and byte-offset
//   record cursor with canonical symbol ownership and typed array indexing.

typedef unsigned char uchar;

class InfluenceMap {
public:
    virtual ~InfluenceMap();
    int initialize(uchar param);
    void setReferencePoint(int x, int y);
    int incrementValue(int min_x, int min_y, int max_x, int max_y, int flag);
    int maxValue(void);
};

extern InfluenceMap* losMap;

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x24];
    float los;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void vf004(); virtual void vf008(); virtual void vf00C();
    virtual void vf010(); virtual void vf014(); virtual void vf018(); virtual void vf01C();
    virtual void vf020(); virtual void vf024(); virtual void vf028(); virtual void vf02C();
    virtual void vf030(); virtual void vf034(); virtual void vf038(); virtual void vf03C();
    virtual void vf040(); virtual void vf044(); virtual void vf048(); virtual void vf04C();
    virtual void vf050(); virtual void vf054(); virtual void vf058(); virtual void vf05C();
    virtual void vf060(); virtual void vf064(); virtual void vf068(); virtual void vf06C();
    virtual void vf070(); virtual void vf074(); virtual void vf078(); virtual void vf07C();
    virtual void vf080(); virtual void vf084(); virtual void vf088(); virtual void vf08C();
    virtual void vf090(); virtual void vf094(); virtual void vf098(); virtual void vf09C();
    virtual void vf0A0(); virtual void vf0A4(); virtual void vf0A8(); virtual void vf0AC();
    virtual void vf0B0(); virtual void vf0B4(); virtual void vf0B8(); virtual void vf0BC();
    virtual void vf0C0(); virtual void vf0C4(); virtual void vf0C8(); virtual void vf0CC();
    virtual void vf0D0(); virtual void vf0D4(); virtual void vf0D8(); virtual void vf0DC();
    virtual void vf0E0(); virtual void vf0E4(); virtual void vf0E8(); virtual void vf0EC();
    virtual void vf0F0(); virtual void vf0F4(); virtual void vf0F8(); virtual void vf0FC();
    virtual void vf100(); virtual void vf104();
    virtual float vf108();

    int id;                  // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x38 - 0x0C];
    float x;                // +0x38
    float y;                // +0x3C
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    RGE_Static_Object* object(int id);
};

struct ObjectMemory {
    int id;                 // +0
    short type;              // +0x04
    short group;             // +0x06
    unsigned char x;         // +0x08
    unsigned char y;         // +0x09
    unsigned char z;         // +0x0A
    uchar owner;            // +0x0B
    short hitPoints;        // +0x0C
    char gap_0E[2];
    int attackAttempts;     // +0x10
    uchar kills;             // +0x14
    char gap_15[3];
    float damageCapability; // +0x18
    float rateOfFire;       // +0x1C
    float range;            // +0x20
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x100 - 0x04];
    MainDecisionAIModule* md;                 // +0x100
    char gap_104[0x110 - 0x104];
    int maxImportantObjectMemory;             // +0x110
    ObjectMemory* importantObjectMemory;      // +0x114

    int setupLOSMap(int owner, int refX, int refY);
};

int TribeInformationAIModule::setupLOSMap(int owner, int refX, int refY)
{
    losMap->initialize(0);
    losMap->setReferencePoint(refX, refY);

    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* mem = &this->importantObjectMemory[i];
            if ((unsigned int)owner == (unsigned int)mem->owner) {
                RGE_Static_Object* obj = this->md->object(mem->id);
                if (obj != 0) {
                    int range = (int)obj->master_obj->los;
                    int objX = (int)obj->x;
                    int objY = (int)obj->y;
                    int maxX = range + objX;
                    int minX = objX - range;
                    int minY = objY - range;
                    int maxY = range + objY;
                    int flag;
                    if (obj->vf108() > 0.0f) {
                        flag = 5;
                    } else {
                        flag = 1;
                    }
                    losMap->incrementValue(minX, minY, maxX, maxY, flag);
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return losMap->maxValue();
}
