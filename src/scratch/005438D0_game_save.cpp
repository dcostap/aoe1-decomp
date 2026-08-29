// RGE_Game_World::base_save (00543850) / game_save (005438D0)
// Size: 228 bytes (function fragment starting at 005438D0)

struct RGE_Color_Table;
struct RGE_Sound;
struct RGE_Sprite;
struct RGE_Map;
struct RGE_Effects;
struct RGE_Master_Player;

struct RGE_Game_World {
    unsigned char g0[0x28];
    struct RGE_Map* map;                   // +0x28
    unsigned char g1[0x04];
    short sound_num;                       // +0x2C (from ghidra: +0x2C)
    unsigned char g2[0x02];
    RGE_Sound** sounds;                    // +0x30
    short sprite_num;                      // +0x34
    unsigned char g3[0x02];
    RGE_Sprite** sprites;                  // +0x38
    unsigned char g4[0x0C];
    short master_player_num;               // +0x44 (from ghidra: +0x44)
    unsigned char g5[0x02];
    RGE_Master_Player** master_players;    // +0x48
    unsigned char g6[0x04];
    struct RGE_Effects* effects;           // +0x4C
    short terrain_num;                     // +0x50
    short terrain_size;                    // +0x52
    float** terrains;                      // +0x54
    unsigned char g7[0x0C];
    short color_table_num;                 // +0x60 (from ghidra: +0x60)
    unsigned char g8[0x02];
    RGE_Color_Table** color_tables;        // +0x64
};

extern "C" void rge_write(int param_1, void* param_2, int param_3);

void RGE_Game_World::game_save(int param_1)
{
    short* psVar1;
    int iVar2;
    int cp1;

    cp1 = param_1;
    psVar1 = &color_table_num;
    rge_write(cp1, psVar1, 2);
    iVar2 = 0;
    if (0 < *psVar1) {
        do {
            RGE_Color_Table::save(color_tables[iVar2], cp1);
            iVar2 = iVar2 + 1;
        } while (iVar2 < *psVar1);
    }
    psVar1 = &sound_num;
    rge_write(cp1, psVar1, 2);
    iVar2 = 0;
    if (0 < *psVar1) {
        do {
            RGE_Sound::save(sounds[iVar2], cp1);
            iVar2 = iVar2 + 1;
        } while (iVar2 < *psVar1);
    }
    psVar1 = &sprite_num;
    rge_write(cp1, psVar1, 2);
    rge_write(cp1, sprites, (int)*psVar1 << 2);
    iVar2 = 0;
    if (0 < *psVar1) {
        do {
            if (sprites[iVar2] != (RGE_Sprite*)0x0) {
                RGE_Sprite::save(sprites[iVar2], cp1);
            }
            iVar2 = iVar2 + 1;
        } while (iVar2 < *psVar1);
    }
    map->save(cp1);
    effects->save(cp1);
    psVar1 = &master_player_num;
    rge_write(cp1, psVar1, 2);
    iVar2 = 0;
    if (0 < *psVar1) {
        do {
            master_players[iVar2]->save(cp1);
            iVar2 = iVar2 + 1;
        } while (iVar2 < *psVar1);
    }
}
