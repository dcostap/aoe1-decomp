class RGE_Lobby {
public:
    virtual ~RGE_Lobby();
    char gap_0[0x10];
    unsigned char field_14;
    int SendZoneHandshakeResponse();
};

int RGE_Lobby::SendZoneHandshakeResponse() { return this->field_14 != 0; }
