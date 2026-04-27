// VA: 0052E990 TRIBE_World::setup_players (304 B)
// PDB source: tworld.cpp
// Packet-grounded: EH-framed, loop players (1..count), operator_new + TRIBE_Player ctor per active slot

extern void* operator_new(unsigned int size);
extern int useComputerPlayers;
extern int TRIBE_Player_ctor(void* self, void* world, void* master_player, int player_id, 
                             char* name, int type, int unk1, int civ, int unk3, int unk4, int unk5);

struct Shim_setupplayers_E990 {
    char gap00[0x3C];
    short player_count;        // +0x3C
    char gap3E[0x40 - 0x3E];
    void** player_array;       // +0x40 (array of TRIBE_Player*)
    char gap44[0x48 - 0x44];
    void* master_players;      // +0x48 (array of RGE_Master_Player*)
};

void TRIBE_World_setup_players(Shim_setupplayers_E990* self, char* player_info)
{
    // EH frame: FS:[0] setup/teardown
    int i;
    
    if (self->player_count <= 1)
        return;
    
    for (i = 1; i < self->player_count; i++) {
        unsigned char type = *(unsigned char*)(player_info + (i - 1) + 0x248);
        void* newPlayer = 0;
        int state = -1;
        
        if (type == 4) {
            // Computer player slot
            if (useComputerPlayers) {
                newPlayer = operator_new(0x848);
                state = 2;
                if (newPlayer) {
                    unsigned char mpIdx = *(unsigned char*)(player_info + (i - 1) + 0x251);
                    void* mp = *(void**)((char*)self->master_players + mpIdx * 4);
                    newPlayer = (void*)TRIBE_Player_ctor(newPlayer, self, mp, (unsigned char)i,
                        player_info, mpIdx, 1, 1, 0, 0, 0);
                }
            } else {
                newPlayer = operator_new(0x848);
                state = 1;
                if (newPlayer) goto common_empty;
            }
        } else if (type == 0) {
            // Empty/gaia slot
            newPlayer = operator_new(0x848);
            state = 0;
            if (!newPlayer) goto fail;
            common_empty: {
                unsigned char mpIdx = *(unsigned char*)(player_info + (i - 1) + 0x251);
                void* mp = *(void**)((char*)self->master_players + mpIdx * 4);
                newPlayer = (void*)TRIBE_Player_ctor(newPlayer, self, mp, (unsigned char)i,
                    player_info, mpIdx, 0, 1, 0, 0, 0);
            }
        }
        // else: human or other type, skip
        
        if (newPlayer)
            self->player_array[i] = newPlayer;
        else {
fail:
            self->player_array[i] = 0;
        }
    }
    // EH frame teardown
}
