class RGE_Player {
public:
    virtual long vf00();
    virtual long vf04();
    virtual long vf08();
    virtual long vf0C();
    virtual long vf10();
    virtual long vf14();
    virtual long vf18();
    virtual long vf1C();
    virtual long vf20();
    virtual long vf24(RGE_Player* other);
};

class RGE_Comm_Error {
public:
    void ShowReturn(long param_1, char* param_2);
};

class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    unsigned int Me;
    char gap_10E4[0x3FC];
    RGE_Comm_Error* Err;

    long DestroyMyPlayer();
};


long TCommunications_Handler::DestroyMyPlayer()
{
    unsigned long playerBits;
    RGE_Player* player;
    RGE_Player* other;
    long result;

    playerBits = *(unsigned long*)0x62C5EC;
    if (playerBits == 0)
        return 0;

    player = (RGE_Player*)playerBits;
    other = *(RGE_Player**)0x62CF04;
    if (other == 0)
        return 0;

    result = player->vf24(other);
    this->Err->ShowReturn(result, "Release Player");
    if (result == 0) {
        *(RGE_Player**)0x62CF04 = 0;
        this->Me = 0;
    }
    return result;
}
