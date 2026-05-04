// 00519320 TRIBE_Player::get_achievement (tplayer.cpp:4819-4855, 325B)
// Switch on achievement type (0-8), writes formatted result to output buffer.
// FLAGS: /nologo /c /O2 /Oy

extern "C" char* strcpy(char* dst, const char* src);
extern "C" int sprintf(char* buf, const char* fmt, ...);

struct RGE_Visible_Map {
    float percentExplored();
};

struct TRIBE_Player {
    // Use flat layout: RGE_Player base fields + TRIBE_Player fields
    // Layout from RGE_Player type dump: vtable at +0x00, visible at +0x38,
    // name at +0x44, attributes at +0x50
    char _pad_00[0x38];             // +0x00 to +0x37
    RGE_Visible_Map* visible_map;    // +0x38
    char _pad_3C[0x44 - 0x3C];      // +0x3C
    char* name;                      // +0x44
    char _pad_48[0x50 - 0x48];      // +0x48
    float* attributes;               // +0x50

    void get_achievement(unsigned char type, char* buffer);
};

void TRIBE_Player::get_achievement(unsigned char type, char* buffer)
{
    switch (type) {
    case 0:
        strcpy(buffer, name);
        break;
    case 1:
        sprintf(buffer, "%4.f", (double)(attributes[19] - attributes[11]));
        break;
    case 2:
        sprintf(buffer, "%4.f", (double)attributes[20]);
        break;
    case 3:
        sprintf(buffer, "%4.f", (double)attributes[11]);
        break;
    case 4:
        sprintf(buffer, "%5.f", (double)attributes[3]);
        break;
    case 5: {
        float pct = visible_map->percentExplored() * 100.0f;
        sprintf(buffer, "%3.f%%", (double)pct);
        break;
    }
    case 6:
        sprintf(buffer, "%4.f", (double)attributes[19]);
        break;
    case 7:
        sprintf(buffer, "%4.f/%4.f/%4.f",
            (double)attributes[7],
            (double)attributes[13],
            (double)attributes[14]);
        break;
    case 8:
        sprintf(buffer, "%4.f", (double)attributes[21]);
        break;
    }
}
