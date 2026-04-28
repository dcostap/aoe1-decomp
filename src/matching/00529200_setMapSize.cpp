// 00529200 TRIBE_Game::setMapSize
// Source: tribegam.cpp lines 4532-4554. 124 bytes. __thiscall, ret 4.
//
// MATCHED. Exact 124-byte match confirmed via local check_function.py.
// Key: gap array char[0xA7C] before tribe_game_options to get correct
// +0xA7C member offset. C-style cast to RGE_Base_Game* for base call.

class RGE_Base_Game {
public:
    void setMapSize(int x, int y, int z);
};

class TRIBE_Game {
public:
    enum MapSize {
        Tiny = 0,
        Small = 1,
        Medium = 2,
        Large = 3,
        Huge = 4,
        Humongous = 5
    };

    struct TRIBE_Game_Options {
        MapSize mapSizeValue;
    };

    char gap_00[0xA7C];
    TRIBE_Game_Options tribe_game_options; // at +0xA7C

    void setMapSize(MapSize size);
};

void TRIBE_Game::setMapSize(MapSize size) {
    this->tribe_game_options.mapSizeValue = size;
    switch (size) {
    case Tiny:
        ((RGE_Base_Game*)this)->setMapSize(0x48, 0x48, 8);
        break;
    case Small:
        ((RGE_Base_Game*)this)->setMapSize(0x60, 0x60, 8);
        break;
    case Medium:
        ((RGE_Base_Game*)this)->setMapSize(0x78, 0x78, 8);
        break;
    case Large:
        ((RGE_Base_Game*)this)->setMapSize(0x90, 0x90, 8);
        break;
    case Huge:
        ((RGE_Base_Game*)this)->setMapSize(0xC8, 0xC8, 8);
        break;
    case Humongous:
        ((RGE_Base_Game*)this)->setMapSize(0xFA, 0xFA, 8);
        break;
    }
}
