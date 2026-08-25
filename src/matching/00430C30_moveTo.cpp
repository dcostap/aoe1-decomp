// VA: 00430C30, RGE_Combat_Object::moveTo, 286 bytes
// Source: com_obj.cpp lines 884-923
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_moveto.h"
#endif

int RGE_Combat_Object::moveTo(int param_1, float param_2, int param_3)
{
    void* worldField;
    RGE_Static_Object* obj;
    void* field8;
    RGE_Action* action;
    RGE_Action_Move_To* moveAction;
    void* sprite;

    worldField = *(void**)((char*)this->field_0C + 0x3C);
    obj = ((RGE_Game_World*)worldField)->object(param_1);

    if (obj == 0)
        return 0;

    if (param_3 == 0) {
        if (this->actions->have_action() == 1) {
            action = (RGE_Action*)this->actions->get_action();
            if (action->get_target_obj() == obj) {
                action = (RGE_Action*)this->actions->get_action();
                if (action->type() == 1)
                    goto success;
            }
        }
    }

    field8 = this->field_08;
    {
        void* sp = *(void**)((char*)field8 + 0xC0);
        if (sp != 0)
            sprite = sp;
        else
            sprite = *(void**)((char*)field8 + 0xBC);
    }
    moveAction = new RGE_Action_Move_To(this, obj, param_2, sprite);
    if (moveAction == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(moveAction);

success:
    return 1;
}
