// VA: 0052EDF0 TRIBE_World::load_world (314 B)
// PDB source: tworld.cpp
// Packet-grounded: base load_world, version-checked field reads
//   field_108 (victory_type, int, read if ver >= 5.6)
//   field_10C (artifact_count, int), field_110 (ruin_count, int, read if ver >= 5.3)
//   field_114 (countdown_victory, byte), field_118 (countdown_clock, float, read if ver >= 5.4)
//   field_11C (score_displayed, byte, read if ver >= 6.6)
//   field_11D (controllingComputerPlayer, byte, read if ver >= 6.97)

extern unsigned char RGE_Game_World_load_world(void* self, int param);
extern int rge_read(int handle, void* buf, int size);

extern float save_game_version;

struct Shim_loadworld_EDF0 {
    char gap00[0x108];
    int victory_type;          // +0x108
    int field_10C;             // +0x10C
    int field_110;             // +0x110
    unsigned char field_114;   // +0x114
    int field_118;             // +0x118 (actually float/4 bytes)
    unsigned char field_11C;   // +0x11C
    unsigned char field_11D;   // +0x11D
};

unsigned char TRIBE_World_load_world(Shim_loadworld_EDF0* self, int handle)
{
    unsigned char result = RGE_Game_World_load_world(self, handle);
    if (!result)
        return 0;
    
    // Version-checked conditional reads
    if (save_game_version < 5.6f) {
        self->victory_type = 0;
    } else {
        rge_read(handle, &self->victory_type, 4);
    }
    
    if (save_game_version < 5.3f) {
        self->field_10C = 0;
        self->field_110 = 0;
    } else {
        rge_read(handle, &self->field_10C, 4);
        rge_read(handle, &self->field_110, 4);
    }
    
    if (save_game_version < 5.4f) {
        self->field_114 = 0;
        self->field_118 = 0;
    } else {
        rge_read(handle, &self->field_114, 1);
        rge_read(handle, &self->field_118, 4);
    }
    
    if (save_game_version < 6.6f) {
        self->field_11C = 0;
    } else {
        rge_read(handle, &self->field_11C, 1);
    }
    
    if (save_game_version >= 6.97f) {
        rge_read(handle, &self->field_11D, 1);
        return 1;
    }
    
    self->field_11D = 2;
    return 1;
}
