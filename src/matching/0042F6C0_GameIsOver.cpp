class RGE_Lobby {
public:
    virtual ~RGE_Lobby();
    char gap_0[0x10];
    unsigned char field_14;
    int GameIsOver();
};

int RGE_Lobby::GameIsOver() { return this->field_14 != 0; }
