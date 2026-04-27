// VA: 005325A0
// RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry*)
// Source: victory.cpp lines 663-686

// attempt log:
// 1. natural if(obj==0)+compound && area check -> 78% diff (inverted branch polarity: je vs jne on null check)
// 2. if-else chain -> same polarity issue
// 3. separate if(goto) for each bound -> 77% diff (different FPU comparison structure + polarity)
// 4. if(obj==0)+separate area if-checks -> same as 3
// 
// Left in scratch: persistent branch-polarity difference. Original uses `je` (jump forward to
// error block at end), my code uses `jne` (skip over inline error, fall-through to success path).
// The FPU comparisons are structurally identical but jump offsets cascade from the polarity choice.

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
    if (obj == 0) {
        entry->state = 3;
        return;
    }

    if (obj->object_state >= 3) {
        if (entry->state == 0) {
            entry->state = 1;
        }
        entry->this_obj = 0;
        return;
    }

    if (obj->world_x < entry->x0) goto not_in_area;
    if (obj->world_x > entry->x1) goto not_in_area;
    if (obj->world_y < entry->y0) goto not_in_area;
    if (obj->world_y > entry->y1) goto not_in_area;

    entry->state = 2;
    return;

not_in_area:
    entry->state = 0;
}
