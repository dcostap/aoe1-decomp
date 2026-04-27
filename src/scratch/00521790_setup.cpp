// VA: 00521790 TRIBE_Game::setup (2061 B)
// PDB source: tribegam.cpp
// Bounded heavy-pass: full game setup chain

extern void RGE_Base_Game_setup(void* self);
extern void TRIBE_Game_setup_cmd_options(void* self);
extern void TRIBE_Game_setup_sounds(void* self);
extern void run_log(const char* msg, int flag);

void TRIBE_Game_setup(void* self)
{
    // Call base class setup
    RGE_Base_Game_setup(self);
    
    // Setup command options
    TRIBE_Game_setup_cmd_options(self);
    
    // Log
    run_log("Setup start", 1);
    
    // Setup sounds
    TRIBE_Game_setup_sounds(self);
    
    // More setup
    // ...
}
