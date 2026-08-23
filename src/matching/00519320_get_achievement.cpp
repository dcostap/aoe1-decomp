// 00519320 TRIBE_Player::get_achievement (tplayer.cpp:4819-4855, 325B)
// Switch on achievement type (0-8), writes formatted result to output buffer.
// FLAGS: /nologo /c /O2 /Oy

#include "../../include/tplayer_context.h"

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
