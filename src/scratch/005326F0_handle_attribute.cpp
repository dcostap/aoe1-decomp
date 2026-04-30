// RGE_Victory_Conditions::handle_attribute
// VA: 005326F0
// victory.cpp

class RGE_Victory_Entry {
public:
    char gap_00[0x1C];
    long number;              // +0x1C
    long count;               // +0x20
    char gap_24[0x09];
    unsigned char ally_flag;  // +0x2D
    unsigned char state;      // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* player;             // +0x0C

    void handle_attribute(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_attribute(RGE_Victory_Entry* entry) {
    if (this->player == 0) return;

    int attr_idx_scaled = entry->number * 4;
    float total = *(float*)(*(long*)((char*)(this->player) + 0x50) + attr_idx_scaled);

    if (entry->ally_flag && *(unsigned char*)((char*)(this->player) + 0x104)) {
        void* world = *(void**)((char*)(this->player) + 0x3C);
        int num = *(short*)((char*)world + 0x3C);
        void** players = *(void***)((char*)world + 0x40);
        short my_id = *(short*)((char*)(this->player) + 0x4A);

        for (int i = num - 1; i >= 0; i--) {
            if (*(unsigned char*)((char*)(this->player) + 0x84 + i) != 0) continue;

            void* other = players[i];
            if (*(unsigned char*)((char*)other + 0x84 + my_id) != 0) continue;
            if (i == my_id) continue;
            if (*(unsigned char*)((char*)other + 0x104) == 0) continue;

            total += *(float*)(*(long*)((char*)other + 0x50) + attr_idx_scaled);
        }
    }

    if ((float)entry->count <= total) {
        entry->state = 2;
    } else {
        entry->state = 0;
    }
}
