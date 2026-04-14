class RGE_Communications_Synchronize_sf {
public:
    void SetDialogOnFail(int val);
    void SetStopOnFail(int val);
};

class TCommunications_Handler_sf {
public:
    void StopIfSyncFail(int flag);
    char gap_00[0x14D8];
    RGE_Communications_Synchronize_sf* sync;
};

void TCommunications_Handler_sf::StopIfSyncFail(int flag) {
    this->sync->SetDialogOnFail(flag);
    this->sync->SetStopOnFail(flag);
}
