// 00545CE0 RGE_Game_World::get_scenario_info()
// PDB: World.cpp lines 3550-3553; owning range 00545CE0-00545CE4.
// The preceding RGE_Game_World::difficultyLevel() ends at 00545CD5;
// 00545CD5-00545CDF are non-behavioral alignment padding.
// BINARY NOTE: This virtual stub returns null and uses __thiscall ret 4.

class RGE_Scenario;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    virtual RGE_Scenario* get_scenario_info(char* file);
};

RGE_Scenario* RGE_Game_World::get_scenario_info(char* file) { return 0; }
