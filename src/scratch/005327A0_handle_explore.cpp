// RGE_Victory_Conditions::handle_explore
// VA: 005327A0
// victory.cpp

struct RGE_Game_World {
    char gap_00[0x3C];
    short player_num;         // +0x3C
    void** players;           // +0x40
};

struct RGE_Visible_Map {
    char gap_00[4];
};

struct RGE_Player {
    char gap_00[0x38];
    RGE_Visible_Map* visible; // +0x38
    char gap_3C[0x0E];
    short id;                 // +0x4A
    char gap_4C[4];
    RGE_Game_World* world;    // +0x50 ... no wait
};

struct RGE_Victory_Entry {
    char gap_00[0x20];
    long count;               // +0x20
    char gap_24[0x09];
    unsigned char ally_flag;  // +0x2D
    unsigned char state;      // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* player_ptr;         // +0x0C

    void handle_explore(RGE_Victory_Entry* entry);
};

extern "C" float percentExplored(void* map);

void RGE_Victory_Conditions::handle_explore(RGE_Victory_Entry* entry) {
    if (entry->state != 0) return;

    void* self = *(void**)((char*)this + 0x0C);
    if (self == 0) return;

    if (entry->ally_flag != 0 && *(unsigned char*)((char*)self + 0x104) != 0) {
        short self_id = *(short*)((char*)self + 0x4A);
        void* world = *(void**)((char*)self + 0x3C);
        int num = *(short*)((char*)world + 0x3C);
        char* players = *(char**)((char*)world + 0x40);
        for (int i = num - 1; i >= 0; i--) {
            void* p = *(void**)(players + i * 4);
            if ((*(unsigned char*)((char*)self + 0x84 + i) == 0 && 
                 *(unsigned char*)((char*)p + 0x84 + self_id) == 0 && 
                 *(unsigned char*)((char*)p + 0x104) != 0) || i == self_id) {
                float explored = percentExplored(*(void**)((char*)p + 0x38));
                if ((float)entry->count <= explored * 100.0f) {
                    entry->state = 2;
                    return;
                }
            }
        }
    } else {
        float explored = percentExplored(*(void**)((char*)self + 0x38));
        if ((float)entry->count <= explored * 100.0f) {
            entry->state = 2;
        }
    }
}
