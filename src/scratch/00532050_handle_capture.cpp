// RGE_Victory_Conditions::handle_capture
// VA: 00532050
// victory.cpp

struct RGE_Static_Object {
    char gap_00[0x0C];
    void* owner;             // +0x0C
    char gap_10[0x3C];
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
    void* player;            // +0x0C
};

void __fastcall handle_capture(void* _this, int _, struct RGE_Victory_Entry* entry) {
    if (entry->target_obj) {
        if (*(unsigned char*)((char*)(entry->target_obj) + 0x48) <= 2) {
            void* owner = *(void**)((char*)(entry->target_obj) + 0x0C);
            if (entry->state == 0) {
                void* self = *(void**)((char*)_this + 0x0C);
                if (owner == self) {
                    entry->state = 2;
                } else if (entry->ally_flag && *(unsigned char*)((char*)self + 0x104)) {
                    short owner_id = *(short*)((char*)owner + 0x4A);
                    if (*(unsigned char*)((char*)self + 0x84 + owner_id) == 0) {
                        short self_id = *(short*)((char*)self + 0x4A);
                        if (*(unsigned char*)((char*)owner + 0x84 + self_id) == 0 &&
                            *(unsigned char*)((char*)owner + 0x104)) {
                            entry->state = 2;
                        }
                    }
                }
            } else if (entry->state == 2) {
                void* self = *(void**)((char*)_this + 0x0C);
                if (owner != self) {
                    if (!entry->ally_flag || *(unsigned char*)((char*)self + 0x84 + *(short*)((char*)owner + 0x4A))) {
                        entry->state = 0;
                    }
                }
            }
        } else {
            entry->target_obj = 0;
            if (entry->state == 0) {
                entry->state = 1;
            }
        }
    }
}
