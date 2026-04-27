// VA: 005303F0 TRIBE_World::check_game_state (1653 B)
// PDB source: tworld.cpp
// Packet-grounded: check victory/defeat conditions (countdown, artifacts, ruins, score, etc.)

extern void* rge_base_game;
extern int RGE_Base_Game_getProgMode(void* game);
extern int TRIBE_Game_isScenarioGame(void* game);
extern int TRIBE_Game_isCampaignGame(void* game);
extern int TRIBE_Game_isDeathmatch(void* game);
extern int TRIBE_Game_getPlayerCount(void* game);

// Fields at non-ascending offsets; access late fields via pointer math
// - +0x1D: field_1D (game_over flag?)
// - +0x108: victory_type
// - +0x114: field_114 (countdown_victory flag)
// - +0x118: field_118 (countdown_clock, float)
// - +0x11D: field_11D (controllingComputerPlayer)
// - +0x120: field_120
// - +0x40: player_array
// - +0x48: master_players

int TRIBE_World_check_game_state(void* self)
{
    unsigned char field_1D = *(unsigned char*)((char*)self + 0x1D);
    if (field_1D)
        return 0;
    
    int victory_type = *(int*)((char*)self + 0x108);
    
    // Check victory_type != 2 (standard game)
    if (victory_type != 2) {
        int progMode = RGE_Base_Game_getProgMode(rge_base_game);
        // ...
        return 0;
    }
    
    // Countdown victory
    unsigned char field_114 = *(unsigned char*)((char*)self + 0x114);
    if (field_114) {
        float clock = *(float*)((char*)self + 0x118);
        if (clock > 0.0f) {
        }
    }
    
    // Check artifact victory (find object master 0x6D)
    // Loop players, check their object lists for artifact(s)
    // If one player has all artifacts, they win
    
    // Check exploration victory
    // If all map explored, player wins
    
    // Check ruin collection
    // Count ruins captured vs required
    
    // Check conquest/score victory
    // Loop players, check if any have been eliminated
    // Check score threshold
    
    // Return 0 (no state change) or 1 (game over)
    return 0;
}
