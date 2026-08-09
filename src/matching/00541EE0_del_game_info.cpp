// VA: 00541EE0 RGE_Game_World::del_game_info()
// PDB source: World.cpp lines 926-1001
// attempt 1: direct reconstruction from packet with typed offsets, two player passes, and reset tail.
// attempt 2: add missing virtual slot for +0xB4 call and spell player checks as nested tests to keep VC5's reload/guard shape.
// attempt 3: volatile player_num kept passes separate but changed compares to memory form; rolled back.
// attempt 4: use explicit pass labels and a short count temp; VC5 still folds initial player_num/player-list guards.
// attempt 5: positive `num != 0 && num > 0` form; no change in the stubborn region.
// attempt 6: /O1, /GX, /Od probes; /O1 smaller, /GX unchanged, /Od broad mismatch; no custom flags kept.
// attempt 7: remove the cached `num` and redundant !=0 tests; this folded the
// duplicate pre-body test.
// attempt 8: retain the outer short count but use ordinary for loops for both
// passes.  VC5 then preserves the binary's early AX load, duplicate compare,
// and shared transition into the second pass.  Exact with default flags.

extern "C" void __cdecl free(void*);

extern int world_update_counter;

class RGE_Object_List {
public:
    void removeAllObjects();
};

class RGE_Scenario {
public:
    virtual void v00();
    virtual void scalar_delete(int flags);
};

class RGE_Player {
public:
    virtual void scalar_delete(int flags);
    void destroy_objects();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World(); virtual void v004(); virtual void v008(); virtual void v00C();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01C();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02C();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03C();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04C();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05C();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06C();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07C();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08C();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09C();
    virtual void v0A0(); virtual void v0A4(); virtual void v0A8(); virtual void v0AC();
    virtual void v0B0();
    virtual void delete_all_objects(); // +0xB4

    char gap_04[0x19];
    unsigned char game_state;          // +0x1D
    unsigned char game_end_condition;  // +0x1E
    char gap_1F[1];
    int sound_update_index;            // +0x20
    int sprite_update_index;           // +0x24
    char gap_28[0x14];
    short player_num;                  // +0x3C
    char gap_3E[2];
    RGE_Player** players;              // +0x40
    char gap_44[0x18];
    RGE_Scenario* scenario;            // +0x5C
    char gap_60[8];
    int next_object_id;                // +0x68
    int next_reusable_object_id;       // +0x6C
    char gap_70[0x18];
    void** objects;                    // +0x88
    char gap_8C[4];
    int max_objects;                   // +0x90
    void** negative_objects;           // +0x94
    char gap_98[4];
    int max_negative_objects;          // +0x9C
    char gap_A0[4];
    int campaign;                      // +0xA4
    int campaign_player;               // +0xA8
    int campaign_scenario;             // +0xAC
    int player_turn;                   // +0xB0
    unsigned long player_time_delta[9];// +0xB4
    RGE_Object_List* reusable_static_objects;      // +0xD8
    RGE_Object_List* reusable_animated_objects;    // +0xDC
    RGE_Object_List* reusable_moving_objects;      // +0xE0
    RGE_Object_List* reusable_action_objects;      // +0xE4
    RGE_Object_List* reusable_combat_objects;      // +0xE8
    RGE_Object_List* reusable_missile_objects;     // +0xEC
    RGE_Object_List* reusable_doppleganger_objects;// +0xF0
    char gap_F4[0x0C];
    int difficultyLevelValue;                       // +0x100

    virtual void del_game_info();
};

void RGE_Game_World::del_game_info()
{
    int i;
    world_update_counter = 0;

    this->game_state = 2;
    this->game_end_condition = 0;
    this->reusable_static_objects->removeAllObjects();
    this->reusable_animated_objects->removeAllObjects();
    this->reusable_moving_objects->removeAllObjects();
    this->reusable_action_objects->removeAllObjects();
    this->reusable_combat_objects->removeAllObjects();
    this->reusable_missile_objects->removeAllObjects();
    this->reusable_doppleganger_objects->removeAllObjects();

    this->next_reusable_object_id = -1;
    this->campaign = -1;
    this->campaign_player = -1;
    this->campaign_scenario = -1;
    this->difficultyLevelValue = -1;
    this->next_object_id = 0;

    i = 0;
    if (this->max_objects > 0) {
        do {
            this->objects[i] = 0;
            i++;
        } while (i < this->max_objects);
    }

    i = 0;
    if (this->max_negative_objects > 0) {
        do {
            this->negative_objects[i] = 0;
            i++;
        } while (i < this->max_negative_objects);
    }

    this->delete_all_objects();

    if (this->scenario != 0) {
        this->scenario->scalar_delete(1);
        this->scenario = 0;
    }

    short num = this->player_num;
    if (num > 0 && this->players != 0) {
        for (i = 0; i < this->player_num; i++) {
            if (this->players[i] != 0) {
                this->players[i]->destroy_objects();
            }
        }
    }

    num = this->player_num;
    if (num > 0 && this->players != 0) {
        for (i = 0; i < this->player_num; i++) {
            if (this->players[i] != 0) {
                this->players[i]->scalar_delete(1);
                this->players[i] = 0;
            }
        }
        this->player_num = 0;
        free(this->players);
        this->players = 0;
    }

    this->next_object_id = 0;
    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->player_turn = 0;
    for (i = 0; i < 9; i++) {
        this->player_time_delta[i] = 0;
    }
}
