// VA: 00529100 TRIBE_Game::get_tribe_options (225 B)
// PDB source: tribegam.cpp:4493-4520
//
// Status: MATCH. 225/225 bytes, 77/77 instructions, shape 100%, exact-block
// coverage 100%, 19/19 ordered calls, frame none, saved regs ebx/ebp/esi/edi.
//
// Attempt log:
//  - Initial scratch (cdecl free-function stubs) was 67% off; calls must be
//    __thiscall member calls (mov ecx,this; call X), matching the tribegam.cpp
//    exact donors (005291F0 mapSize ... 00529480 popLimit). Non-const member
//    declarations verified by matched caller 004B6230 (mangled ?mapSize@
//    TRIBE_Game@@QAEHXZ etc. confirmed in rebuilt call relocations).
//  - Natural indexed for-loop source gives 225/225 with only 3 bytes off.
//  - The 3 bytes are the SIB byte of the three byte-array stores:
//      original: 88 44 1E 18  mov [esi+ebx+18h],al  (base=esi=counter,
//                index=ebx=opt) -> counter-in-base
//      rebuilt:  88 44 33 18  mov [ebx+esi+18h],al  (base=ebx=opt,
//                index=esi=counter) -> pointer-in-base
//    Same effective address; pure encoder base/index assignment difference.
//  - Pattern is systematic in the original file: set_tribe_options (00529000)
//    reads the same arrays as [esi+ebx+18h]/[esi+ebx+48h]/[esi+ebx+51h], and
//    RGE_Color_Table (004244F0) fills its table as [esi+ebx]. All ORIGINAL
//    loops use counter-in-base; non-loop accesses (setCivilization 00529350,
//    setScenarioPlayer 00529380) use pointer-in-base. Matched donor "append"
//    (004471F0, /GX) also emits counter-in-base after VC5 peels its do-while.
//  - Probes that did NOT flip the SIB (all kept/restored to natural baseline):
//      * i[opt->civilizationValue] term order (VC5 canonicalizes int+ptr)
//      * (int)opt->civilizationValue + i and i + (int)opt->civilizationValue
//      * four walking pointers (exploded to 272 B with spills/frame 0x8)
//      * int* scenario walker local + do-while (moved scheduling, 35 B off)
//      * int* scenario walker local + for (moved scheduling, 35 B off)
//      * /O2 /Oy /GX cluster flags (tribegam.cpp matched siblings use /GX;
//        no EH constructs here so codegen unchanged)
//      * short loop counter (sign-extension bloat, 246 B)
//      * for (int i = 0; ...) header-scoped counter (no change)
//      * pointer+pointer ((unsigned char*)i + arr) rejected by VC5 C2110
//  - Register roles and loop shape already match exactly (esi=counter,
//    ebx=opt, ebp=scenarioPlayer walker, edi=this; inc at bottom;
//    cmp esi,9; jl). Only the encoder's base/index choice differs.
//  - Resolution: adding the proven polymorphic RGE_Base_Game base and the
//    typed TRIBE_Game::tribe_game_options member at +0xA7C flipped all three
//    SIB bytes to the original counter-in-base encoding without changing the
//    natural indexed source. No pointer-walker, cast, or flag trick was kept.
//  - Main-agent audit confirmed the polymorphic game/options ownership and
//    natural indexed copy; exact bytes were revalidated after promotion.

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int mapSize();
    int mapType();
    int animals();
    int predators();
    int victoryType();
    int victoryAmount();
    int civilization(int i);
    int scenarioPlayer(int i);
    int playerColor(int i);
    int computerName(int i);
    int allowTrading();
    int longCombat();
    int randomizePositions();
    int fullTechTree();
    int resourceLevel();
    int startingAge();
    int startingUnits();
    unsigned char deathMatch();
    unsigned char popLimit();

    struct TRIBE_Game_Options {
        int mapSizeValue;               // +0x00
        int mapTypeValue;               // +0x04
        int animalsValue;               // +0x08
        int predatorsValue;             // +0x0C
        int victoryTypeValue;           // +0x10
        int victoryAmountValue;         // +0x14
        unsigned char civilizationValue[9];  // +0x18
        unsigned char _pad_0[3];        // +0x21
        int scenarioPlayerValue[9];     // +0x24
        unsigned char playerColorValue[9];   // +0x48
        unsigned char computerNameValue[9];  // +0x51
        unsigned char allowTradingValue;     // +0x5A
        unsigned char longCombatValue;       // +0x5B
        unsigned char randomizePositionsValue; // +0x5C
        unsigned char fullTechTreeValue;     // +0x5D
        unsigned char _pad_1[2];        // +0x5E
        int resourceLevelValue;         // +0x60
        int startingAgeValue;           // +0x64
        unsigned char startingUnitsValue;    // +0x68
        unsigned char deathMatchValue;       // +0x69
        unsigned char popLimitValue;         // +0x6A
        unsigned char _pad_end[1];      // +0x6B
    };

    char gap_00[0xA7C - 4];
    TRIBE_Game_Options tribe_game_options; // +0xA7C

    void get_tribe_options(TRIBE_Game_Options* opt);
};

void TRIBE_Game::get_tribe_options(TRIBE_Game_Options* opt)
{
    int i;

    opt->mapSizeValue = mapSize();
    opt->mapTypeValue = mapType();
    opt->animalsValue = animals();
    opt->predatorsValue = predators();
    opt->victoryTypeValue = victoryType();
    opt->victoryAmountValue = victoryAmount();

    for (i = 0; i < 9; i++) {
        opt->civilizationValue[i] = (unsigned char)civilization(i);
        opt->scenarioPlayerValue[i] = scenarioPlayer(i);
        opt->playerColorValue[i] = (unsigned char)playerColor(i);
        opt->computerNameValue[i] = (unsigned char)computerName(i);
    }

    opt->allowTradingValue = (unsigned char)allowTrading();
    opt->longCombatValue = (unsigned char)longCombat();
    opt->randomizePositionsValue = (unsigned char)randomizePositions();
    opt->fullTechTreeValue = (unsigned char)fullTechTree();
    opt->resourceLevelValue = resourceLevel();
    opt->startingAgeValue = startingAge();
    opt->startingUnitsValue = (unsigned char)startingUnits();
    opt->deathMatchValue = deathMatch();
    opt->popLimitValue = popLimit();
}
