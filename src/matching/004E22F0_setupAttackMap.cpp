// 004E22F0 TribeInformationAIModule::setupAttackMap
// Source: taiinfmd.cpp lines 7081-7114
// Attempt log:
// initial: 74% diff â€” missing dispatch table pointer on all classes, wrong offsets.
// added virtuals: offsets correct, 75% diff.
// do-while + i at function scope: push edi/ebp now inside if body, 52% diff.
// tried base+offset separation; direct field access via attackMemories[]: 14.5% diff.
// FLAGS: none
// Left in scratch: remaining diff is register allocation (edx vs ecx for md ptr)
// and instruction scheduling (byte read interleaved with md->attackInfo load).
// First condition (targetOwner compare) and full prologue/loop are byte-identical.
// Extern relocations masked (8).

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class InfluenceMap {
public:
    int initialize(unsigned char param);
    void setReferencePoint(int x, int y);
    int incrementValue(int min_x, int min_y, int max_x, int max_y, int flag);
    int maxValue();
};

#endif
struct AttackMapStruct {
    char gap_00[0x4A];
    unsigned short compareOwner;  // +0x4A
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    AttackMapStruct* attackInfo;   // +0xF0
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0xFC];
    MainDecisionAIModule* md;           // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;       // +0x110
    void* importantObjectMemory;        // +0x114
    char gap_118[0xE4];
    int maxAttackMemories;              // +0x1FC
    char* attackMemories;               // +0x200 (array of 0x18-byte entries)

    int setupAttackMap(int param_1, int param_2, int param_3);
};
#endif

#endif
int TribeInformationAIModule::setupAttackMap(int param_1, int param_2, int param_3)
{
    attackMap->initialize(0);
    attackMap->setReferencePoint(param_2, param_3);

    int i = 0;
    if (this->maxAttackMemories > 0) {
        int offset = 0;
        do {
            if ((unsigned char)((char*)this->attackMemories)[offset + 0x0A] == (unsigned int)param_1) {
                MainDecisionAIModule* md = (MainDecisionAIModule*)this->md;
                volatile AttackMapStruct* info = md->attackInfo;
                unsigned short owner = (unsigned char)((char*)this->attackMemories)[offset + 0x09];
                if (owner == info->compareOwner) {
                    attackMap->incrementValue(
                        (unsigned char)((char*)this->attackMemories)[offset + 0x05],
                        (unsigned char)((char*)this->attackMemories)[offset + 0x06],
                        (unsigned char)((char*)this->attackMemories)[offset + 0x07],
                        (unsigned char)((char*)this->attackMemories)[offset + 0x08],
                        1);
                }
            }
            i++;
            offset += 0x18;
        } while (i < this->maxAttackMemories);
    }

    return attackMap->maxValue();
}
