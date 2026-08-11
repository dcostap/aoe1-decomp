// VA: 004CBEF0 TRIBE_Combat_Object::higher_than_target
// Attempt log:
// prior worker: raw offset/vtable reconstruction; same size but broad FPU,
// helper-ABI, and frame drift.
// clean reconstruction: restored the typed combat/static-object coordinates,
// the TRIBE vtable slot for higher_check_for_cliff, and the natural line-step
// source family shared by the movement line walkers.
// probe: this-z greater-than target-z restored the original x87 guard polarity.
// probe: declaring both absolute-step temporaries before their sign tests
// restored the original spill/reload basin, reducing the best result to 143
// differing bytes and a 4-byte size excess.
// probes: direction-plus-tile operand reversal and branch-local offset temps
// were emitted-code duplicates; one-shot direction mutation worsened broadly.
// final best: retain the clean typed source and direct secondary-call offsets;
// remaining drift is localized to VC5 scheduling of the two secondary helper
// call argument additions and the resulting late tail displacement.

#include <math.h>

extern float DAT_00574C98;

class RGE_Map;

class RGE_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x38];
    RGE_World* world;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

#define V10(p) \
    virtual void vf_##p##0(); virtual void vf_##p##1(); \
    virtual void vf_##p##2(); virtual void vf_##p##3(); \
    virtual void vf_##p##4(); virtual void vf_##p##5(); \
    virtual void vf_##p##6(); virtual void vf_##p##7(); \
    virtual void vf_##p##8(); virtual void vf_##p##9();

#define V6(p) \
    virtual void vf_##p##0(); virtual void vf_##p##1(); \
    virtual void vf_##p##2(); virtual void vf_##p##3(); \
    virtual void vf_##p##4(); virtual void vf_##p##5();

class RGE_Combat_Object {
public:
    V10(0)
    V10(1)
    V10(2)
    V10(3)
    V10(4)
    V10(5)
    V10(6)
    V10(7)
    V10(8)
    V10(9)
    V10(10)
    V10(11)
    V10(12)
    V10(13)
    V6(14)
    virtual int higher_check_for_cliff(RGE_Static_Object* object,
                                       int col, int row,
                                       float x1, float y1,
                                       float x2, float y2,
                                       RGE_Map* map,
                                       RGE_Static_Object* old_object,
                                       float& angle, int& direction);

    int id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x180];
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    virtual int higher_than_target(RGE_Static_Object* target);
};

int TRIBE_Combat_Object::higher_than_target(RGE_Static_Object* target)
{
    if (this->world_z > target->world_z) {
        return 1;
    }

    float dest_x = target->world_x;
    float start_x = this->world_x;
    float dest_y = target->world_y;
    float start_y = this->world_y;
    float x_distance = dest_x - start_x;
    float y_distance = dest_y - start_y;

    if ((x_distance == DAT_00574C98) &&
        (y_distance == DAT_00574C98)) {
        return 0;
    }

    int num_steps;
    if (fabs(y_distance) > fabs(x_distance)) {
        num_steps = abs((int)y_distance) * 2;
    } else {
        num_steps = abs((int)x_distance) * 2;
    }

    float x_step;
    float y_step;
    x_step = x_distance / (float)num_steps;
    y_step = y_distance / (float)num_steps;

    float abs_x = x_step;
    float abs_y = y_step;
    if (abs_x < DAT_00574C98) {
        abs_x = -x_step;
    }
    if (abs_y < DAT_00574C98) {
        abs_y = -y_step;
    }

    int dx1;
    int dy1;
    int dx2;
    int dy2;
    int diagonal;
    if (abs_x > abs_y) {
        dx1 = -1;
        dy2 = 0;
        diagonal = 0;
        dx2 = 1;
    } else {
        dy2 = -1;
        dx1 = 0;
        diagonal = 1;
        dx2 = 0;
    }

    float x = start_x;
    float y = start_y;
    int prior_x = -999;
    int prior_y = -999;
    RGE_Map* map = this->owner->world->map;
    float angle = -1.0f;
    int direction = 0;
    int i;
    if (num_steps > 0) {
        i = num_steps;
        do {
            x += x_step;
            y += y_step;
            int tile_x = (int)x;
            int tile_y = (int)y;
            if (tile_x != prior_x || tile_y != prior_y) {
                prior_x = tile_x;
                prior_y = tile_y;
                if (this->higher_check_for_cliff(target, tile_x, tile_y,
                                                 start_x, start_y,
                                                 dest_x, dest_y,
                                                 map, 0, angle, direction) == 0) {
                    if (this->higher_check_for_cliff(target,
                                                     tile_x + dy2,
                                                     tile_y + dx1,
                                                     start_x, start_y,
                                                     dest_x, dest_y,
                                                     map, 0, angle,
                                                     direction) == 0) {
                        this->higher_check_for_cliff(target,
                                                     tile_x + diagonal,
                                                     tile_y + dx2,
                                                     start_x, start_y,
                                                     dest_x, dest_y,
                                                     map, 0, angle,
                                                     direction);
                    }
                }
            }
            --i;
        } while (i != 0);
    }

    if (direction < 1) {
        direction = 0;
    }
    if (direction > 0) {
        direction = 1;
    }
    return direction > 0;
}

#undef V6
#undef V10
