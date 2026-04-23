extern "C" char* strcpy(char* dst, const char* src);

class RGE_Scenario {
public:
    char gap_0[0x16C8];
    char Cine_Loss[224];

    void Set_Cine_Loss(char* text);
};

void RGE_Scenario::Set_Cine_Loss(char* text) {
    if (text != 0) {
        strcpy(this->Cine_Loss, text);
    } else {
        this->Cine_Loss[0] = 0;
    }
}
