// RGE_Victory_Conditions::handle_bring_area
// VA: 005325A0
// victory.cpp

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;         // +0x38
    float world_y;         // +0x3C
    char gap_40[0x08];
    unsigned char object_state;  // +0x48
};

class RGE_Victory_Entry {
public:
    char gap_00[0x0C];
    float x0;              // +0x0C
    float y0;              // +0x10
    float x1;              // +0x14
    float y1;              // +0x18
    char gap_1C[0x08];
    RGE_Static_Object* this_obj;  // +0x24
    char gap_28[0x06];
    unsigned char state;   // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x04];
        
    void handle_bring_area(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry* entry) {
    RGE_Static_Object* obj = entry->this_obj;

    if (obj) {
        if (obj->object_state >= 3) goto state_done;
    } else {
        goto state_err;
    }

    if (obj->world_x < entry->x0) goto state_0;
    if (obj->world_x > entry->x1) goto state_0;
    if (obj->world_y < entry->y0) goto state_0;
    if (obj->world_y > entry->y1) goto state_0;

    entry->state = 2;
    return;

state_0:
    entry->state = 0;
    return;

state_done:
    if (entry->state == 0) {
        entry->state = 1;
    }
    entry->this_obj = 0;
    return;

state_err:
    entry->state = 3;
    return;
}
