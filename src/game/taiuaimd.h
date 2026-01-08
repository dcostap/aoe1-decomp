#pragma once
#include "../common.h"

class TribeLionUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeLionUnitAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 (Override)
    virtual int canAttackUnitAtNeutrality(int param_1); // Ghidra: canAttackUnitAtNeutrality

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void bestUnitToHeal();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void bestUnitToConvert();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void processOrder();

};

static_assert(sizeof(TribeLionUnitAIModule) == 0x134, "TribeLionUnitAIModule Size Mismatch");

class TribeSoldierUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeSoldierUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 (Override)
    virtual int canAttackUnit(RGE_Static_Object* param_1); // Ghidra: canAttackUnit

    // [Slot 21] Offset 0x54 (Override)
    virtual int canAttackUnitAtNeutrality(int param_1); // Ghidra: canAttackUnitAtNeutrality

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribeSoldierUnitAIModule) == 0x134, "TribeSoldierUnitAIModule Size Mismatch");

class TribeRangedUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeRangedUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeRangedUnitAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void bestUnitToHeal();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void bestUnitToConvert();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void processOrder();

};

static_assert(sizeof(TribeRangedUnitAIModule) == 0x134, "TribeRangedUnitAIModule Size Mismatch");

class TribeHuntedAnimalUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeHuntedAnimalUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

};

static_assert(sizeof(TribeHuntedAnimalUnitAIModule) == 0x134, "TribeHuntedAnimalUnitAIModule Size Mismatch");

class TribeRangedUnitAIModule2 : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeRangedUnitAIModule2(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeRangedUnitAIModule2() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void bestUnitToHeal();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void bestUnitToConvert();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void processOrder();

};

static_assert(sizeof(TribeRangedUnitAIModule2) == 0x134, "TribeRangedUnitAIModule2 Size Mismatch");

class TribeElephantUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeElephantUnitAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void bestUnitToHeal();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void bestUnitToConvert();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void processOrder();

};

static_assert(sizeof(TribeElephantUnitAIModule) == 0x134, "TribeElephantUnitAIModule Size Mismatch");

class TribeFishingShipUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeFishingShipUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 (Override)
    virtual int importantWhenDead(int param_1); // Ghidra: importantWhenDead

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 (Override)
    virtual int convertToLOSResourceType(int param_1); // Ghidra: convertToLOSResourceType

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribeFishingShipUnitAIModule) == 0x134, "TribeFishingShipUnitAIModule Size Mismatch");

class TribeTradeShipUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeTradeShipUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribeTradeShipUnitAIModule) == 0x134, "TribeTradeShipUnitAIModule Size Mismatch");

class TribePriestUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribePriestUnitAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 (Override)
    virtual int retryableOrder(int param_1); // Ghidra: retryableOrder

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 (Override)
    virtual int canAttackUnit(RGE_Static_Object* param_1); // Ghidra: canAttackUnit

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C (Override)
    virtual int attackObject(int param_1, int param_2); // Ghidra: attackObject

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 (Override)
    virtual int canConvert(int param_1); // Ghidra: canConvert

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 (Override)
    virtual int processMisc(); // Ghidra: processMisc

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 (Override)
    virtual int bestUnitToHeal(int param_1, float* param_2); // Ghidra: bestUnitToHeal

    // [Slot 57] Offset 0xE4 (Override)
    virtual int bestUnitToConvert(float* param_1); // Ghidra: bestUnitToConvert

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribePriestUnitAIModule) == 0x134, "TribePriestUnitAIModule Size Mismatch");

class TribeTowerUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeTowerUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 (Override)
    virtual int canAttackUnit(RGE_Static_Object* param_1); // Ghidra: canAttackUnit

    // [Slot 21] Offset 0x54 (Override)
    virtual int canAttackUnitAtNeutrality(int param_1); // Ghidra: canAttackUnitAtNeutrality

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribeTowerUnitAIModule) == 0x134, "TribeTowerUnitAIModule Size Mismatch");

class TribeTransportShipUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeTransportShipUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribeTransportShipUnitAIModule) == 0x134, "TribeTransportShipUnitAIModule Size Mismatch");

class TribeArtifactUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeArtifactUnitAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 (Override)
    virtual int processMisc(); // Ghidra: processMisc

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribeArtifactUnitAIModule) == 0x134, "TribeArtifactUnitAIModule Size Mismatch");

class TribePreditorUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribePreditorUnitAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 (Override)
    virtual int canAttackUnitAtNeutrality(int param_1); // Ghidra: canAttackUnitAtNeutrality

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void bestUnitToHeal();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void bestUnitToConvert();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void processOrder();

};

static_assert(sizeof(TribePreditorUnitAIModule) == 0x134, "TribePreditorUnitAIModule Size Mismatch");

class TribeCivilianUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeCivilianUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 (Override)
    virtual int importantWhenDead(int param_1); // Ghidra: importantWhenDead

    // [Slot 10] Offset 0x28 (Override)
    virtual int retryableOrder(int param_1); // Ghidra: retryableOrder

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 (Override)
    virtual int canAttackUnit(RGE_Static_Object* param_1); // Ghidra: canAttackUnit

    // [Slot 21] Offset 0x54 (Override)
    virtual int canAttackUnitAtNeutrality(int param_1); // Ghidra: canAttackUnitAtNeutrality

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C (Override)
    virtual int attackObject(int param_1, int param_2); // Ghidra: attackObject

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 (Override)
    virtual int convertToLOSResourceType(int param_1); // Ghidra: convertToLOSResourceType

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 (Override)
    virtual int processMisc(); // Ghidra: processMisc

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 60] Offset 0xF0 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 61] Offset 0xF4 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void bestUnitToHeal();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void bestUnitToConvert();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void processNotify();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void processIdle();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void processOrder();

};

static_assert(sizeof(TribeCivilianUnitAIModule) == 0x134, "TribeCivilianUnitAIModule Size Mismatch");

class TribeBuildingUnitAIModule : public UnitAIModule       {
public:
    char _pad_0x4[0x130];

    TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeBuildingUnitAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void load();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void owner();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void order();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void notify();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void notifyCommander();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void search();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void importantWhenDead();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void retryableOrder();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void actionRequiresLiveTarget();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void bestUnitToAttack();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void mostDangerousEnemy();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void weakestEnemy();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void closestAttacker();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void closestObject();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void closestResourceObject();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void closestUndiscoveredTile();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void logDebug();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void canAttackUnit();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void canAttackUnitAtNeutrality();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void stopObject();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void attackObject();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void attackRoundupObject();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void huntObject();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void gatherObject();

    // [Slot 27] Offset 0x6C WARNING: Function body missing in analysis
    // virtual void convertObject();

    // [Slot 28] Offset 0x70 WARNING: Function body missing in analysis
    // virtual void healObject();

    // [Slot 29] Offset 0x74 WARNING: Function body missing in analysis
    // virtual void repairObject();

    // [Slot 30] Offset 0x78 WARNING: Function body missing in analysis
    // virtual void buildObject();

    // [Slot 31] Offset 0x7C WARNING: Function body missing in analysis
    // virtual void tradeWithObject();

    // [Slot 32] Offset 0x80 WARNING: Function body missing in analysis
    // virtual void explore();

    // [Slot 33] Offset 0x84 WARNING: Function body missing in analysis
    // virtual void enterObject();

    // [Slot 34] Offset 0x88 WARNING: Function body missing in analysis
    // virtual void unload();

    // [Slot 35] Offset 0x8C WARNING: Function body missing in analysis
    // virtual void transportObject();

    // [Slot 36] Offset 0x90 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 37] Offset 0x94 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 38] Offset 0x98 WARNING: Function body missing in analysis
    // virtual void moveTo();

    // [Slot 39] Offset 0x9C WARNING: Function body missing in analysis
    // virtual void evasiveMoveTo();

    // [Slot 40] Offset 0xA0 WARNING: Function body missing in analysis
    // virtual void intelligentEvasiveMoveTo();

    // [Slot 41] Offset 0xA4 WARNING: Function body missing in analysis
    // virtual void runAwayFromAttackers();

    // [Slot 42] Offset 0xA8 WARNING: Function body missing in analysis
    // virtual void followObject();

    // [Slot 43] Offset 0xAC WARNING: Function body missing in analysis
    // virtual void defendObject();

    // [Slot 44] Offset 0xB0 WARNING: Function body missing in analysis
    // virtual void defendPosition();

    // [Slot 45] Offset 0xB4 WARNING: Function body missing in analysis
    // virtual void seekAndDestroy();

    // [Slot 46] Offset 0xB8 WARNING: Function body missing in analysis
    // virtual void exploreAndDestroy();

    // [Slot 47] Offset 0xBC WARNING: Function body missing in analysis
    // virtual void importantObject();

    // [Slot 48] Offset 0xC0 WARNING: Function body missing in analysis
    // virtual void convertToLOSResourceType();

    // [Slot 49] Offset 0xC4 WARNING: Function body missing in analysis
    // virtual void canConvert();

    // [Slot 50] Offset 0xC8 WARNING: Function body missing in analysis
    // virtual void processOrder();

    // [Slot 51] Offset 0xCC (Override)
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // Ghidra: processNotify

    // [Slot 52] Offset 0xD0 WARNING: Function body missing in analysis
    // virtual void processGroupNotify();

    // [Slot 53] Offset 0xD4 (Override)
    virtual int processIdle(int param_1); // Ghidra: processIdle

    // [Slot 54] Offset 0xD8 WARNING: Function body missing in analysis
    // virtual void processMisc();

    // [Slot 55] Offset 0xDC WARNING: Function body missing in analysis
    // virtual void processRetryableOrder();

    // [Slot 56] Offset 0xE0 WARNING: Function body missing in analysis
    // virtual void create_task();

    // [Slot 57] Offset 0xE4 WARNING: Function body missing in analysis
    // virtual void get_target_task();

    // [Slot 58] Offset 0xE8 WARNING: Function body missing in analysis
    // virtual void is_attack_task();

    // [Slot 59] Offset 0xEC WARNING: Function body missing in analysis
    // virtual void check_task();

};

static_assert(sizeof(TribeBuildingUnitAIModule) == 0x134, "TribeBuildingUnitAIModule Size Mismatch");

