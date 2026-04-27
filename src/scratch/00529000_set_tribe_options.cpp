// VA: 00529000 TRIBE_Game::set_tribe_options (253 B)
// PDB source: tribegam.cpp
// Packet-grounded: write game options from struct via setter calls

void TRIBE_Game_setMapSize(void* self, int v);
void TRIBE_Game_setMapType(void* self, int v);
void TRIBE_Game_setAnimals(void* self, int v);
void TRIBE_Game_setPredators(void* self, int v);
void TRIBE_Game_setVictoryType(void* self, int type, int amount);
void TRIBE_Game_setCivilization(void* self, int idx, int v);
void TRIBE_Game_setScenarioPlayer(void* self, int idx, int v);
void TRIBE_Game_setPlayerColor(void* self, int idx, int v);
void TRIBE_Game_setComputerName(void* self, int idx, int v);
void TRIBE_Game_setAllowTrading(void* self, int v);
void TRIBE_Game_setLongCombat(void* self, int v);
void TRIBE_Game_setRandomizePositions(void* self, int v);
void TRIBE_Game_setFullTechTree(void* self, int v);
void TRIBE_Game_setResourceLevel(void* self, int v);
void TRIBE_Game_setStartingAge(void* self, int v);
void TRIBE_Game_setStartingUnits(void* self, int v);
void TRIBE_Game_setDeathMatch(void* self, unsigned char v);
void TRIBE_Game_setPopLimit(void* self, unsigned char v);

typedef struct {
    int mapSize;
    int mapType;
    int animals;
    int predators;
    int victoryType;
    int victoryAmount;
    unsigned char civilization[9];
    int scenarioPlayer[9];  // at +0x24
    unsigned char playerColor[9];  // at +0x48
    unsigned char computerName[9]; // at +0x51
    unsigned char allowTrading;    // +0x5A
    unsigned char longCombat;
    unsigned char randomizePositions;
    unsigned char fullTechTree;
    int resourceLevel;       // +0x60
    int startingAge;
    unsigned char startingUnits;
    unsigned char deathMatch;
    unsigned char popLimit;
} TRIBE_Game_Options;

void TRIBE_Game_set_tribe_options(void* self, TRIBE_Game_Options* opt)
{
    int i;
    
    TRIBE_Game_setMapSize(self, opt->mapSize);
    TRIBE_Game_setMapType(self, opt->mapType);
    TRIBE_Game_setAnimals(self, opt->animals);
    TRIBE_Game_setPredators(self, opt->predators);
    TRIBE_Game_setVictoryType(self, opt->victoryType, opt->victoryAmount);
    
    for (i = 0; i < 9; i++) {
        TRIBE_Game_setCivilization(self, i, (int)opt->civilization[i]);
        TRIBE_Game_setScenarioPlayer(self, i, opt->scenarioPlayer[i]);
        TRIBE_Game_setPlayerColor(self, i, (int)opt->playerColor[i]);
        TRIBE_Game_setComputerName(self, i, (int)opt->computerName[i]);
    }
    
    TRIBE_Game_setAllowTrading(self, (int)opt->allowTrading);
    TRIBE_Game_setLongCombat(self, (int)opt->longCombat);
    TRIBE_Game_setRandomizePositions(self, (int)opt->randomizePositions);
    TRIBE_Game_setFullTechTree(self, (int)opt->fullTechTree);
    TRIBE_Game_setResourceLevel(self, opt->resourceLevel);
    TRIBE_Game_setStartingAge(self, opt->startingAge);
    TRIBE_Game_setStartingUnits(self, (int)opt->startingUnits);
    TRIBE_Game_setDeathMatch(self, opt->deathMatch);
    TRIBE_Game_setPopLimit(self, opt->popLimit);
}
