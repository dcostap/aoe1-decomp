// intercept: ACT_misl.cpp lines 73-86
// Raw bit-copy stores preserve the original frame-less writes for x, y, and z.

class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Action {
public:
    void* vtable_ptr;
    short action_type;
    unsigned char _pad0[2];
    void* obj;
    unsigned char state;
    unsigned char _pad1[3];
    RGE_Static_Object* target_obj;
    unsigned char _gap2[0xC];
    float target_x;
    float target_y;
    float target_z;
};

class RGE_Action_Missile : public RGE_Action {
public:
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float ballistic_velocity;
    float ballistic_acceleration;

    void intercept(float& x, float& y, float& z);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    unsigned char _gap_0C[0x2C];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Master_Static_Object {
public:
    unsigned char _gap[0x38];
    float radius_z;
};

void RGE_Action_Missile::intercept(float& x, float& y, float& z) {
    if (!this->target_obj) {
        *(long*)&x = *(long*)&this->target_x;
        *(long*)&y = *(long*)&this->target_y;
        *(long*)&z = *(long*)&this->target_z;
    } else {
        *(long*)&x = *(long*)&this->target_obj->world_x;
        *(long*)&y = *(long*)&this->target_obj->world_y;
        z = (this->target_obj->master_obj->radius_z * 0.5f) + this->target_obj->world_z;
    }
}
