
#include "../include/taistrmd.h"
#include "../include/taimdmd.h"
#include "../include/basegame.h"
#include "../include/player.h"
#include "../include/tplayer.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/victory.h"

// Canonical context: the compiler now owns the proved virtual-table store.


VictoryConditionRuleSystem::VictoryConditionRuleSystem()
{
    int* p = this->sn;
    p[0] = 34;
    p[1] = 0;
    p[2] = 66;
    p[3] = 2;
    p[4] = 2;
    p[5] = -1;
    p[6] = -1;
    p[7] = -1;
    p[8] = -1;
    p[9] = -1;
    p[10] = -1;
    p[11] = -1;
    p[12] = -1;
    p[13] = -1;
    p[14] = -1;
    p[15] = -1;
    p[16] = 4;
    p[17] = -1;
    p[18] = 4;
    p[19] = 50;
    p[20] = 50;
    p[21] = -1;
    p[22] = 12;
    p[23] = 10;
    p[24] = 75;
    p[25] = 1;
    p[26] = 10;
    p[27] = -1;
    p[28] = 4;
    p[29] = 85;
    p[30] = 70;
    p[31] = 75;
    p[32] = 100;
    p[33] = -1;
    p[34] = 50;
    p[35] = 0;
    p[36] = 3;
    p[37] = 0;
    p[38] = 0;
    p[39] = 0;
    p[40] = 0;
    p[41] = 4;
    p[42] = 0;
    p[43] = 1;
    p[44] = 3;
    p[45] = 0;
    p[46] = 30;
    p[47] = 1;
    p[48] = 30;
    p[49] = 3;
    p[50] = 0;
    p[51] = 0;
    p[52] = 0;
    p[53] = 0;
    p[54] = 0;
    p[55] = 0;
    p[56] = 7;
    p[57] = 3;
    p[58] = 2;
    p[59] = 1;
    p[60] = 5;
    p[61] = 1;
    p[62] = 1;
    p[63] = 2;
    p[64] = 0;
    p[65] = 0;
    p[66] = 0;
    p[67] = 0;
    p[68] = 0;
    p[69] = 0;
    p[70] = 0;
    p[71] = 1;
    p[72] = 2;
    p[73] = 12;
    p[74] = 20;
    p[75] = 3;
    p[76] = 15;
    p[77] = 50;
    p[78] = 0;
    p[79] = 0;
    p[80] = 0;
    p[81] = 0;
    p[82] = 0;
    p[83] = 0;
    p[84] = 4;
    p[85] = 2;
    p[86] = 25;
    p[87] = 100;
    p[88] = 3;
    p[89] = -25;
    p[90] = 0;
    p[91] = 100;
    p[92] = 5;
    p[93] = 1;
    p[94] = 0;
    p[95] = 0;
    p[96] = 0;
    p[97] = 0;
    p[98] = 1;
    p[99] = 10;
    p[100] = 3;
    p[101] = 1;
    p[102] = 15;
    p[103] = 0;
    p[104] = 0;
    p[105] = 0;
    p[106] = -1;
    p[107] = -1;
    p[108] = -1;
    p[109] = 0;
    p[110] = 0;
    p[111] = 0;
    p[112] = 300;
    p[113] = 0;
    p[114] = 25;
    p[115] = 10;
    p[116] = 10;
    p[117] = 0;
    p[118] = 0;
    p[119] = 0;
    p[120] = 0;
    p[121] = 0;
    p[122] = 100;
    p[123] = 0;
    p[124] = 0;
    p[125] = 0;
    p[126] = 0;
    p[127] = 0;
    p[128] = -1;
    p[129] = 0;
    p[130] = 0;
    p[131] = 3;
    p[132] = 0;
    p[133] = 0;
    p[134] = 0;
    p[135] = 1;
    p[136] = 15;
    p[137] = 0;
    p[138] = 0;
    p[139] = 0;
    p[140] = 0;
    p[141] = 0;
    p[142] = 0;
    p[143] = 1;
    p[144] = 0;
    p[145] = 10;
    p[146] = 50;
    p[147] = 10;
    p[148] = 20;
    p[149] = 40;
    p[150] = -1;
    p[151] = 3;
    p[152] = 0;
    p[153] = -1;
    p[154] = -1;
    p[155] = 10;
    p[156] = 0;
    p[157] = 0;
    p[158] = 0;
    p[159] = 0;
    p[160] = 50;
    p[161] = 2;
    p[162] = 0;
    p[163] = 7;
    p[164] = 10;
    p[165] = 25;
    p[166] = 7;
    p[167] = 2;
    p[168] = 50;
    p[169] = 10;
    p[170] = 200;
    p[171] = 250;
    p[172] = 150;
    p[173] = 200;
    p[174] = 2;
    p[175] = -1;
    p[176] = 0;
    p[177] = -1;
    p[178] = 10;
    p[179] = 30;
    p[180] = 1;
    p[181] = 1;
    p[182] = 0;
    p[183] = 0;
    p[184] = 20;
    p[185] = 50;
    p[186] = 0;
    p[187] = 0;
    p[188] = 1;
    p[189] = 50;
    p[190] = 3000;
    p[191] = 2000;
    p[192] = 1500;
    p[193] = 3000;
    p[194] = 1;
    p[195] = 25;
    p[199] = 25;
    p[202] = 25;
    p[196] = 1;
    p[197] = 120;
    p[198] = 50;
    p[200] = 50;
    p[201] = 0;
    p[203] = 1;
    p[204] = 5;
    p[205] = 1;
    p[206] = 1;
    p[207] = 1;
    p[208] = 0;
    p[209] = 0;
    p[210] = 0;
    p[211] = 1;
    p[212] = 0;
    p[213] = 0;
    p[214] = 0;
    p[215] = 1;
    p[216] = 50;
    p[217] = 0;
    p[218] = 100;
    p[219] = 100;
    p[220] = 8;
    p[221] = 3;
    p[222] = 10;
    p[223] = 0;
    p[224] = 0;
    p[225] = 1;
}

VictoryConditionRuleSystem::~VictoryConditionRuleSystem() {}


extern "C" int __cdecl strcmp(const char* left, const char* right);
extern "C" unsigned int __cdecl strlen(const char* text);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" FILE* __cdecl fopen(const char* filename, const char* mode);
extern "C" char* __cdecl fgets(char* buffer, int count, FILE* stream);
extern "C" int __cdecl sscanf(const char* buffer, const char* format, ...);
extern "C" int __cdecl fclose(FILE* stream);
extern "C" char* __cdecl strstr(const char* text, const char* search);
extern "C" int __cdecl _unlink(const char* filename);

#pragma intrinsic(strcmp)
#pragma intrinsic(strlen)

int VictoryConditionRuleSystem::loadRules(char* filename)
{
    char commentTemp1;
    char commentTemp2;
    int ruleIndex;
    int ruleValue;
    char temp[256];
    FILE* file;

    if (strcmp(filename, "NONE") != 0 &&
        filename != 0 &&
        strlen(filename) != 0) {
        sprintf(temp, "%s", filename);
        file = fopen(temp, "r");
        if (file != 0) {
            while (fgets(temp, 0x100, file) != 0) {
                // The shipped parser ignores both sscanf results.
                // Keep these outputs uninitialized for malformed input.
                sscanf(temp, " %c%c",
                       &commentTemp1, &commentTemp2);
                if ((commentTemp1 != '/' || commentTemp2 != '/') &&
                    (commentTemp1 != 'D' || commentTemp2 != 'E') &&
                    (commentTemp1 != 'V' || commentTemp2 != 'C')) {
                    if (commentTemp1 == 'E' && commentTemp2 == 'N') {
                        break;
                    }
                    sscanf(temp, "%d %d ",
                           &ruleIndex, &ruleValue);
                    if (ruleIndex >= 0 && ruleIndex < 0xE2) {
                        this->sn[ruleIndex] = ruleValue;
                    }
                }
            }
            fclose(file);
            if (strstr(filename, ".tmp") != 0) {
                _unlink(filename);
            }
            return 1;
        }
    }
    return 0;
}

void VictoryConditionRuleSystem::setRule(int index, int val) {
    if (index < 0 || index >= 226) return;
    this->sn[index] = val;
}

int VictoryConditionRuleSystem::rule(int index) {
    if (index < 0 || index >= 226) return -1;
    return this->sn[index];
}


int VictoryConditionRuleSystem::evaluateAsInProgress(TRIBE_Player*, int) {
    return 0;
}

int VictoryConditionRuleSystem::evaluateAsNonInProgress(TRIBE_Player* player, int rule) {
    switch (rule) {
        case 1:
        case 2:
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:
            return -2;
        default:
            return 0;
    }
}

//   strategic-number storage, and the player -> main-decision -> tactical-AI ownership chain.



int VictoryConditionRuleSystem::execute(TRIBE_Player* player, int state, int command)
{
    if (state < 0 || state >= 0xD) {
        return 0;
    }

    switch (command) {
    case 1:
        player->playerAI->tacticalAI.setStrategicNumber(0, this->sn[0]);
        player->playerAI->tacticalAI.setStrategicNumber(1, this->sn[1]);
        player->playerAI->tacticalAI.setStrategicNumber(2, this->sn[2]);
        player->playerAI->tacticalAI.setStrategicNumber(3, this->sn[3]);
        player->playerAI->tacticalAI.setStrategicNumber(4, this->sn[4]);
        player->playerAI->tacticalAI.setStrategicNumber(5, this->sn[5]);
        player->playerAI->tacticalAI.setStrategicNumber(0x23, this->sn[0x23]);
        player->playerAI->tacticalAI.setStrategicNumber(100, this->sn[100]);
        player->playerAI->tacticalAI.setStrategicNumber(0xe1, this->sn[0xe1]);
        player->playerAI->tacticalAI.setStrategicNumber(0x75, this->sn[0x75]);
        player->playerAI->tacticalAI.setStrategicNumber(0x76, this->sn[0x76]);
        player->playerAI->tacticalAI.setStrategicNumber(0x77, this->sn[0x77]);
        player->playerAI->tacticalAI.setStrategicNumber(0x78, this->sn[0x78]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9c, this->sn[0x9c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9f, this->sn[0x9f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9e, this->sn[0x9e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9d, this->sn[0x9d]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa0, this->sn[0xa0]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8e, this->sn[0x8e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x94, this->sn[0x94]);
        player->playerAI->tacticalAI.setStrategicNumber(0x95, this->sn[0x95]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcb, this->sn[0xcb]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa3, this->sn[0xa3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa4, this->sn[0xa4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa6, this->sn[0xa6]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa5, this->sn[0xa5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa7, this->sn[0xa7]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb3, this->sn[0xb3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb4, this->sn[0xb4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcd, this->sn[0xcd]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcf, this->sn[0xcf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xce, this->sn[0xce]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdc, this->sn[0xdc]);
        player->playerAI->tacticalAI.setStrategicNumber(0xde, this->sn[0xde]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd0, this->sn[0xd0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd1, this->sn[0xd1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd2, this->sn[0xd2]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd3, this->sn[0xd3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdf, this->sn[0xdf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd4, this->sn[0xd4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd5, this->sn[0xd5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd6, this->sn[0xd6]);
        player->playerAI->tacticalAI.setStrategicNumber(0xe0, this->sn[0xe0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa9, this->sn[0xa9]);
        player->playerAI->tacticalAI.setStrategicNumber(0xaa, this->sn[0xaa]);
        player->playerAI->tacticalAI.setStrategicNumber(0xab, this->sn[0xab]);
        player->playerAI->tacticalAI.setStrategicNumber(0xac, this->sn[0xac]);
        player->playerAI->tacticalAI.setStrategicNumber(0xad, this->sn[0xad]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbe, this->sn[0xbe]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbf, this->sn[0xbf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc0, this->sn[0xc0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc1, this->sn[0xc1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xae, this->sn[0xae]);
        player->playerAI->tacticalAI.setStrategicNumber(0xcc, this->sn[0xcc]);
        break;
    case 2:
        player->playerAI->tacticalAI.setStrategicNumber(0x10, this->sn[0x10]);
        player->playerAI->tacticalAI.setStrategicNumber(0x1a, this->sn[0x1a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x24, this->sn[0x24]);
        player->playerAI->tacticalAI.setStrategicNumber(0x25, this->sn[0x25]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5d, this->sn[0x5d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5e, this->sn[0x5e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x62, this->sn[0x62]);
        player->playerAI->tacticalAI.setStrategicNumber(0x79, this->sn[0x79]);
        player->playerAI->tacticalAI.setStrategicNumber(0x83, this->sn[0x83]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8f, this->sn[0x8f]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa2, this->sn[0xa2]);
        break;
    case 0xc:
        player->playerAI->tacticalAI.setStrategicNumber(0x12, this->sn[0x12]);
        break;
    case 0xd:
        player->playerAI->tacticalAI.setStrategicNumber(0x13, this->sn[0x13]);
        break;
    case 0xe:
        player->playerAI->tacticalAI.setStrategicNumber(0x14, this->sn[0x14]);
        break;
    case 0x10:
        player->playerAI->tacticalAI.setStrategicNumber(0x16, this->sn[0x16]);
        player->playerAI->tacticalAI.setStrategicNumber(0x48, this->sn[0x48]);
        player->playerAI->tacticalAI.setStrategicNumber(0x39, this->sn[0x39]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5c, this->sn[0x5c]);
        break;
    case 0x11:
        player->playerAI->tacticalAI.setStrategicNumber(0x17, this->sn[0x17]);
        break;
    case 0x12:
        player->playerAI->tacticalAI.setStrategicNumber(0x18, this->sn[0x18]);
        break;
    case 0x15:
        player->playerAI->tacticalAI.setStrategicNumber(0x19, this->sn[0x19]);
        player->playerAI->tacticalAI.setStrategicNumber(0x1c, this->sn[0x1c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x26, this->sn[0x26]);
        player->playerAI->tacticalAI.setStrategicNumber(0x27, this->sn[0x27]);
        break;
    case 0x16:
        player->playerAI->tacticalAI.setStrategicNumber(0x1d, this->sn[0x1d]);
        break;
    case 0x17:
        player->playerAI->tacticalAI.setStrategicNumber(0x20, this->sn[0x20]);
        player->playerAI->tacticalAI.setStrategicNumber(0x91, this->sn[0x91]);
        break;
    case 0x18:
        player->playerAI->tacticalAI.setStrategicNumber(0x22, this->sn[0x22]);
        break;
    case 0x19:
        player->playerAI->tacticalAI.setStrategicNumber(0x28, this->sn[0x28]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4b, this->sn[0x4b]);
        break;
    case 0x1a:
        player->playerAI->tacticalAI.setStrategicNumber(0x29, this->sn[0x29]);
        break;
    case 0x1b:
        player->playerAI->tacticalAI.setStrategicNumber(0x2b, this->sn[0x2b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2c, this->sn[0x2c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2a, this->sn[0x2a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2d, this->sn[0x2d]);
        break;
    case 0x1c:
        player->playerAI->tacticalAI.setStrategicNumber(0x1e, this->sn[0x1e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x1f, this->sn[0x1f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5b, this->sn[0x5b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5f, this->sn[0x5f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x60, this->sn[0x60]);
        player->playerAI->tacticalAI.setStrategicNumber(0x61, this->sn[0x61]);
        break;
    case 0x1d:
        player->playerAI->tacticalAI.setStrategicNumber(0x2e, this->sn[0x2e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x66, this->sn[0x66]);
        player->playerAI->tacticalAI.setStrategicNumber(0x2f, this->sn[0x2f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x67, this->sn[0x67]);
        player->playerAI->tacticalAI.setStrategicNumber(0x68, this->sn[0x68]);
        player->playerAI->tacticalAI.setStrategicNumber(0x86, this->sn[0x86]);
        break;
    case 0x1e:
        player->playerAI->tacticalAI.setStrategicNumber(0x30, this->sn[0x30]);
        break;
    case 0x1f:
        player->playerAI->tacticalAI.setStrategicNumber(0x31, this->sn[0x31]);
        player->playerAI->tacticalAI.setStrategicNumber(0x87, this->sn[0x87]);
        player->playerAI->tacticalAI.setStrategicNumber(0x88, this->sn[0x88]);
        player->playerAI->tacticalAI.setStrategicNumber(200, this->sn[200]);
        break;
    case 0x20:
        player->playerAI->tacticalAI.setStrategicNumber(0x32, this->sn[0x32]);
        player->playerAI->tacticalAI.setStrategicNumber(0x33, this->sn[0x33]);
        player->playerAI->tacticalAI.setStrategicNumber(0x34, this->sn[0x34]);
        player->playerAI->tacticalAI.setStrategicNumber(0x35, this->sn[0x35]);
        player->playerAI->tacticalAI.setStrategicNumber(0x36, this->sn[0x36]);
        player->playerAI->tacticalAI.setStrategicNumber(0x37, this->sn[0x37]);
        player->playerAI->tacticalAI.setStrategicNumber(0x38, this->sn[0x38]);
        player->playerAI->tacticalAI.setStrategicNumber(0x46, this->sn[0x46]);
        break;
    case 0x21:
        player->playerAI->tacticalAI.setStrategicNumber(0x3a, this->sn[0x3a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3b, this->sn[0x3b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3c, this->sn[0x3c]);
        break;
    case 0x22:
        player->playerAI->tacticalAI.setStrategicNumber(0x3d, this->sn[0x3d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3e, this->sn[0x3e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x3f, this->sn[0x3f]);
        break;
    case 0x23:
        player->playerAI->tacticalAI.setStrategicNumber(0x40, this->sn[0x40]);
        player->playerAI->tacticalAI.setStrategicNumber(0x41, this->sn[0x41]);
        player->playerAI->tacticalAI.setStrategicNumber(0x42, this->sn[0x42]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd8, this->sn[0xd8]);
        break;
    case 0x24:
        player->playerAI->tacticalAI.setStrategicNumber(0x43, this->sn[0x43]);
        player->playerAI->tacticalAI.setStrategicNumber(0x44, this->sn[0x44]);
        player->playerAI->tacticalAI.setStrategicNumber(0x45, this->sn[0x45]);
        break;
    case 0x25:
        player->playerAI->tacticalAI.setStrategicNumber(0x47, this->sn[0x47]);
        break;
    case 0x26:
        player->playerAI->tacticalAI.setStrategicNumber(0x49, this->sn[0x49]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4a, this->sn[0x4a]);
        break;
    case 0x27:
        player->playerAI->tacticalAI.setStrategicNumber(0x4c, this->sn[0x4c]);
        break;
    case 0x28:
        player->playerAI->tacticalAI.setStrategicNumber(0x4d, this->sn[0x4d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4e, this->sn[0x4e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x4f, this->sn[0x4f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x50, this->sn[0x50]);
        player->playerAI->tacticalAI.setStrategicNumber(0x51, this->sn[0x51]);
        player->playerAI->tacticalAI.setStrategicNumber(0x52, this->sn[0x52]);
        player->playerAI->tacticalAI.setStrategicNumber(0x53, this->sn[0x53]);
        player->playerAI->tacticalAI.setStrategicNumber(0x59, this->sn[0x59]);
        player->playerAI->tacticalAI.setStrategicNumber(0x5a, this->sn[0x5a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6a, this->sn[0x6a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6b, this->sn[0x6b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6c, this->sn[0x6c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6d, this->sn[0x6d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6e, this->sn[0x6e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x6f, this->sn[0x6f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7a, this->sn[0x7a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7b, this->sn[0x7b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x90, this->sn[0x90]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb8, this->sn[0xb8]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb9, this->sn[0xb9]);
        break;
    case 0x29:
        player->playerAI->tacticalAI.setStrategicNumber(0x54, this->sn[0x54]);
        player->playerAI->tacticalAI.setStrategicNumber(0x55, this->sn[0x55]);
        player->playerAI->tacticalAI.setStrategicNumber(0x89, this->sn[0x89]);
        break;
    case 0x2a:
        player->playerAI->tacticalAI.setStrategicNumber(0x56, this->sn[0x56]);
        player->playerAI->tacticalAI.setStrategicNumber(0x57, this->sn[0x57]);
        player->playerAI->tacticalAI.setStrategicNumber(0xca, this->sn[0xca]);
        player->playerAI->tacticalAI.setStrategicNumber(0x96, this->sn[0x96]);
        player->playerAI->tacticalAI.setStrategicNumber(0x97, this->sn[0x97]);
        player->playerAI->tacticalAI.setStrategicNumber(0x98, this->sn[0x98]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa1, this->sn[0xa1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xa8, this->sn[0xa8]);
        break;
    case 0x2b:
        player->playerAI->tacticalAI.setStrategicNumber(0x58, this->sn[0x58]);
        player->playerAI->tacticalAI.setStrategicNumber(0x65, this->sn[0x65]);
        player->playerAI->tacticalAI.setStrategicNumber(0x9b, this->sn[0x9b]);
        player->playerAI->tacticalAI.setStrategicNumber(0xaf, this->sn[0xaf]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb0, this->sn[0xb0]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb1, this->sn[0xb1]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb5, this->sn[0xb5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb6, this->sn[0xb6]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb7, this->sn[0xb7]);
        player->playerAI->tacticalAI.setStrategicNumber(0xba, this->sn[0xba]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbb, this->sn[0xbb]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc2, this->sn[0xc2]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc4, this->sn[0xc4]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc5, this->sn[0xc5]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbc, this->sn[0xbc]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc3, this->sn[0xc3]);
        player->playerAI->tacticalAI.setStrategicNumber(0xbd, this->sn[0xbd]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc6, this->sn[0xc6]);
        player->playerAI->tacticalAI.setStrategicNumber(199, this->sn[199]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd7, this->sn[0xd7]);
        player->playerAI->tacticalAI.setStrategicNumber(0xd9, this->sn[0xd9]);
        player->playerAI->tacticalAI.setStrategicNumber(0xda, this->sn[0xda]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdb, this->sn[0xdb]);
        player->playerAI->tacticalAI.setStrategicNumber(0xdd, this->sn[0xdd]);
        break;
    case 0x2c:
        player->playerAI->tacticalAI.setStrategicNumber(99, this->sn[99]);
        break;
    case 0x2d:
        player->playerAI->tacticalAI.setStrategicNumber(0x69, this->sn[0x69]);
        break;
    case 0x2e:
        player->playerAI->tacticalAI.setStrategicNumber(0x70, this->sn[0x70]);
        break;
    case 0x2f:
        player->playerAI->tacticalAI.setStrategicNumber(0x71, this->sn[0x71]);
        player->playerAI->tacticalAI.setStrategicNumber(0x72, this->sn[0x72]);
        player->playerAI->tacticalAI.setStrategicNumber(0x73, this->sn[0x73]);
        player->playerAI->tacticalAI.setStrategicNumber(0x74, this->sn[0x74]);
        player->playerAI->tacticalAI.setStrategicNumber(0x92, this->sn[0x92]);
        player->playerAI->tacticalAI.setStrategicNumber(0x93, this->sn[0x93]);
        break;
    case 0x30:
        player->playerAI->tacticalAI.setStrategicNumber(0x7c, this->sn[0x7c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7d, this->sn[0x7d]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7e, this->sn[0x7e]);
        player->playerAI->tacticalAI.setStrategicNumber(0x7f, this->sn[0x7f]);
        player->playerAI->tacticalAI.setStrategicNumber(0x80, this->sn[0x80]);
        player->playerAI->tacticalAI.setStrategicNumber(0x81, this->sn[0x81]);
        player->playerAI->tacticalAI.setStrategicNumber(0x82, this->sn[0x82]);
        player->playerAI->tacticalAI.setStrategicNumber(0x84, this->sn[0x84]);
        player->playerAI->tacticalAI.setStrategicNumber(0x85, this->sn[0x85]);
        player->playerAI->tacticalAI.setStrategicNumber(0xb2, this->sn[0xb2]);
        player->playerAI->tacticalAI.setStrategicNumber(0xc9, this->sn[0xc9]);
        break;
    case 0x31:
        player->playerAI->tacticalAI.setStrategicNumber(0x8a, this->sn[0x8a]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8b, this->sn[0x8b]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8c, this->sn[0x8c]);
        player->playerAI->tacticalAI.setStrategicNumber(0x8d, this->sn[0x8d]);
        break;
    default:
        return 0;
    }

    return 1;
}


int VictoryConditionRuleSystem::stopExecution(TRIBE_Player*, int) {
    return 0;
}


struct ScaleLocals {
    float scale1;
    float scale2;
    int tmp;
};

void VictoryConditionRuleSystem::modifyForDifficultyLevel(int level)
{
    if (level != 0) {
        int add1 = 0;
        int add2 = 0;
        int add3 = 0;
        ScaleLocals locals;
        locals.scale1 = 1.0f;
        locals.scale2 = 1.0f;

        switch (level) {
        case 1:
            if (rge_base_game->scenarioGame() == 1) {
                locals.scale1 = 0.8f;
                add1 = 30;
                locals.scale2 = 0.8f;
                add2 = 120;
                add3 = 1;
            }
            break;
        case 2:
            locals.scale1 = 0.6f;
            add1 = 60;
            locals.scale2 = 0.6f;
            add2 = 240;
            add3 = 2;
            break;
        case 3:
            locals.scale1 = 0.4f;
            add1 = 90;
            locals.scale2 = 0.4f;
            add2 = (rge_base_game->scenarioGame() == 1) ? 360 : 900;
            add3 = 3;
            break;
        case 4:
            locals.scale1 = 0.2f;
            add1 = 120;
            locals.scale2 = 0.2f;
            add2 = (rge_base_game->scenarioGame() == 1) ? 480 : 1260;
            add3 = 4;
            break;
        default:
            return;
        }

        locals.tmp = this->sn[0x24];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x24] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x24] = 1;
            }
        }
        locals.tmp = this->sn[0x10];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x10] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x10] = 1;
            }
        }
        locals.tmp = this->sn[0x1A];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x1A] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x1A] = 1;
            }
        }

        this->sn[0x2E] += add1;
        this->sn[0x30] += add1;

        locals.tmp = this->sn[0x13];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale2);
            this->sn[0x13] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x13] = 1;
            }
        }
        locals.tmp = this->sn[0x14];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale2);
            this->sn[0x14] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x14] = 1;
            }
        }

        this->sn[0x68] += add2;

        locals.tmp = this->sn[0x19];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x19] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x19] = 1;
            }
        }
        locals.tmp = this->sn[0x1C];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x1C] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x1C] = 1;
            }
        }
        locals.tmp = this->sn[0x26];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x26] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x26] = 1;
            }
        }
        locals.tmp = this->sn[0x3A];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x3A] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x3A] = 1;
            }
        }
        locals.tmp = this->sn[0x3B];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x3B] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x3B] = 1;
            }
        }
        locals.tmp = this->sn[0x3C];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x3C] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x3C] = 1;
            }
        }
        locals.tmp = this->sn[0x43];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x43] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x43] = 1;
            }
        }
        locals.tmp = this->sn[0x44];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x44] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x44] = 1;
            }
        }
        locals.tmp = this->sn[0x45];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x45] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x45] = 1;
            }
        }

        this->sn[0x58] += add3;
        if (level <= 3) {
            this->sn[0x67] = 1;
        } else {
            this->sn[0x67] = 0;
        }
    }
}


extern "C" char* __cdecl strcpy(char* destination, const char* source);

TribeStrategyAIModule::TribeStrategyAIModule(void* object, int parameter)
    : StrategyAIModule(object, parameter),
      md(0),
      currentVictoryConditionValue(-1),
      targetIDValue(-1),
      targetTypeValue(-1),
      secondTargetIDValue(-1),
      secondTargetTypeValue(-1),
      targetAttributeValue(-1),
      targetNumberValue(-1),
      victoryConditionChangeTimeout(0),
      vcRuleSet(),
      executingRules(),
      idleRules(),
      vcRules(),
      difficultyLevel(0)
{
    this->targetPoint1Value.x = -1.0f;
    this->targetPoint1Value.y = -1.0f;
    this->targetPoint1Value.z = -1.0f;
    this->targetPoint2Value.x = -1.0f;
    this->targetPoint2Value.y = -1.0f;
    this->targetPoint2Value.z = -1.0f;
    strcpy(this->ruleSetNameValue, "");
}


extern "C" void __cdecl rge_read(int file, void* dst, int size);
extern float save_game_version;
extern float DAT_00575690;


TribeStrategyAIModule::TribeStrategyAIModule(int playerID, int infile)
    : StrategyAIModule((void*)0, playerID),
      md(0),
      vcRuleSet(),
      executingRules(),
      idleRules(),
      vcRules(),
      difficultyLevel(0)
{
    rge_read(infile, &this->currentVictoryConditionValue, 4);
    rge_read(infile, &this->targetIDValue, 4);
    rge_read(infile, &this->secondTargetIDValue, 4);
    rge_read(infile, &this->secondTargetTypeValue, 4);
    rge_read(infile, &this->targetPoint1Value, 0x10);
    rge_read(infile, &this->targetPoint2Value, 0x10);
    rge_read(infile, &this->targetAttributeValue, 4);
    rge_read(infile, &this->targetNumberValue, 4);
    rge_read(infile, &this->victoryConditionChangeTimeout, 4);
    if (save_game_version >= DAT_00575690) {
        rge_read(infile, &this->difficultyLevel, 4);
    }

    int tempIntNum;
    int i;
    int tempInt;

    rge_read(infile, &tempIntNum, 4);
    rge_read(infile, this->ruleSetNameValue, tempIntNum);
    this->ruleSetNameValue[tempIntNum] = 0;
    this->loadRules(this->ruleSetNameValue);
    this->setDifficultyLevel(this->difficultyLevel);

    rge_read(infile, &tempInt, 4);
    for (i = 0; i < tempInt; ++i) {
        rge_read(infile, &tempIntNum, 4);
        this->vcRuleSet.add(tempIntNum);
    }
    rge_read(infile, &tempInt, 4);
    for (i = 0; i < tempInt; ++i) {
        rge_read(infile, &tempIntNum, 4);
        this->executingRules.add(tempIntNum);
    }
    rge_read(infile, &tempInt, 4);
    for (i = 0; i < tempInt; ++i) {
        rge_read(infile, &tempIntNum, 4);
        this->idleRules.add(tempIntNum);
    }
}


void __cdecl operator delete(void* ptr);


TribeStrategyAIModule::~TribeStrategyAIModule() {
}


extern void* __cdecl operator new(unsigned int size);
extern void __cdecl operator delete(void* pointer);


int TribeStrategyAIModule::update(int parameter)
{
    int i = 0;
    RGE_Victory_Entry* victoryEntry;
    unsigned int victoryCondition;

    this->victoryConditionChangeTimeout++;
    if (this->victoryConditionChangeTimeout >= 0) {
        this->victoryConditionChangeTimeout = i;
        victoryCondition = 0x0B;
        victoryEntry = this->md->player->victory_conditions->condition_raw_info(i);
        if (victoryEntry != 0) {
            victoryCondition = victoryEntry->command;
            if (victoryEntry->target_obj != 0) {
                this->targetIDValue = victoryEntry->target_obj->id;
                this->targetTypeValue = victoryEntry->target_obj->master_obj->id;
            }
            if (victoryEntry->this_obj != 0) {
                this->secondTargetIDValue = victoryEntry->this_obj->id;
                this->secondTargetTypeValue = victoryEntry->this_obj->master_obj->id;
            }
            this->targetPoint1Value.x = victoryEntry->x0;
            this->targetPoint1Value.y = victoryEntry->y0;
            this->targetPoint1Value.z = 1.0f;
            this->targetPoint2Value.x = victoryEntry->x1;
            this->targetPoint2Value.y = victoryEntry->y1;
            this->targetPoint2Value.z = 1.0f;
            this->targetAttributeValue = victoryEntry->number;
            this->targetNumberValue = victoryEntry->count;
        }
        if (victoryCondition != (unsigned int)this->currentVictoryConditionValue) {
            this->setVictoryCondition(victoryCondition);
        }
    }

    int result;
    int bestResult;
    int worstRuleResult;
    int ruleResult;

    result = -1;
    bestResult = 0;
    worstRuleResult = -1;
    if (i < this->idleRules.numberValue) {
        ManagedArray<int>* idleRules = &this->idleRules;
        do {
            ruleResult = this->vcRules.evaluateAsNonInProgress(
                this->md->aiPlayer,
                (*idleRules)[i]);
            if (ruleResult > bestResult) {
                result = (*idleRules)[i];
                bestResult = ruleResult;
            }
            ++i;
        } while (i < this->idleRules.numberValue);
    }

    if (result != -1 &&
        this->vcRules.execute(
            this->md->aiPlayer,
            this->currentVictoryConditionValue,
            result) == 1) {
        ManagedArray<int>* executingRules = &this->executingRules;
        if (executingRules->add(result) == 0)
            goto remove_idle_rule;

remove_idle_rule:
        int idleCount = this->idleRules.maximumSizeValue;
        i = 0;
        int* idleValue = this->idleRules.value;
        while (i < idleCount) {
            if (*idleValue == result) {
                break;
            }
            ++i;
            ++idleValue;
        }
        if (i < idleCount) {
            if (i < idleCount - 1) {
                do {
                    this->idleRules.value[i] = this->idleRules.value[i + 1];
                    ++i;
                } while (i < this->idleRules.maximumSizeValue - 1);
            }
            this->idleRules.numberValue--;
            if (this->idleRules.numberValue < 0) {
                this->idleRules.numberValue = 0;
            }
        }
    }

    i = 0;
    result = 0x65;
    worstRuleResult = -1;
    if (this->executingRules.numberValue > 0) {
        ManagedArray<int>* executingRules = &this->executingRules;
        do {
            ruleResult = this->vcRules.evaluateAsInProgress(
                this->md->aiPlayer,
                (*executingRules)[i]);
            if (ruleResult < result) {
                worstRuleResult = (*executingRules)[i];
                result = ruleResult;
            }
            ++i;
        } while (i < this->executingRules.numberValue);
    }

    if (worstRuleResult != -1 &&
        this->vcRules.stopExecution(this->md->aiPlayer, worstRuleResult) == 1) {
        int executingSize = this->executingRules.maximumSizeValue;
        i = 0;
        int* executingValue = this->executingRules.value;
        while (i < executingSize) {
            if (*executingValue == worstRuleResult) {
                break;
            }
            ++i;
            ++executingValue;
        }
        if (i < executingSize) {
            if (i < executingSize - 1) {
                do {
                    this->executingRules.value[i] = this->executingRules.value[i + 1];
                    ++i;
                } while (i < this->executingRules.maximumSizeValue - 1);
            }
            this->executingRules.numberValue--;
            if (this->executingRules.numberValue < 0) {
                this->executingRules.numberValue = 0;
            }
        }

        ManagedArray<int>* idleRules = &this->idleRules;
        int idleCount = idleRules->numberValue;
        i = 0;
        if (idleCount > 0) {
            while (i < idleCount && i < idleRules->maximumSizeValue) {
                if (idleRules->value[i] == worstRuleResult) {
                    goto add_idle_rule;
                }
                ++i;
            }
        }
        idleRules->add(worstRuleResult);

add_idle_rule:
        ;
    }

    i = 0;
    if (this->vcRuleSet.numberValue > 0) {
        do {
            ruleResult = this->vcRules.evaluateAsNonInProgress(
                this->md->aiPlayer, this->vcRuleSet[i]);
            if (ruleResult == -1) {
                this->vcRules.execute(
                    this->md->aiPlayer,
                    this->currentVictoryConditionValue,
                    this->vcRuleSet[i]);
            }
            ++i;
        } while (i < this->vcRuleSet.numberValue);
    }
    return 1;
}

void TribeStrategyAIModule::setMainDecisionAI(TribeMainDecisionAIModule* v) {
    this->md = v;
}

// and three grow-while-saving integer arrays mirroring UnitAIModule::save pattern.
// the first ten writes begin at +0xF4 and skip targetType at
// +0x200; the canonical class layout also places md at +0xF0.
// The standalone declaration mirrors that inherited layout for source checks.

#include <string.h>

void __cdecl rge_write(int fd, const void* data, int size);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);


int TribeStrategyAIModule::save(int fd)
{
    int temp;
    char tempString[260];
    int i;

    rge_write(fd, &this->currentVictoryConditionValue, 4);
    rge_write(fd, &this->targetIDValue, 4);
    rge_write(fd, &this->secondTargetIDValue, 4);
    rge_write(fd, &this->secondTargetTypeValue, 4);
    rge_write(fd, &this->targetPoint1Value, 16);
    rge_write(fd, &this->targetPoint2Value, 16);
    rge_write(fd, &this->targetAttributeValue, 4);
    rge_write(fd, &this->targetNumberValue, 4);
    rge_write(fd, &this->victoryConditionChangeTimeout, 4);
    rge_write(fd, &this->difficultyLevel, 4);

    strcpy(tempString, this->ruleSetNameValue);
    temp = strlen(tempString);
    rge_write(fd, &temp, 4);
    rge_write(fd, tempString, strlen(tempString));

    temp = this->vcRuleSet.numberValue;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->vcRuleSet.numberValue; i++) {
        if (i > this->vcRuleSet.maximumSizeValue - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->vcRuleSet.maximumSizeValue && j < newMax; j++) {
                    newArr[j] = this->vcRuleSet.value[j];
                }
                operator delete(this->vcRuleSet.value);
                this->vcRuleSet.value = newArr;
                this->vcRuleSet.maximumSizeValue = newMax;
            }
        }
        temp = this->vcRuleSet.value[i];
        rge_write(fd, &temp, 4);
    }

    temp = this->executingRules.numberValue;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->executingRules.numberValue; i++) {
        if (i > this->executingRules.maximumSizeValue - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->executingRules.maximumSizeValue && j < newMax; j++) {
                    newArr[j] = this->executingRules.value[j];
                }
                operator delete(this->executingRules.value);
                this->executingRules.value = newArr;
                this->executingRules.maximumSizeValue = newMax;
            }
        }
        temp = this->executingRules.value[i];
        rge_write(fd, &temp, 4);
    }

    temp = this->idleRules.numberValue;
    rge_write(fd, &temp, 4);
    for (i = 0; i < this->idleRules.numberValue; i++) {
        if (i > this->idleRules.maximumSizeValue - 1) {
            int newMax = i + 1;
            int* newArr = (int*)operator new(i * 4 + 4);
            if (newArr) {
                int j;
                for (j = 0; j < this->idleRules.maximumSizeValue && j < newMax; j++) {
                    newArr[j] = this->idleRules.value[j];
                }
                operator delete(this->idleRules.value);
                this->idleRules.value = newArr;
                this->idleRules.maximumSizeValue = newMax;
            }
        }
        temp = this->idleRules.value[i];
        rge_write(fd, &temp, 4);
    }

    return 1;
}

char* TribeStrategyAIModule::ruleSetName() {
    return this->ruleSetNameValue;
}

char* strncpy(char* dest, const char* src, unsigned int count);


int TribeStrategyAIModule::loadRules(char* name) {
    if (name == 0) {
        return (int)name;
    }
    strncpy(this->ruleSetNameValue, name, 0xFF);
    return ((VictoryConditionRuleSystem*)((char*)this + 0x268))->loadRules(this->ruleSetNameValue);
}

void TribeStrategyAIModule::setRule(int rule, int value) {
    this->logCommonHistory((char*)"Setting SN[%d] to %d.", rule, value);
    this->vcRules.setRule(rule, value);
}

int TribeStrategyAIModule::rule(int param) {
    return this->vcRules.rule(param);
}

void TribeStrategyAIModule::setDifficultyLevel(int param) {
    this->vcRules.modifyForDifficultyLevel(param);
}

int TribeStrategyAIModule::currentVictoryCondition() const {
    return this->currentVictoryConditionValue;
}

int TribeStrategyAIModule::targetID() const {
    return this->targetIDValue;
}

int TribeStrategyAIModule::targetType() const {
    return this->targetTypeValue;
}

int TribeStrategyAIModule::secondTargetID() const {
    return this->secondTargetIDValue;
}

int TribeStrategyAIModule::secondTargetType() const {
    return this->secondTargetTypeValue;
}

const Waypoint& TribeStrategyAIModule::targetPoint1() const {
    return this->targetPoint1Value;
}

const Waypoint& TribeStrategyAIModule::targetPoint2() const {
    return this->targetPoint2Value;
}

int TribeStrategyAIModule::targetAttribute() const {
    return this->targetAttributeValue;
}

int TribeStrategyAIModule::targetNumber() const {
    return this->targetNumberValue;
}


class TRIBE_Player;


#define ADD_REQUIRED(valueToAdd) do { \
    v = (valueToAdd); \
    if (rules->contains(v) != 1) { \
        if (rules->numberValue > rules->maximumSizeValue - 1) \
            rules->resize(rules->numberValue + 1); \
        rules->value[rules->numberValue] = v; \
        rules->numberValue++; \
    } \
} while (0)

// this add-heavy body uses the out-of-line ManagedArray::operator[]
// calls shown at 004EA6EF, 004EA71A, and 004EA72A.
#pragma inline_depth(0)

void TribeStrategyAIModule::setVictoryCondition(int v)
{
    int& currentReference = this->currentVictoryConditionValue;
    currentReference = v;
    this->vcRuleSet.numberValue = 0;

    v = 1;
    if (this->vcRuleSet.contains(v) != 1) {
        ManagedArray<int>* firstRules = &this->vcRuleSet;
        if (firstRules->numberValue > firstRules->maximumSizeValue - 1)
            firstRules->resize(firstRules->numberValue + 1);
        firstRules->value[firstRules->numberValue] = v;
        firstRules->numberValue++;
    }

    ManagedArray<int>* rules = &this->vcRuleSet;
    ADD_REQUIRED(2);
    ADD_REQUIRED(0x0C);
    ADD_REQUIRED(0x0D);
    ADD_REQUIRED(0x0E);
    ADD_REQUIRED(0x10);
    ADD_REQUIRED(0x11);
    ADD_REQUIRED(0x12);
    ADD_REQUIRED(0x15);
    ADD_REQUIRED(0x16);
    ADD_REQUIRED(0x17);
    ADD_REQUIRED(0x18);
    ADD_REQUIRED(0x19);

    rules->add(0x1A);
    rules->add(0x1B);
    rules->add(0x1C);
    rules->add(0x1D);
    rules->add(0x1E);
    rules->add(0x1F);
    rules->add(0x20);
    rules->add(0x21);
    rules->add(0x22);
    rules->add(0x23);
    rules->add(0x24);
    rules->add(0x25);
    rules->add(0x26);
    rules->add(0x27);
    rules->add(0x28);
    rules->add(0x29);
    rules->add(0x2A);
    rules->add(0x2B);
    rules->add(0x2C);
    rules->add(0x2D);
    rules->add(0x2E);
    rules->add(0x2F);
    rules->add(0x30);
    rules->add(0x31);

    int i = 0;
    if (this->vcRuleSet.numberValue > 0) {
        do {
            if (this->vcRules.evaluateAsNonInProgress(
                    this->md->aiPlayer, (*rules)[i]) == -2) {
                if (this->vcRules.execute(
                        this->md->aiPlayer,
                        this->currentVictoryConditionValue,
                        (*rules)[i]) == 1) {
                    this->executingRules.add((*rules)[i]);
                } else {
                    this->idleRules.add((*rules)[i]);
                }
            }
            ++i;
        } while (i < this->vcRuleSet.numberValue);
    }
}



int TribeStrategyAIModule::isRuleExecuting(int ruleId) {
    int i;

    for (i = 0; i < this->executingRules.numberValue; i = i + 1) {
        if (i >= this->executingRules.maximumSizeValue) {
            return 0;
        }
        if (this->executingRules.value[i] == ruleId) {
            return 1;
        }
    }
    return 0;
}



int TribeStrategyAIModule::isRuleIdle(int rule_id) {
    int i;

    for (i = 0; i < this->idleRules.numberValue; i = i + 1) {
        if (i >= this->idleRules.maximumSizeValue) {
            return 0;
        }
        if (this->idleRules.value[i] == rule_id) {
            return 1;
        }
    }
    return 0;
}
