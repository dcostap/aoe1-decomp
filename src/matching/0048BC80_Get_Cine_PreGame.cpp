class RGE_Scenario {
public:
    virtual ~RGE_Scenario();
    char gap_0[0x1504];
    char field_1508[1];
    char* Get_Cine_PreGame();
};

char* RGE_Scenario::Get_Cine_PreGame() { return this->field_1508; }
