// 005425B0 RGE_Game_World::setup_player_colors (World.cpp:1173-1220, 295B)
// Assigns color tables to players from player info, with fallback search.
//
// Left in scratch: VC5 register allocation and comparison structure differences:
// - colorIdx in ebp instead of ebx (register allocation choice)
// - info param kept in register (edi) vs reloaded from stack ([esp+20h])
// - player_num comparison: `mov ax,[esi+3Ch]; cmp ax,1` vs `cmp [esi+3Ch], di`
// - First loop: adds info+25Ch to ptr vs lea ebp,[ecx+25Ch]
// - stack local assignment: [esp+14h] vs [esp+18h] for maxIter
// All field offsets, calloc/free pattern, loop bounds, and color search logic verified.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void* calloc(int num, int size);
extern "C" void free(void* ptr);

struct ColorTable2 {
    char _gap_00[0x24];
    unsigned char type;   // +0x24
};

struct RGE_PlayerShort3 {
    char _gap_00[4];
    void set_color_table(unsigned char color);
    char _gap_04[0x220 - 4];
};

struct RGE_PlayerInfo2 {
    char _gap_00[0x25C];
    short color[9];      // +0x25C
    char _gap_26E[0x294 - 0x26E];
    short player_num;    // +0x294
};

struct RGE_GameWorldShort3 {
    char _gap_00[0x3C];
    short player_num;
    char _gap_3E[2];
    RGE_PlayerShort3** players;
    char _gap_44[0x60 - 0x44];
    short color_table_num;
    char _gap_62[2];
    ColorTable2** color_tables;

    void setup_player_colors(RGE_PlayerInfo2* info);
};

void RGE_GameWorldShort3::setup_player_colors(RGE_PlayerInfo2* info) {
    players[0]->set_color_table((unsigned char)7);

    int colorIdx = -1;

    int maxPlayerNum = player_num + 1;
    int maxIter = info->player_num;
    if (maxIter > maxPlayerNum) {
        maxIter = maxPlayerNum;
    }

    unsigned char* colorsUsed = (unsigned char*)calloc(color_table_num, 1);
    unsigned char* playersDone = (unsigned char*)calloc(player_num, 1);

    // First pass: use colors from player info
    if (player_num > 1) {
        short* colorPtr = info->color;
        for (int i = 1; i < player_num; i++) {
            if (i - 1 < maxIter) {
                short c = *colorPtr;
                if (c >= 0) {
                    if (colorsUsed[c] == 0) {
                        players[i]->set_color_table((unsigned char)c);
                        colorsUsed[c] = 1;
                        playersDone[i] = 1;
                    }
                }
            }
            colorPtr++;
        }
    }

    // Second pass: assign remaining colors to unassigned players
    if (player_num > 1) {
        for (int i = 1; i < player_num; i++) {
            if (playersDone[i] == 0) {
                do {
                    colorIdx++;
                } while (colorsUsed[colorIdx] == 1 || color_tables[colorIdx]->type != 1);

                players[i]->set_color_table((unsigned char)colorIdx);
                colorsUsed[colorIdx] = 1;
            }
        }
    }

    free(colorsUsed);
    free(playersDone);
}
