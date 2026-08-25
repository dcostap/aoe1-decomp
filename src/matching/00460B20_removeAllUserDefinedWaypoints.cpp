#include <stdio.h>

#pragma warning(disable:4234)
extern FILE* actionFile;

void RGE_Moving_Object::removeAllUserDefinedWaypoints(int param_1) {
    this->numberUserDefinedWaypointsValue = 0;
    if (param_1 == 1 && this->unitAIValue != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", this->id, "C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xb59);
        }
        this->unitAIValue->stopObject(0);
    }
}
