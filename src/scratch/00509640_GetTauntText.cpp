class TTaunt {
public:
    char gap_00[0x14];
    char TBuff[32];

    char* GetTauntText(int id);
};

char* TTaunt::GetTauntText(int id) {
    char* dest = this->TBuff;
    const char* src = "Taunts you!";

    while ((*dest++ = *src++) != 0) {
    }
    return this->TBuff;
}
