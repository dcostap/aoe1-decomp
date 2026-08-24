// VA: 0045D1F0 turn_towards (358B)
// move_obj.cpp lines 475-505
// Attempt log:
// - Baseline scaffold had the wrong ABI and only assigned a guessed integer
//   angle field; packet evidence proves a virtual unsigned-char method taking
//   RGE_Static_Object*, float, float and returning the post-turn tolerance.
// - Reconstructing named ownership: owner->world->world_time, master_obj's
//   turn_speed, sprite->facet_num, angle/turn_towards_time, direct
//   angle_to_object and set_angle calls, and the original parameter-home reuse
//   topology through a natural angle local.

class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Sprite;
class RGE_Static_Object;

extern double DAT_00570b40;
extern float DAT_00570b4c;
extern float DAT_00570b50;
extern float DAT_00570b84;

#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Sprite {
public:
    char gap_00[0x60];
    short facet_num;
    char gap_62[0x0E];
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0xB4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[8];
    float turn_speed;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x74];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;

    float angle_to_object(RGE_Static_Object* object, float x, float y);
    void set_angle();
    virtual unsigned char turn_towards(RGE_Static_Object* object,
                                       float x, float y);
};
#endif

unsigned char RGE_Moving_Object::turn_towards(RGE_Static_Object* object,
                                               float x, float y) {
    float turnTime;
    float angle = this->angle_to_object(object, x, y);
    if (angle <= 0.5f) {
        if (angle >= -0.5f) {
            return 1;
        }
    }

    turnTime = (float)this->owner->world->world_time * DAT_00570b84;
    if (turnTime - this->turn_towards_time <
        ((RGE_Master_Moving_Object*)this->master_obj)->turn_speed) {
        return 0;
    }

    if (angle < 0.0f) {
        this->angle -=
            (float)(DAT_00570b40 / (float)(int)this->sprite->facet_num);
    } else {
        this->angle +=
            (float)(DAT_00570b40 / (float)(int)this->sprite->facet_num);
    }

    if (this->angle < 0.0f) {
        this->angle = this->angle - DAT_00570b4c;
    } else if (this->angle > DAT_00570b50) {
        this->angle = this->angle - DAT_00570b50;
    }

    this->set_angle();
    this->turn_towards_time = turnTime;

    angle = this->angle_to_object(object, x, y);
    if (angle <= 0.5f) {
        if (angle >= -0.5f) {
            return 1;
        }
    }
    return 0;
}
