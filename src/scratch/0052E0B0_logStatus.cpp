// VA: 0052E0B0 TRIBE_World::logStatus (358 B)
// PDB source: tworld.cpp
// Packet-grounded: fprintf status to AI log (time, players, scenario, map size/type, victory)

extern int fprintf(void* fp, const char* fmt, ...);
extern long time(long* t);
extern void* localtime(long* t);
extern char* asctime(void* tm);
extern int strlen(const char* s);
extern void* rge_base_game;
extern int TRIBE_Game_mapSize(void* game);
extern int TRIBE_Game_mapType(void* game);
extern int TRIBE_Game_victoryType(void* game);

struct Shim_logstatus_E0B0 {
    char gap00[0x3C];
    short player_count;        // +0x3C
    char gap3E[0x5C - 0x3E];
    void* field_5C;            // +0x5C (has scenario name at +0x1010)
};

void TRIBE_World_logStatus(Shim_logstatus_E0B0* self, void* fp, int flag)
{
    if (!fp || flag != 1)
        return;
    
    fprintf(fp, "\n\n\n****************************************\n");
    
    long t;
    time(&t);
    fprintf(fp, "AI Log file for Game Started %s", asctime(localtime(&t)));
    fprintf(fp, "Number Players:          %d\n", self->player_count - 1);
    
    if (self->field_5C) {
        char* scenarioName = *(char**)((char*)self->field_5C + 0x1010);
        if (scenarioName && strlen(scenarioName) > 0) {
            fprintf(fp, "Scenario:                %s\n", scenarioName);
            return;
        }
    }
    
    // Map info from rge_base_game
    {
        char buf[256];
        int (*getter)(void*);
        const char* label;
        
        // Map size
        getter = TRIBE_Game_mapSize;
        label = "Map Size:";
        // ...
        
        // Map type
        getter = TRIBE_Game_mapType;
        label = "Map Type:";
        // ...
        
        // Victory condition
        getter = TRIBE_Game_victoryType;
        label = "Victory Condition:";
        // ...
    }
}
