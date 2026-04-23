extern "C" char* strcpy(char* dst, const char* src);

class RGE_Scenario {
public:
    char gap_0[0x1508];
    char Cine_PreGame[224];

    void Set_Cine_PreGame(char* text);
};

void RGE_Scenario::Set_Cine_PreGame(char* text) {
    if (text != 0) {
        strcpy(this->Cine_PreGame, text);
    } else {
        this->Cine_PreGame[0] = 0;
    }
}
