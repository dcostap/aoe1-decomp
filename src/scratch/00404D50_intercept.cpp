// intercept: ACT_misl.cpp lines 73-86
// Attempt 5: try compound assignment to influence ordering.

class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Action {
public:
    void* vtable_ptr;           // 0x0
    short action_type;          // 0x4
    unsigned char _pad0[2];     // 0x6
    void* obj;                  // 0x8
    unsigned char state;        // 0xC
    unsigned char _pad1[3];     // 0xD
    RGE_Static_Object* target_obj; // 0x10
    unsigned char _gap2[0xC];   // 0x14-0x1F
    float target_x;             // 0x20
    float target_y;             // 0x24
    float target_z;             // 0x28
    unsigned char _pad_end[0x40 - 0x2C];
};

class RGE_Action_Missile : public RGE_Action {
public:
    float velocity_x, velocity_y, velocity_z;
    float ballistic_velocity, ballistic_acceleration;
    void intercept(float* x, float* y, float* z);
};

class RGE_Static_Object {
public:
    void* vtable_ptr;          // 0x0
    long id;                   // 0x4
    RGE_Master_Static_Object* master_obj; // 0x8
    unsigned char _gap_0C[0x2C]; // 0xC-0x37
    float world_x;             // 0x38
    float world_y;             // 0x3C
    float world_z;             // 0x40
};

class RGE_Master_Static_Object {
public:
    unsigned char _gap[0x38];
    float radius_z;            // 0x38
};

void RGE_Action_Missile::intercept(float* x, float* y, float* z) {
    if (!this->target_obj) {
        *x = this->target_x;
        *y = this->target_y;
        *z = this->target_z;
        return;
    }
    *x = this->target_obj->world_x;
    *y = this->target_obj->world_y;

    RGE_Master_Static_Object* master = this->target_obj->master_obj;
    float val = master->radius_z * 0.5f;
    val += this->target_obj->world_z;
    *z = val;
}
