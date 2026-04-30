// RGE_Victory_Conditions::handle_bring_object
// VA: 00532610
// victory.cpp
// 8.48% positional diff - register swap EDX<->ECX for this_obj/target_obj

struct RGE_Master_Object {
    char gap_00[0x30];
    float radius_x;          // +0x30
    float radius_y;          // +0x34
    char gap_38[0x10];
};

struct RGE_Static_Object {
    char gap_00[8];
    RGE_Master_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x;           // +0x38
    float world_y;           // +0x3C
    char gap_40[0x08];
    unsigned char object_state; // +0x48
};

struct RGE_Victory_Entry {
    char gap_00[0x24];
    RGE_Static_Object* this_obj;  // +0x24
    RGE_Static_Object* target_obj; // +0x28
    char gap_2C[0x02];
    unsigned char state;     // +0x2E
};

class RGE_Victory_Conditions {
public:
    void handle_bring_object(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_bring_object(RGE_Victory_Entry* entry) {
    if (entry->this_obj == 0 || entry->target_obj == 0) {
        entry->state = 3;
        return;
    }

    if (entry->this_obj->object_state >= 3 || entry->target_obj->object_state >= 3) {
        entry->this_obj = 0;
        entry->target_obj = 0;
        if (entry->state == 0) {
            entry->state = 1;
        }
        return;
    }

    float dx = entry->this_obj->world_x - entry->target_obj->world_x;
    float dy = entry->this_obj->world_y - entry->target_obj->world_y;

    if (dx < 0.0f) dx = -dx;
    if (dy < 0.0f) dy = -dy;

    float range_x = entry->target_obj->master_obj->radius_x + entry->this_obj->master_obj->radius_x + 1.0f;
    float range_y = entry->target_obj->master_obj->radius_y + entry->this_obj->master_obj->radius_y + 1.0f;

    if (dx <= range_x && dy <= range_y) {
        entry->state = 2;
    } else {
        entry->state = 0;
    }
}
