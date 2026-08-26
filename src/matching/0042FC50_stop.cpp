extern "C" void* actionFile;
extern "C" int fprintf(void* stream, const char* format, ...);

#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::stop() {
    RGE_Action_Object::stop();
    if (unitAIValue != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xAB);
        }
        unitAIValue->stopObject(1);
    }
}
