class RGE_Base_Game_tim {
public:
    void setup_timings(void);
    char gap_00[0x538];
    int timing_538;
    char gap_53C[0x18];
    int timing_554;
    char gap_558[0x1C];
    int timing_574;
    char gap_578[0x1C];
    int timing_594;
    char gap_598[0x20];
    int timing_5B8;
    char gap_5BC[0xB8];
    int timing_674;
    char gap_678[0x5C];
    int timing_6D4;
};

void RGE_Base_Game_tim::setup_timings(void) {
    int val = 1;
    this->timing_554 = val;
    this->timing_574 = val;
    this->timing_594 = val;
    this->timing_674 = val;
    this->timing_6D4 = val;
    this->timing_538 = val;
    this->timing_5B8 = val;
}
