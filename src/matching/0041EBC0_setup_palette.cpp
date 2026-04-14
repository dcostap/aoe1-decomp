class TPanelSystem_pal {
public:
    int get_palette(char* data, int size);
};
extern TPanelSystem_pal DAT_0062e870;

class RGE_Base_Game_pal {
public:
    int setup_palette(void);
    char gap_00[0x0C];
    char* prog_data;
    char gap_10[0x0C];
    int prog_palette;
};

int RGE_Base_Game_pal::setup_palette(void) {
    int result = DAT_0062e870.get_palette(this->prog_data + 0x66E, 0xC544);
    this->prog_palette = result;
    return result != 0;
}
