// VA: 004224E0 RGE_Base_Game::playerVersionString (231 B)
// PDB source: basegame.cpp
// PDB line span: 5200-5230

class RGE_Base_Game {
public:
    char gap_0[0x98A];
    unsigned char arr_[1];
    unsigned char playerVersion(int i);
    char* playerVersionString(int param);
};

char* RGE_Base_Game::playerVersionString(int param)
{
    unsigned char v = playerVersion(param);

    switch (v) {
        case 0:   return "";
        case 1:   return "1.0";
        case 2:   return "1.0a";
        case 3:   return "1.0b";
        case 4:   return "1.0c";
        case 5:   return "1.0d";
        case 6:   return "1.0e";
        case 7:   return "1.1";
        case 8:   return "1.1a";
        case 9:   return "1.1b";
        case 10:  return "1.1c";
        case 11:  return "1.2";
        case 12:  return "1.2a";
        case 13:  return "1.2b";
        case 14:  return "1.2c";
        case 15:  return "1.3";
        case 16:  return "1.3a";
        case 17:  return "1.3b";
        case 18:  return "1.3c";
        case 19:  return "1.4";
        case 20:  return "1.4a";
        case 21:  return "1.4b";
        case 22:  return "1.4c";
        default:  return "1.X";
    }
}
