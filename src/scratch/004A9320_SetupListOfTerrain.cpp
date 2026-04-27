// TRIBE_Screen_Sed::SetupListOfTerrain — real pass
// VA: 004A9320
#include "../../include/game_globals.h"

extern void __fastcall _emptyList(void* list);
extern int __fastcall _appendLine(void* list, int _, int strId, int param);

int __fastcall SetupListOfTerrain(void* _this, int _, void* list)
{
    _emptyList(list);
    _appendLine(list, 0, 0x297D, 0); // Grass
    _appendLine(list, 0, 0x297E, 0); // Desert
    _appendLine(list, 0, 0x297F, 0); // Forest
    _appendLine(list, 0, 0x2980, 0); // Water
    _appendLine(list, 0, 0x2981, 0); // Palm Desert
    _appendLine(list, 0, 0x2982, 0); // Jungle
    _appendLine(list, 0, 0x2983, 0); // Shallows
    _appendLine(list, 0, 0x2984, 0); // Pine Forest
    _appendLine(list, 0, 0x2985, 0); // Deep Water
    return 8;
}
