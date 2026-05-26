// RGE_Victory_Conditions::handle_capture
// VA: 00532050
// victory.cpp

struct RGE_Player {
    char gap_00[0x4A];
    short id;                // +0x4A
    char gap_4C[0x38];
    unsigned char* relations; // +0x84
    char gap_88[0x7C];
    unsigned char allied_victory; // +0x104
};

struct RGE_Static_Object {
    char gap_00[0x0C];
    RGE_Player* owner;       // +0x0C
    char gap_10[0x38];
    unsigned char object_state; // +0x48
};

struct RGE_Victory_Entry {
    char gap_00[0x28];
    void* target_obj;        // +0x28
    char gap_2C;
    unsigned char ally_flag; // +0x2D
    unsigned char state;     // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    RGE_Player* player;      // +0x0C
    void handle_capture(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_capture(RGE_Victory_Entry* entry) {
    RGE_Static_Object* obj = (RGE_Static_Object*)entry->target_obj;
    if (obj) {
        if (obj->object_state > 2) {
            entry->target_obj = 0;
            if (entry->state == 0) {
                entry->state = 1;
                return;
            }
        } else {
            if (entry->state == 0) {
                RGE_Player* owner = obj->owner;
                RGE_Player* self = this->player;
                if (owner == self ||
                    (entry->ally_flag && self->allied_victory &&
                     self->relations[owner->id] == 0 &&
                     owner->relations[self->id] == 0 && owner->allied_victory)) {
                    entry->state = 2;
                    return;
                }
            } else if (entry->state == 2) {
                RGE_Player* owner = obj->owner;
                RGE_Player* self = this->player;
                if (owner != self && (!entry->ally_flag || self->relations[owner->id] != 0)) {
                    entry->state = 0;
                }
            }
        }
    }
}
