// VA: 0052EF30 TRIBE_World::new_game (5028 B)
// PDB source: tworld.cpp
// Packet-grounded: massive game init — RGE_Game_World init, tribes, terrain, players, map generation

extern int RGE_Game_World_init(void* self, void* progInfo);
extern int RGE_Game_World_setRandSeed(void* self, unsigned int seed);
extern int RGE_Game_World_setPlayers(void* self, int count);
extern int RGE_Game_World_setMapSize(void* self, int w, int h);
extern int TRIBE_World_updatePlayerCount(void* self);
extern int TRIBE_World_setup_players(void* self, void* playerInfo);
extern int TRIBE_World_initTerrain(void* self);
extern int RGE_Map_Generator_generate(void* gen);
extern int RGE_Map_Generator_init(void* gen, void* world);
extern int RGE_Map_Generator_setSeed(void* gen, unsigned int seed);
extern int RGE_Game_World_createObjectLists(void* self);
extern int RGE_Game_World_initObjects(void* self);
extern int TRIBE_Game_updateAI(void* game);
extern int sprintf(char* buf, const char* fmt, ...);

extern void* rge_base_game;

struct Shim_newgame_EF30 {
    char gap00[0x3C];
    short player_count;        // +0x3C
    char gap3E[0x40 - 0x3E];
    void** player_array;       // +0x40
    char gap44[0x48 - 0x44];
    void* master_players;      // +0x48
    char gap4C[0x5C - 0x4C];
    void* field_5C;            // +0x5C
    char gap60[0x120 - 0x60];
    int field_120;             // +0x120
    char gap124[0x3F4 - 0x124];
    void* world;               // +0x3F4
};

int TRIBE_World_new_game(Shim_newgame_EF30* self, void* progInfo)
{
    // Initialize base game world
    int result = RGE_Game_World_init(self, progInfo);
    if (!result)
        return 0;
    
    // Set random seed from program info
    // RGE_Game_World_setRandSeed(self, seed);
    
    // Setup players
    // TRIBE_World_updatePlayerCount(self);
    // TRIBE_World_setup_players(self, playerInfo);
    
    // Initialize terrain
    // TRIBE_World_initTerrain(self);
    
    // Create and initialize map generator
    // RGE_Map_Generator_init(generator, self);
    // generator->generate();
    
    // For each player, process starting objects
    // Place town center, villagers, scout
    // Initialize resources
    
    // Create object lists
    // RGE_Game_World_createObjectLists(self);
    
    // Initialize all objects
    // RGE_Game_World_initObjects(self);
    
    // Update AI
    // TRIBE_Game_updateAI(rge_base_game);
    
    // Recalculate visibility
    // ...
    
    return 1;
}
