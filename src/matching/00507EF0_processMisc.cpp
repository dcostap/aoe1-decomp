// 00507EF0 TribeArtifactUnitAIModule::processMisc
// Source: taiuaimd.cpp lines 2897-2919
// protected: virtual int __thiscall TribeArtifactUnitAIModule::processMisc(void)
//
// Attempt log:
// Probe 1: natural shape with virtual calls at slots 22 (0x58) and 53 (0xD4), default flags

#include "..\..\include\game_globals.h"

extern FILE* actionFile;

#ifndef TAIUAIMD_COMPLETE_TU
#include "../../include/taiuaimd_context.h"

// TribeArtifactUnitAIModule size 0x134
class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    virtual int getActionState(int);
    int field_F8;
};
#endif

int TribeArtifactUnitAIModule::processMisc()
{
    if (this->getActionState(1) == 6) {
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int value;
#ifdef TAIUAIMD_COMPLETE_TU
            if (this->obj != 0) {
                value = *(int*)((char*)this->obj + 4);
            } else {
                value = -1;
            }
#else
            if (this->objectValue != 0) {
                value = this->objectValue->id;
            } else {
                value = -1;
            }
#endif
            fprintf(actionFile, "#%d call stopObject %s %d\n", value, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0xB60);
        }
        this->stopObject(1);
        this->field_F8 = 0;
        return 10;
    }
    return 9;
}
