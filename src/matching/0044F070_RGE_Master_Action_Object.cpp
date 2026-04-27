// first pass: call the moving-object base ctor with 0, then conditionally run the copy/helper setup
// /GX was needed to land the exact EH ctor/body basin for this constructor overload
#include "..\..\include\game_types.h"

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
    virtual ~RGE_Master_Animated_Object();
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    short obj_trail_id;
    unsigned char obj_trail_options;
    float obj_trail_spacing;
    unsigned char move_algorithem;

    RGE_Master_Moving_Object(RGE_Master_Moving_Object* source, int do_setup);
    virtual ~RGE_Master_Moving_Object();
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;
    short default_task;
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;

    RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup);
    virtual ~RGE_Master_Action_Object();
    int setup(RGE_Master_Action_Object* source);
};

RGE_Master_Action_Object::RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup)
    : RGE_Master_Moving_Object((RGE_Master_Moving_Object*)source, 0) {
    *(void**)this = (void*)0x570448;
    if (do_setup != 0) {
        setup(source);
    }
}
