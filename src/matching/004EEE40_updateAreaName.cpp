// 004EEE40 TribeTacticalAIModule::updateAreaName()
// Source: taitacmd.cpp lines 2039-2065
// Attempt log:
// - Replaced stub with full switch table of status string addresses.
// - Exact match with an unsigned switch input, producing the original `ja`
//   bounds check and jump table.

#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    char gap_000[0xE1C];
    unsigned int updateArea;

    char* updateAreaName();
};
#endif

char* TribeTacticalAIModule::updateAreaName()
{
    switch (this->updateArea) {
    case 0: return (char*)0x0058839C;
    case 1: return (char*)0x0058838C;
    case 2: return (char*)0x00588380;
    case 3: return (char*)0x0058836C;
    case 4: return (char*)0x0058835C;
    case 5: return (char*)0x00588350;
    case 6: return (char*)0x00588340;
    case 7: return (char*)0x00588330;
    case 8: return (char*)0x00588324;
    case 9: return (char*)0x00588318;
    case 10: return (char*)0x00588308;
    case 11: return (char*)0x005882FC;
    case 12: return (char*)0x005882F4;
    case 13: return (char*)0x005882E4;
    case 14: return (char*)0x005882D8;
    case 15: return (char*)0x005882CC;
    case 16: return (char*)0x005882C0;
    case 17: return (char*)0x0058762C;
    case 18: return (char*)0x005882B4;
    case 19: return (char*)0x005882A8;
    case 20: return (char*)0x00588298;
    case 21: return (char*)0x00588284;
    default: return (char*)0x0057F54C;
    }
}
