// VA: 00529000 TRIBE_Game::set_tribe_options (253 B)
// Packet-grounded: copy the network options through the typed setter surface.

#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    enum MapSize {
        Tiny,
        Small,
        Medium,
        Large,
        Huge,
        Humongous
    };

    enum MapType { MapTypeDefault };
    enum VictoryType { VictoryTypeDefault };
    enum ResourceLevel { ResourceLevelDefault };
    enum Age { AgeDefault };

    struct TRIBE_Game_Options {
        MapSize mapSizeValue;
        MapType mapTypeValue;
        int animalsValue;
        int predatorsValue;
        VictoryType victoryTypeValue;
        int victoryAmountValue;
        unsigned char civilizationValue[9];
        int scenarioPlayerValue[9];
        unsigned char playerColorValue[9];
        unsigned char computerNameValue[9];
        unsigned char allowTradingValue;
        unsigned char longCombatValue;
        unsigned char randomizePositionsValue;
        unsigned char fullTechTreeValue;
        ResourceLevel resourceLevelValue;
        Age startingAgeValue;
        unsigned char startingUnitsValue;
        unsigned char deathMatchValue;
        unsigned char popLimitValue;
    };

    void setMapSize(MapSize);
    void setMapType(MapType);
    void setAnimals(int);
    void setPredators(int);
    void setVictoryType(VictoryType, int);
    void setCivilization(int, int);
    void setScenarioPlayer(int, int);
    void setPlayerColor(int, int);
    void setComputerName(int, int);
    void setAllowTrading(int);
    void setLongCombat(int);
    void setRandomizePositions(int);
    void setFullTechTree(int);
    void setResourceLevel(ResourceLevel);
    void setStartingAge(Age);
    void setStartingUnits(int);
    void setDeathMatch(unsigned char);
    void setPopLimit(unsigned char);

    void set_tribe_options(TRIBE_Game_Options*);
};
#endif

void TRIBE_Game::set_tribe_options(TRIBE_Game_Options* options) {
    int i;

    this->setMapSize(options->mapSizeValue);
    this->setMapType((TRIBE_Game::MapType)options->mapTypeValue);
    this->setAnimals(options->animalsValue);
    this->setPredators(options->predatorsValue);
    this->setVictoryType((TRIBE_Game::VictoryType)options->victoryTypeValue,
                         options->victoryAmountValue);

    for (i = 0; i < 9; i++) {
        this->setCivilization(i, options->civilizationValue[i]);
        this->setScenarioPlayer(i, options->scenarioPlayerValue[i]);
        this->setPlayerColor(i, options->playerColorValue[i]);
        this->setComputerName(i, options->computerNameValue[i]);
    }

    this->setAllowTrading(options->allowTradingValue);
    this->setLongCombat(options->longCombatValue);
    this->setRandomizePositions(options->randomizePositionsValue);
    this->setFullTechTree(options->fullTechTreeValue);
    this->setResourceLevel((TRIBE_Game::ResourceLevel)options->resourceLevelValue);
    this->setStartingAge((TRIBE_Game::Age)options->startingAgeValue);
    this->setStartingUnits(options->startingUnitsValue);
    this->setDeathMatch(options->deathMatchValue);
    this->setPopLimit(options->popLimitValue);
}
