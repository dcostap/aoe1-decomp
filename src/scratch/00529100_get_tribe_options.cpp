// VA: 00529100 TRIBE_Game::get_tribe_options (225 B)
// PDB source: tribegam.cpp
// Packet-grounded: read game options into struct via getter calls

int TRIBE_Game_mapSize(void* self);
int TRIBE_Game_mapType(void* self);
int TRIBE_Game_animals(void* self);
int TRIBE_Game_predators(void* self);
int TRIBE_Game_victoryType(void* self);
int TRIBE_Game_victoryAmount(void* self);
int TRIBE_Game_civilization(void* self, int idx);
int TRIBE_Game_scenarioPlayer(void* self, int idx);
int TRIBE_Game_playerColor(void* self, int idx);
int TRIBE_Game_computerName(void* self, int idx);
int TRIBE_Game_allowTrading(void* self);
int TRIBE_Game_longCombat(void* self);
int TRIBE_Game_randomizePositions(void* self);
int TRIBE_Game_fullTechTree(void* self);
int TRIBE_Game_resourceLevel(void* self);
int TRIBE_Game_startingAge(void* self);
int TRIBE_Game_startingUnits(void* self);
unsigned char TRIBE_Game_deathMatch(void* self);
unsigned char TRIBE_Game_popLimit(void* self);

struct TRIBE_Game_Options {
    int mapSize;
    int mapType;
    int animals;
    int predators;
    int victoryType;
    int victoryAmount;
    unsigned char civilization[9];  // +0x18
    int scenarioPlayer[9];         // +0x24 (actually 24 + 4 each)
    unsigned char playerColor[9];  // +0x48
    unsigned char computerName[9]; // +0x51
    unsigned char allowTrading;    // +0x5A
    unsigned char longCombat;
    unsigned char randomizePositions;
    unsigned char fullTechTree;
    int resourceLevel;             // +0x60
    int startingAge;
    unsigned char startingUnits;
    unsigned char deathMatch;
    unsigned char popLimit;
};

void TRIBE_Game_get_tribe_options(void* self, struct TRIBE_Game_Options* opt)
{
    int i;
    
    opt->mapSize = TRIBE_Game_mapSize(self);
    opt->mapType = TRIBE_Game_mapType(self);
    opt->animals = TRIBE_Game_animals(self);
    opt->predators = TRIBE_Game_predators(self);
    opt->victoryType = TRIBE_Game_victoryType(self);
    opt->victoryAmount = TRIBE_Game_victoryAmount(self);
    
    for (i = 0; i < 9; i++) {
        opt->civilization[i] = (unsigned char)TRIBE_Game_civilization(self, i);
        opt->scenarioPlayer[i] = TRIBE_Game_scenarioPlayer(self, i);
        opt->playerColor[i] = (unsigned char)TRIBE_Game_playerColor(self, i);
        opt->computerName[i] = (unsigned char)TRIBE_Game_computerName(self, i);
    }
    
    opt->allowTrading = (unsigned char)TRIBE_Game_allowTrading(self);
    opt->longCombat = (unsigned char)TRIBE_Game_longCombat(self);
    opt->randomizePositions = (unsigned char)TRIBE_Game_randomizePositions(self);
    opt->fullTechTree = (unsigned char)TRIBE_Game_fullTechTree(self);
    opt->resourceLevel = TRIBE_Game_resourceLevel(self);
    opt->startingAge = TRIBE_Game_startingAge(self);
    opt->startingUnits = (unsigned char)TRIBE_Game_startingUnits(self);
    opt->deathMatch = TRIBE_Game_deathMatch(self);
    opt->popLimit = TRIBE_Game_popLimit(self);
}
