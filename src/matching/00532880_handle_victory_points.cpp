// RGE_Victory_Conditions::handle_victory_points
// VA: 00532880
// victory.cpp

class RGE_Victory_Condition {
public:
    long get_victory_points();
};

class RGE_Player {
public:
    char gap_00[0x34];
    RGE_Victory_Condition* victory_condition; // +0x34
    char gap_38[0x02];
    short player_num; // +0x3A? placeholder
    char gap_3C[0x0E];
    short self_id; // +0x4A
    char gap_4C[0x38];
    unsigned char* diplomacy; // +0x84
    char gap_88[0x7C];
    unsigned char active; // +0x104
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* player;              // +0x0C
    char gap_10[0x0C];
    long tot_victory_points;   // +0x1C

    void handle_victory_points(void* entry);
};

void RGE_Victory_Conditions::handle_victory_points(void* entry) {
    RGE_Victory_Conditions* self = this;
    if (self->player) {
        register long total = self->tot_victory_points;
        int count = 1;

        if (*(unsigned char*)((char*)entry + 0x2D) && 
            ((RGE_Player*)self->player)->active) {
            void* w = *(void**)((char*)self->player + 0x3C);
            void** pl = *(void***)((char*)w + 0x40);
            int max_i = *(short*)((char*)w + 0x3C) - 1;
            int i = max_i;
            while (i >= 0) {
                if (((RGE_Player*)self->player)->diplomacy[i] == 0) {
                    RGE_Player* p = (RGE_Player*)pl[i];
                    if (p->diplomacy[((RGE_Player*)self->player)->self_id] == 0 && 
                        i != ((RGE_Player*)self->player)->self_id && 
                        p->active) {
                        total += p->victory_condition->get_victory_points();
                        count++;
                    }
                }
                i--;
            }
        }

        if (total / count >= *(long*)((char*)entry + 0x20)) {
            *(unsigned char*)((char*)entry + 0x2E) = 2;
        }
    }
}
