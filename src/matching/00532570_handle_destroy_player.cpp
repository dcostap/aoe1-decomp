#ifndef VICTORY_CONTEXT_H
struct RGE_Player {
    char gap_0[0x80];
    char game_status;
};

struct RGE_Victory_Entry {
    char type;
    char gap_1[3];
    int field_4;
    RGE_Player* target_player;
    char gap_C[0x2E - 0xC];
    char field_2E;
    char gap_2F;
    void* next;
};

class RGE_Victory_Conditions {
protected:
    void handle_destroy_player(RGE_Victory_Entry* entry);
};
#endif

void RGE_Victory_Conditions::handle_destroy_player(RGE_Victory_Entry* entry) {
    if (entry->target_player) {
        if (entry->target_player->game_status != 2)
            entry->field_2E = 0;
        else
            entry->field_2E = 2;
    }
}
