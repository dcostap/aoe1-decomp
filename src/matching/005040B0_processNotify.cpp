// VA: 005040B0 TribePreditorUnitAIModule::processNotify
// taiuaimd.cpp:216-258
//
// Attempt log:
// v0: Initial implementation - RGE_Static_Object missing vtable caused wrong offsets, fcomp branch inverted
// v1: Added virtual to RGE_Static_Object, fixed fcomp branch to !(dist>range)
// v2: Canonical fields and slots preserve exact bytes and the protected MAE symbol.

#include <cstdio>
#include "../../include/taiuaimd_context.h"

extern void* actionFile;  // FILE* at 0x62C4CC
extern int fprintf(void*, const char*, ...);

// String constants at fixed RVAs in .rdata
extern const char str_taiuaimd_path[];    // at 0x588AE8
extern const char str_fmt_stopObject[];   // at 0x57F964

int TribePreditorUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2) {
    if (event->mType == 0x1FC) {
        RGE_Static_Object* obj =
            this->objectValue->owner->world->object(this->currentTargetValue);

        if (obj != 0) {
            float dist = this->objectValue->distance_to_object(obj);
            if (!(dist > this->objectValue->master_obj->los)) {
                this->attackObject(this->currentTargetValue, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();

        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 250);
        }

        this->stopObject(1);
        this->notifyCommander((void*)event);
    }

    return UnitAIModule::processNotify(event, param_2);
}
