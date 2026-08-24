#include <stdio.h>

#pragma warning(disable:4234)
extern FILE* actionFile;

#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object_Stop {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void stopObject(int param_1);
};

class RGE_Moving_Object {
public:
    void* vtable_ptr;
    int field_4;
    char gap_08[0x6C];
    RGE_Moving_Object_Stop* stop_object;
    char gap_78[0xF4];
    int numberUserDefinedWaypointsValue;

    void removeAllUserDefinedWaypoints(int param_1);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define field_4 id
#define stop_object inside_obj
#endif

void RGE_Moving_Object::removeAllUserDefinedWaypoints(int param_1) {
    this->numberUserDefinedWaypointsValue = 0;
    if (param_1 == 1 && this->stop_object != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", this->field_4, "C:\\msdev\\work\\age1_x1\\move_obj.cpp", 0xb59);
        }
        this->stop_object->stopObject(0);
    }
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef field_4
#undef stop_object
#endif
